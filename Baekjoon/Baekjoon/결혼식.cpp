#include <bits/stdc++.h>

using namespace std;

int n, m;
int arr[501][501]; 
int visited[501]; 
int ans; 

void dfs(int x) {

	for (int i = 1; i <= n; i++) {
		if (arr[x][i] == 1 && (!visited[i] || visited[i] > visited[x]+1)) {
			visited[i] = visited[x] + 1; 
			dfs(i); 
		}
	}

}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	cin >> m; 
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		arr[a][b] = arr[b][a] = 1; 
	}

	visited[1] = 1;
	dfs(1); 

	for (int i = 2; i <= n; i++) {
		if (2 <= visited[i] && visited[i] <= 3) {
			ans++;
		}
	}

	cout << ans << '\n';
	return 0; 
}
