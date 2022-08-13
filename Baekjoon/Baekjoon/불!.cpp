#include <bits/stdc++.h>

using namespace std;

int t; 
int w, h; 
char board[1001][1001]; 
int fvisited[1001][1001]; 
int svisited[1001][1001]; 
queue<pair<int, int>> fq;
queue<pair<int, int>> sq;
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1, 0,0 }; 

void queueClear() {
	while (!sq.empty()) {
		sq.pop(); 
	}
	while (!fq.empty()) {
		fq.pop();
	}
}

void fbfs() {

	while (!fq.empty()) {
		int x = fq.front().first;
		int y = fq.front().second;  
		fq.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
			if (nx < 0 || nx>= h || ny < 0 || ny >= w) {
				continue;
			}
			if (!fvisited[nx][ny] && board[nx][ny] != '#') {
				fvisited[nx][ny] = fvisited[x][y] + 1;
				fq.push({ nx ,ny }); 
			}
		}
	}
}

int sbfs() {

	while (!sq.empty()) {
		int x = sq.front().first;
		int y = sq.front().second; 
		sq.pop(); 

		if (x == 0 || y == 0 || x == h - 1 || y == w - 1) {
			return svisited[x][y];
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				continue; 
			}
			if (svisited[nx][ny] || board[nx][ny] != '.') {
				continue;
			}
			if (fvisited[nx][ny] ==0 || (fvisited[nx][ny] != 0 && svisited[x][y] + 1 < fvisited[nx][ny])) {
				svisited[nx][ny] = svisited[x][y] + 1;
				sq.push({ nx,ny }); 
			}
		}
	}

	return -1; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> w >> h;
		memset(board, 0, sizeof(board)); 
		memset(fvisited, 0, sizeof(fvisited)); 
		memset(svisited, 0, sizeof(svisited));
		queueClear(); 

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> board[i][j];
				if (board[i][j] == '*') {
					fvisited[i][j] = 1; 
					fq.push({ i,j });
				}
				else if (board[i][j] == '@') {
					svisited[i][j] = 1;
					sq.push({ i,j });
				}
			}
		}
			fbfs(); 
		
			int ans = sbfs();
			if (ans == -1) {
				cout << "IMPOSSIBLE" << '\n';
			}
			else {
				cout << ans << '\n'; 
			}
	}
}
