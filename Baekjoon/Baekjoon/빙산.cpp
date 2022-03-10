#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int ans = 0;
int arr[301][301];
int bvisit[301][301];
int dvisit[301][301];
int dx[4] = { 1,-1,0,0 };
int dy[4] = { 0,0,1,-1 };
queue<pair<int, int>> q;

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
			if (!arr[nx][ny] && !bvisit[nx][ny] && arr[cur_x][cur_y]>0) {
				arr[cur_x][cur_y]--;
			}
		}
	}
}

void dfs(int x,int y) {
	dvisit[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i]; 

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (arr[nx][ny] && !dvisit[nx][ny]) {
			dfs(nx, ny); 
		}
	}
}

int goDfs() {
	memset(dvisit, 0, sizeof(dvisit));
	int cnt = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] && !dvisit[i][j]) {
				dfs(i, j);
				cnt++;
			}
		}
	}

	return cnt; 
}

int goBfs() {
	memset(bvisit, 0, sizeof(bvisit));
	ans++;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] > 0) {
				q.push(make_pair(i, j));
				bvisit[i][j] = 1;
			}
		}
	}

	if (q.empty()) {
		return -1;
	}

	bfs(); 
	return 0;
}

int main(void) {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; 
		}
	}

	//처음부터 두 덩어리 이상 
	if (goDfs() >= 2) {
		cout << 0 << '\n';
		return 0; 
	}

	while (1) {
		if (goBfs() == -1) {
			cout << 0 << '\n';
			return 0;
		}
		if (goDfs() >= 2) {
			cout << ans << '\n';
			return 0;
		}
	}

	return 0; 
}