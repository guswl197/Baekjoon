#include <bits/stdc++.h>

using namespace std;

int n, m; 
int arr[10][10]; 
int tmp[10][10]; 
vector<pair<int, int>> zero; 
int visited[10][10]; 
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1, 0,0 }; 

void wall(pair<int,int> x, pair<int, int> y, pair<int, int> z) {
	memset(tmp, 0, sizeof(tmp)); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			tmp[i][j] = arr[i][j]; 
		}
	}

	tmp[x.first][x.second] = tmp[y.first][y.second] = tmp[z.first][z.second] = 1; 
}

void dfs(int x, int y) {
	visited[x][y] = 1;
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 
		if (nx <= 0 || nx > n || ny <= 0 || ny > m) {
			continue; 
		}
		if (!visited[nx][ny] && tmp[nx][ny] == 0) {
			tmp[nx][ny] = 2; 
			dfs(nx, ny); 
		}
	}
}

int solve() {
	memset(visited, 0, sizeof(visited)); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (!visited[i][j] && tmp[i][j] == 2) {
				dfs(i, j); 
			}
		}
	}

	int cnt = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			if (tmp[i][j] == 0) {
				cnt++;
			}
		}
	}

	return cnt;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= m; j++) {
			cin >> arr[i][j]; 
			if (arr[i][j] == 0) {
				zero.push_back({ i,j });
			}
		}
	}

	int len = zero.size(); 
	int mx = 0; 
	for (int i = 0; i < len - 2; i++) {
		for (int j = i + 1; j < len - 1; j++) {
			for (int k = j + 1; k < len; k++) {
				wall(zero[i], zero[j], zero[k]);
				mx = max(solve(), mx); 
			}
		}
	}

	cout << mx << '\n'; 
	return 0; 
}
