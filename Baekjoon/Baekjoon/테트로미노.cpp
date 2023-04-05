#include <bits/stdc++.h>

using namespace std;

int n, m; 
int arr[505][505];
int visited[505][505]; 
int ans; 
int res; 
int dx[] = { 1,-1, 0,0 }; 
int dy[] = { 0,0,1,-1 }; 

void dfs(int x, int y, int cnt, int sum) {
	if (cnt == 4) {
		ans = max(ans, sum); 
		return; 
	}

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue; 
		}
		if (!visited[nx][ny]) {
			visited[nx][ny] = 1;
			dfs(nx, ny, cnt + 1, sum+arr[nx][ny]);
			visited[nx][ny] = 0;
		}
	}
	
	return;
}

int etc(int x, int y) {
	int ans = 0;
	// ㅏ
	if (1 <= x && x < n - 1 && y < m - 1) {
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x + 1][y] + arr[x][y + 1]);
	}

	// ㅓ 
	if (1<=x && x<n-1 && 1<=y) {
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x + 1][y]); 
	}

	// ㅗ 
	if (1 <= x && 1 <= y && y < m - 1) {
		ans = max(ans, arr[x][y] + arr[x - 1][y] + arr[x][y - 1] + arr[x][y + 1]); 
	}

	// ㅜ
	if (1 <= y && y < m - 1 && x < n - 1) {
		ans = max(ans, arr[x][y] + arr[x][y - 1] + arr[x + 1][y] + arr[x][y + 1]); 
	}
	return ans;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> arr[i][j]; 
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			visited[i][j] = 1, ans = 0; 
			dfs(i, j, 1, arr[i][j]); 
			visited[i][j] = 0;
			res = max(res, ans);
			res = max(res, etc(i,j)); 
		}
	}

	cout << res << '\n'; 
	return 0; 
}
