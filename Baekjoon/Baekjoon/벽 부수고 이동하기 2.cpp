#include <bits/stdc++.h>

using namespace std;

int n, m, k; 
char board[1001][1001];
int visited[1001][1001][11]; 
int x, y, broken; 
int dx[] = { 1,-1,0,0 }; 
int dy[] = { 0,0,1, -1 }; 

int bfs() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			for (int l = 0; l <= k; l++) {
				visited[i][j][l]= -1;
			}
		}
	}

	for (int i = 0; i <= k; i++) {
		visited[0][0][i] = 1; 
	}

	queue<tuple<int, int, int>> q; 
	q.push({ 0,0,0 });
	
	while (!q.empty()) {

		tie(x, y, broken) = q.front();

		if (x == n - 1 && y == m - 1) {
			return visited[x][y][broken];
		}

		q.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue; 
			}

			if (board[nx][ny] == '0' && visited[nx][ny][broken] == -1) {
				visited[nx][ny][broken] = visited[x][y][broken] + 1; 
				q.push({ nx,ny, broken});
			}
			
			if (board[nx][ny] == '1' && visited[nx][ny][broken+1] == -1 && broken < k) {
				visited[nx][ny][broken + 1] = visited[x][y][broken] + 1;
				q.push({ nx,ny, broken + 1 }); 
			}
		}
	}

	return -1; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m >> k; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; 
		}
	}

	cout << bfs();
	return 0; 
}
