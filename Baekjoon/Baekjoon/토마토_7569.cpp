#include <iostream>
#include <queue>
#include <tuple>
#include <algorithm>

using namespace std;

int n, m, h; 
int ans = 0;
int arr[101][101][101]; 
int visit[101][101][101]; 
int dx[6] = { 1,-1,0,0,0,0 };
int dy[6] = { 0,0,1,-1,0,0 };
int dz[6] = { 0,0,0,0,1,-1 };
queue<tuple<int, int, int>> q; 

void bfs() {
	while (!q.empty()) {
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		int z = get<0>(q.front());
		q.pop(); 

		for (int i = 0; i < 6; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i];
			int nz = z + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) {
				continue;
			}
			if (arr[nz][nx][ny]==0 && !visit[nz][nx][ny]) {
				visit[nz][nx][ny] = 1; 
				arr[nz][nx][ny] = arr[z][x][y] + 1; 
				q.push(make_tuple(nz, nx, ny)); 
			}
		}
	}
}

int main(void) {
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n ; j++) {
			for (int k = 0; k < m; k++) {
				cin >> arr[i][j][k]; 
				if (arr[i][j][k] == 1) {
					q.push(make_tuple(i, j, k)); 
				}
			}
		}
	}

	bfs(); 

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (arr[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0; 
				}
				ans = max(ans, arr[i][j][k]);
			}
		}
	}

	cout << ans-1 << '\n';
	return 0; 
}