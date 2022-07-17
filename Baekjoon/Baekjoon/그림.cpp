#include <iostream>
#include <algorithm>
#define MAX 505

using namespace std;

int n, m; 
int Max;
int ans;
int cnt; 
long long arr[MAX][MAX];
long long visit[MAX][MAX];
int dx[] = { 0,0,-1,1 }; 
int dy[] = { 1,-1, 0 ,0 }; 

int dfs(int x, int y) {
	visit[x][y] = 1;

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i];
		int ny = y + dy[i]; 

		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			continue; 
		}
		if (arr[nx][ny] == 1 && visit[nx][ny] == 0) {
			Max++;
			dfs(nx, ny); 
		}
	}

	return Max;
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			int a; 
			cin >> a;
			arr[i][j] = a;
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (arr[i][j] == 1 && visit[i][j] == 0) {
				Max = 0;
				cnt++;
				ans = max(ans, dfs(i, j));
			}
		}
	}

	if (cnt == 0) {
		ans = -1; 
	}
	cout << cnt << endl << ans+1 <<endl;
	return 0; 
}
