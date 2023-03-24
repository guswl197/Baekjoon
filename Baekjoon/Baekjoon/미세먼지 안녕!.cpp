
#include <bits/stdc++.h>

using namespace std;

int r, c, t; 
int arr[55][55]; 
int dx[] = { 0,0 ,-1, 1 }; 
int dy[] = { 1,-1, 0,0 }; 
int visited[55][55]; 
int add[55][55]; 
vector<pair<int, int>> air; 

void spread(int x, int y) {
	visited[x][y] = 1; 
	int cnt = 0; 

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 
		if (nx <= 0 || nx > r || ny <= 0 || ny > c) {
			continue; 
		}
		
		// 공기청정기가 없고
		if (arr[nx][ny] != -1) {
			int s = arr[x][y] / 5; 
			add[nx][ny] += s; 
			cnt++; 
		}
	}

	int num = arr[x][y] - ((arr[x][y] / 5)* cnt); 
	arr[x][y] = num; 

}

void umove(pair<int, int> start, pair<int, int> end) {
	int sx = start.first; 
	int sy = start.second;
	int ex = end.first;
	int ey = end.second; 
	
	//1. 왼쪽 -o
	for (int i = ex-1; i > sx; i--) {
		arr[i][sy] = arr[i-1][sy]; 
	}

	//2. 위 - o 
	for (int i = sy; i < ey; i++) {
		arr[sx][i] = arr[sx][i + 1];
	}

	//3. 오른쪽
	for (int i = sx; i < ex; i++) {
		arr[i][ey] = arr[i + 1][ey]; 
	}

	//4. 아래
	for (int i = ey; i > sy; i--) {
		if (arr[ex][i - 1] == -1) {
			arr[ex][i] = 0;
		}
		else {
			arr[ex][i] = arr[ex][i - 1];
		}
	}
}

void dmove(pair<int, int> start, pair<int, int> end) {
	int sx = start.first;
	int sy = start.second;
	int ex = end.first;
	int ey = end.second;

	//1. 왼쪽
	for (int i = sx + 1; i < ex; i++) {
		arr[i][sy] = arr[i + 1][sy];
	}

	//2. 아래
	for (int i = sy; i < ey; i++) {
		arr[ex][i] = arr[ex][i + 1];
	}

	//2. 오른쪽
	for (int i = ex; i > sx; i--) {
		arr[i][ey] = arr[i - 1][ey];
	}

	//4. 위
	for (int i = ey; i > sy; i--) {
		if (arr[sx][i - 1] == -1) {
			arr[sx][i] = 0;
		}
		else {
			arr[sx][i] = arr[sx][i - 1];
		}
	}

}

void solve() {
	// 1번
	memset(visited, 0, sizeof(visited)); 
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j]) {
				spread(i, j); 
			}
		}
	}

	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			arr[i][j] += add[i][j]; 
		}
	}

	// 2번
		int x = air[0].first; 
		int y = air[0].second; 
		umove({ 1,1 }, { x,c });
		dmove({ x + 1, 1 }, {r,c });
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> r >> c >> t; 
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			cin >> arr[i][j]; 
			if (arr[i][j] == -1) {
				air.push_back({ i,j }); 
			}
		}
	}

	while (t--) {
		memset(add, 0, sizeof(add));
		solve();  
	}
	
	int ans = 0; 
	// 미세먼지 양
	for (int i = 1; i <= r; i++) {
		for (int j = 1; j <= c; j++) {
			if (arr[i][j] != -1) {
				ans += arr[i][j];
			}
		}
	}

	cout << ans << '\n'; 
	return 0; 
}
