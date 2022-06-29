#include <iostream>
#include <algorithm>

using namespace std;

int n, m, k;
int Max; 
int ans;
int arr[101][101]; 
int visit[101][101];
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1,0,0 }; 

int dfs(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue;
		}
		if (arr[nx][ny] == 1 && visit[nx][ny] == 0) {
			visit[nx][ny] = 1; 
			Max++;
			dfs(nx, ny); 
		}
	}

	return Max;
}

int main() {
	cin >> n >> m >> k; 
	for (int i = 0; i < k; i++) {
		int r, c;
		cin >> r >> c;
		arr[r-1][c-1] = 1; 
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && visit[i][j]==0) {
				Max = 0; 
				ans = max(ans, dfs(i, j)+1);
			}
		}
	}

	cout << ans << '\n';
	return 0; 

}