#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101];
vector<int> dir; // 방향 패턴 
int mx_x, mx_y;
int ans; 

pair<int, int> curve(int y, int x, int d) {
	if (d == 0) {
		return {y , x+1 };
	}
	else if (d == 1) {
		return { y - 1  , x };
	}
	else if (d == 2) {
		return { y , x - 1 };
	}
	else {
		return { y + 1 ,x };
	}
}

void point(int y, int x) {
	pair<int, int> npoint = { y, x }; 
	//cout<<y<<' '<<x<<'\n';
	//cout << "dir: ";
	for (int i = 0; i < dir.size(); i++) {
		//cout << dir[i]<<" "; 
		npoint = curve(npoint.first, npoint.second, dir[i]);
		//cout << npoint.first << ' ' << npoint.second << '\n';
		arr[npoint.first][npoint.second] = 1; 
		mx_x = max(mx_x, npoint.second);
		mx_y = max(mx_y, npoint.first);
	}
	//cout << '\n';
}

void direction(int d, int g) {
	// 시작 방향 저장 (0세대)
	dir.push_back(d);

	// 1세대 이상 
	for (int i = 1; i <= g; i++) {
		int gen = dir.size(); 
		while (gen) {
			dir.push_back((dir[--gen] + 1)%4);
		}
	}
}

bool square(int y, int x) {
	if (arr[y][x] && arr[y][x + 1] && arr[y + 1][x] && arr[y + 1][x + 1]) {
		return true;
	}
	return false;
}

void solve(int y, int x, int d, int g) {
	// 방향 패턴 저장 
	direction(d, g);

	// 점 이동 
	point(y, x);	
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		vector<int>().swap(dir); 
		int x, y, d, g;
		cin >> x >> y >> d >> g;
		arr[y][x] = 1; 
		solve(y, x, d, g);
	}
	
	// 사각형 개수
	for (int i = 0; i <= mx_y; i++) {
		for (int j = 0; j <= mx_x; j++) {
			if (square(i, j)) {
				ans++;
			}
		}
	}
	
	cout << ans << '\n'; 
	return 0; 
}
