#include <bits/stdc++.h>

using namespace std;

int n, m, x, y, k; 
int board[25][25]; 
int dice[5][4]; 
int dx[] = {0,0,0,-1,1}; 
int dy[] = {0,1,-1,0,0};

void rmove(int cnt) {
	for (int t = 0; t < cnt; t++) {
		int tmp = dice[1][2]; 
		for (int i = 1; i >= 0; i--) {
			dice[1][i+1] = dice[1][i];
		}
		dice[1][0] = dice[3][1]; 
		dice[3][1] = tmp; 
	}
}

void dmove(int cnt) {
	for (int t = 0; t < cnt; t++) {
		int tmp = dice[3][1];
		for (int i = 2; i >= 0; i--) {
			dice[i+1][1] = dice[i][1];
		}
		dice[0][1] = tmp;
	}
}

void slove(int dir) {
	
	if (x+dx[dir] < 0 || x + dx[dir] >= n || y+ dy[dir] < 0 || y+ dy[dir] >= m) {
		return; 
	}
	x += dx[dir];
	y += dy[dir];

	if (dir == 1) {
		rmove(1); 
	}
	else if (dir == 2) {
		rmove(3); 
	}
	else if (dir == 3) {
		dmove(3); 
	}
	else {
		dmove(1);
	}

	if (board[x][y] == 0) {
		board[x][y] = dice[3][1]; 
	}
	else {
		dice[3][1] = board[x][y]; 
		board[x][y] = 0;
	}

	cout << dice[1][1] << '\n';

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> x >> y >> k; 
	
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; 
		}
	}

	for (int i = 0; i < k; i++) {
		int x;
		cin >> x; 
		slove(x); 
	}

	return 0;
}
