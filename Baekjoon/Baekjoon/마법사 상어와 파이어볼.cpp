#include <bits/stdc++.h>

using namespace std;

#define MAX 55

int N, M, K; 
int dx[] = {-1,-1,0,1,1,1,0,-1}; 
int dy[] = {0,1,1,1,0,-1,-1,-1}; 

struct FIREBALL {
	int row;
	int col;
	int mass;
	int speed;
	int direction;
};

vector<FIREBALL> fireball;
vector<FIREBALL> arr[MAX][MAX];

pair<int,int> point_move(int x,int y,int s,int d) {
	int nx = x, ny = y; 
	for (int i = 0; i < s; i++) {
		nx += dx[d]; 
		ny += dy[d]; 
		if (nx == 0) {
			nx = N; 
		}
		if (ny == 0) {
			ny = N; 
		}
		if (nx == N + 1) {
			nx = 1; 
		}
		if (ny == N + 1) {
			ny = 1; 
		}
	}

	return { nx , ny }; 
}

void move() {
	for (int i = 1; i <= N; i++) {
		for (int j = 1; j <= N; j++) {
			arr[i][j].clear(); 
		}
	}

	for (int i = 0; i < fireball.size(); i++) {
		int x = fireball[i].row; 
		int y = fireball[i].col; 
		int m = fireball[i].mass;
		int s = fireball[i].speed; 
		int d = fireball[i].direction; 

		pair<int,int> next = point_move(x, y, s, d);
		x = next.first, y = next.second;

		arr[x][y].push_back({ x, y,m,s,d }); 
		//fireball[i].row = x, fireball[i].col = y; 
	}
}

void combine(int x, int y) {
	int nm = 0, ns = 0;
	bool even = true, odd = true; 

	for (int i = 0; i < arr[x][y].size(); i++) {
		nm += arr[x][y][i].mass; 
		ns += arr[x][y][i].speed; 
	}
	nm /= 5, ns /= arr[x][y].size();

	if (nm == 0) {
		return; 
	}

	for (int i = 0; i < arr[x][y].size(); i++) {
		if (arr[x][y][i].direction % 2 == 0) { //짝수 
			odd = false;
		}
		else { // 홀수 
			even = false;
		}
	}

	arr[x][y].clear(); 

	// 4개의 파이어볼로 나눔
	if (even == false && odd == false) { // 1,3,5,7
		for (int i = 1; i <= 7; i += 2) {
			arr[x][y].push_back({x,y,nm,ns, i});
			fireball.push_back({ x,y,nm,ns, i });
		}

	}
	else { // 0,2,4,6
		for (int i = 0; i <= 6; i += 2) {
			arr[x][y].push_back({ x,y,nm,ns, i });
			fireball.push_back({ x,y,nm,ns, i });
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> N >> M >> K; 
	for (int i = 0; i < M; i++) {
		int r, c, m, s, d; 
		cin >> r >> c >> m >> s >> d; 
		fireball.push_back({ r,c,m,s,d }); 
		arr[r][c].push_back({ r,c,m,s,d }); 
	}

	while (K--) {
		// 1. 이동
		move(); 
		fireball.clear(); 

		// 2. 2개 이상 파이어볼
		for (int i = 1; i <= N; i++) {
			for (int j = 1; j <= N; j++) {
				if (arr[i][j].size() >= 2) {
					combine(i, j);
				}
				else if(arr[i][j].size() ==1) {
					fireball.push_back({ i,j, arr[i][j][0].mass, arr[i][j][0].speed, arr[i][j][0].direction}); 
				}
			}
		}
	}

	int ans = 0; 
	for (int i = 0; i < fireball.size(); i++) {
		//cout << fireball[i].mass << ' '; 
		ans += fireball[i].mass; 
	}

	cout<< ans << '\n';
	return 0; 
}
