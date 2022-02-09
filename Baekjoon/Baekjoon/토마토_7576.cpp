#include <iostream>
#include  <vector>
#include <algorithm>
#include <queue>

using namespace std;

int ans = 0; 
int n, m; 
int arr[1001][1001]; 
int visit[1001][1001]; 
queue<pair<int, int>> q;
int dx[4] = { 0,0,1,-1 }; 
int dy[4] = { 1,-1,0,0 };

void bfs() {
	
	while(!q.empty()){
		int cur_x = q.front().first;
		int cur_y = q.front().second; 
		q.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = cur_x + dx[i];
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
				continue;
			}
			if (arr[nx][ny] == 0) {
				arr[nx][ny] = arr[cur_x][cur_y] + 1;
				q.push(make_pair(nx, ny)); 
			}
		}
	}
}

int main(void) {
	cin >> m >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; 
			if (arr[i][j] == 1) {
				q.push(make_pair(i, j)); 
			}
		}
	}

	bfs(); 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] ==0) {
				cout << -1 << '\n'; 
				return 0; 
			}

			if (ans < arr[i][j]) {
				ans = arr[i][j]; 
			}
		}
	}
	
	cout << ans-1 << '\n'; 

}