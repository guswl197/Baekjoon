#include <iostream>
#include <queue>

using namespace std;

int n, m; 
int ans = 0; 
int arr[301][301]; 
int visit[301][301]; 
int dx[4] = { 1,-1,0,0 }; 
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q; 

void bfs() {
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second; 
		q.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if (0 > nx || nx >= n || 0 > ny || ny >= m) {
				continue;
			}
			if (arr[nx][ny] == 0 && arr[x][y]>0 && visit[nx][ny]==0) {
				arr[x][y]--; 
			}
		}
	}
}

int main(void) {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0) {
					q.push(make_pair(i, j));
					visit[i][j] = 1;
				}
			}
		}
		bfs();
		ans++;
		if (!q.empty()) {
			break; 
		}
		q = queue<pair<int, int>>();
		memset(visit, 0, sizeof(visit)); 
	}

	cout << ans << '\n'; 
	return 0; 
}