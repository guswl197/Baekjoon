#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int m, n,k;
int arr[51][51]; 
int visit[51][51]; 
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };

void bfs(int x, int y) {
	visit[x][y] = 1; 
	queue<pair<int, int>> q; 
	q.push(make_pair(x, y)); 

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (arr[nx][ny] && !visit[nx][ny]) {
				visit[nx][ny] = 1;
				q.push(make_pair(nx, ny));
			}
		}
	}
}

int main(void) {
	int t;
	cin >> t;
	for (int i = 0; i < t; i++) {
		memset(visit, 0, sizeof(visit)); 
		memset(arr, 0, sizeof(arr)); 
		cin >> m >> n >> k;

		for (int i = 0; i < k; i++) {
			int a, b;
			cin >> a >> b;
			arr[b][a] = 1;

		}

		int ans = 0; 
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] == 1 && visit[i][j] == 0) {
					bfs(i, j); 
					ans++; 
				}
			}
		}

		
		cout << ans << '\n'; 
	}

	return 0; 
}