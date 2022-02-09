#include <iostream>
#include <string>
#include <queue>

using namespace std;

int n, m; 
int arr[101][101]; 
int visit[101][101]; 
int dx[4] = { 1,-1,0,0 }; 
int dy[4] = { 0,0,1,-1 }; 

void bfs(int x, int y) {
	queue<pair<int,int>> q; 
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
			if (visit[nx][ny] == 0 && arr[nx][ny] == 1) {
				q.push(make_pair(nx, ny));
				arr[nx][ny] = arr[cur_x][cur_y] + 1; 
				visit[nx][ny] = 1; 
			}
		}
	}

}

int main(void) {
	cin >> n >> m; 

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;

		for (int j = 0; j < m; j++) { 
			arr[i][j] = str[j]-'0'; 
		}
	}

	bfs(0, 0); 

	cout << arr[n - 1][m - 1] << '\n'; 
}