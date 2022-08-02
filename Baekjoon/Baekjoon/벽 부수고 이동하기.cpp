#include <bits/stdc++.h>

using namespace std;

int n, m; 
int x, y, b; 
char arr[1001][1001]; 
queue<tuple<int, int, int>> q; 
int visited[1001][1001][2];
int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 }; 

int bfs(int si, int sj) {
	q.push({ si,sj,0 }); 
	visited[si][sj][0] = 1; 

	while (!q.empty()) {
		tie(x, y, b) = q.front(); 
		q.pop();

		if (x == n - 1 && y == m - 1) {
			return visited[x][y][b];
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
			int broken = b;

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue; 
			}

			if (!visited[nx][ny][broken] && arr[nx][ny]=='0') {
				visited[nx][ny][broken] = visited[x][y][broken] + 1; 
				q.push({ nx,ny, broken });
			}

			if (!broken && !visited[nx][ny][1] && arr[nx][ny]=='1') {
				visited[nx][ny][1] = visited[x][y][broken] + 1; 
				q.push({ nx,ny,1}); 
			}
		}

	}

	return -1;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; 
		}
	}

	cout<<bfs(0,0); 

	return 0;
}
