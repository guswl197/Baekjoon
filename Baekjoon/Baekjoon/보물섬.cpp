#include <iostream>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m;
int num = 0;
char arr[51][51]; 
int visit[51][51]; 
int dx[4] = { 1,-1,0,0 }; 
int dy[4] = { 0,0,1,-1 }; 

void bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push(make_pair(x, y));
	visit[x][y] = 1;

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
			if (arr[nx][ny] == 'L' && !visit[nx][ny]) {
				q.push(make_pair(nx, ny));
				visit[nx][ny] = visit[cur_x][cur_y] + 1;
			}
		}
	}
}

int main(void){
	cin >> n >> m; 
	vector<int> v; 

	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 'L') {
				memset(visit, 0, sizeof(visit)); 
				bfs(i, j);
				for (int i = 0; i < n; i++) {
					for (int j = 0; j < m; j++) {
						num = max(num, visit[i][j]);
					}
				}
			}

		}
	}

	cout << num-1 << '\n'; 
	return 0; 
}