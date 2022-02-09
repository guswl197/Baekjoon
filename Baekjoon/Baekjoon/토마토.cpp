#include <iostream>
#include <stdlib.h>
#include <queue>

using namespace std;

int m, n; 
queue<pair<int, int>> q;
int map[1001][1001]; 

int dx[4] = { 1,-1,0,0 }; 
int dy[4] = { 0,0,1,-1 }; 

void bfs() {

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
			if (map[nx][ny] == 0) {
				map[nx][ny] = map[cur_x][cur_y]+1;
				q.push(make_pair(nx, ny));
			}
		} 
	}
}

int main(void) {
	cin >> m >> n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin>>map[i][j];
			if (map[i][j] == 1) {
				q.push(make_pair(i, j)); 
			}
		}
	}
	bfs(); 

	int max = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 0) {
				cout << -1 << '\n'; 
				return 0; 
			}

			if (max < map[i][j]) {
				max = map[i][j];
			}
		}
	}
	cout << max-1<<'\n'; 

	return 0; 
}