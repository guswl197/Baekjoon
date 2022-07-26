#include <bits/stdc++.h>

using namespace std;

int n;
char arr[101][101]; 
int visited[101][101]; 
queue<pair<int, int>> q;
int dx[] = { 1,-1,0,0 };
int dy[] = { 0,0, 1,-1 }; 
vector<int> ans(2); 

void bfs(int i, int j) {
	q.push({ i,j });
	visited[i][j] = 1;
	
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}

			if (visited[nx][ny] == 0 && arr[nx][ny] == arr[x][y]) {
				visited[nx][ny] = 1;
				q.push({ nx,ny });
			}
		}
	}
}

int run() {
	int cnt = 0; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (visited[i][j] == 0) {
				bfs(i, j);
				cnt++;
			}
		}
	}

	return cnt; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 
		}
	}

	cout << run() << ' '; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 'R') {
				arr[i][j] = 'G'; 
			}
		}
	}

	memset(visited, 0, sizeof(visited));
	cout << run() << ' ';

	return 0; 
}
