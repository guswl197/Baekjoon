#include <bits/stdc++.h>

using namespace std;

int n, m; 
int r, c, d; 
int arr[51][51]; 
int ans; 
int dx[4] = { 0,0,1,-1 };
int dy[4] = { 1,-1,0,0 }; 

pair<int,int> back(int x, int y, int d) {
	if (d == 0) {
		return { x + 1, y }; 
	}
	else if (d == 1) {
		return { x , y-1 };
	}
	else if (d == 2) {
		return { x - 1, y };
	}
	else {
		return { x , y+1 };
	}
}

pair<int, int> front(int x, int y, int d) {
	if (d == 0) {
		return { x - 1, y };
	}
	else if (d == 1) {
		return { x , y + 1 };
	}
	else if (d == 2) {
		return { x + 1, y };
	}
	else {
		return { x , y - 1 };
	}
}

int rotate(int x) {
	if (x == 0) {
		return 3; 
	}
	else if (x == 1) {
		return 0;
	}
	else if (x == 2) {
		return 1;
	}
	else {
		return 2; 
	}
}

void solve(int x, int y, int d) {
	if (arr[x][y] == 0) { // 1번
		arr[x][y] = 2; // 청소됨!
		ans++; 
	}

	int dirty = 0; 
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i];
		if (arr[nx][ny] == 0) {
			dirty++; 
		}
	}

	if (!dirty) { // 2번
		pair<int, int> b = back(x, y, d); 
		if (arr[b.first][b.second] != 1) {
			solve(b.first, b.second, d); 
		}
		else {
			return; 
		}
	}
	else{ // 3번
		d = rotate(d); 
		pair<int, int> f = front(x, y, d);
		if (arr[f.first][f.second] == 0) {
			x = f.first, y = f.second; 
		}
		solve(x, y, d);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	cin >> r >> c >> d; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; 
		}
	}

	solve(r,c,d); 
	cout << ans << '\n'; 
	return 0; 
}
