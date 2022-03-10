#include <iostream>
#include<queue>
#include <tuple>

using namespace std;

int n, m, h;
int map[101][101][101];
queue<tuple<int, int, int>> q; 
int dx[6] = { 1,-1,0,0,0,0 }; 
int dy[6] = { 0,0,1,-1,0,0 }; 
int dz[6] = { 0,0,0,0,1,-1 }; 

void bfs() {
	while (!q.empty()) {
		int cur_z = get<0>(q.front()); 
		int cur_x= get<1>(q.front());
		int cur_y= get<2>(q.front());
		q.pop(); 

		for (int i = 0; i < 6; i++) {
			int nx = cur_x + dx[i]; 
			int ny = cur_y + dy[i];
			int nz = cur_z + dz[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m || nz < 0 || nz >= h) {
				continue;
			}
			if (map[nz][nx][ny] == 0) {
				map[nz][nx][ny] = map[cur_z][cur_x][cur_y] + 1;
				q.push(make_tuple(nz, nx, ny)); 
			}
		}
	}
}

int main(void) {
	int ans = 0;
	cin >> m >> n >> h;

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin >> map[i][j][k];
				if (map[i][j][k] == 1) {
					q.push(make_tuple(i, j, k));
				}
			}
		}
	}

	bfs();

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				if (map[i][j][k] == 0) {
					cout << -1 << '\n';
					return 0;
				}
				ans = max(ans, map[i][j][k]);
			}
		}
	}

	cout << ans - 1 << '\n';
	return 0;
}
