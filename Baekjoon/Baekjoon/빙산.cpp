#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m; 
int ans = 0; 
int num = 0; 
int arr[301][301]; 
int visit[301][301]; 
int dx[4] = { 1,-1,0,0 }; 
int dy[4] = { 0,0,1,-1};
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

void check(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i];

		if (0 > nx || nx >= n || 0 > ny || ny >= m) {
			continue;
		}

		if (arr[nx][ny] && visit[nx][ny] == 0) {
			check(nx, ny); 
		}
	}
}

int block() {
	num = 0;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (!visit[i][j] && arr[i][j]) {
				check(i, j);
				num++;
			}
		}
	}

	return num; 
}

int main(void) {
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j];
		}
	}

	if (block() >= 2) {
		cout << 0 << '\n';
		return 0; 
	}

	memset(visit, 0, sizeof(visit));

	while (1) {
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (arr[i][j] > 0) {
					q.push(make_pair(i, j));
					visit[i][j] = 1;
				}
			}
		}

		if (q.empty()) {
			cout << 0 << '\n';
			return 0; 
		}

		bfs(); 
		ans++; 
		q = queue<pair<int, int>>();
		memset(visit, 0, sizeof(visit)); 

		if (block() >= 2) {
			cout << ans << '\n';
			return 0;
		}
	}

	return 0; 
}