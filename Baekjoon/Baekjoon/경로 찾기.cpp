#include <bits/stdc++.h>

using namespace std;

int n;
int arr[101][101]; 
int ans[101][101]; 
int visited[101][101]; 

int bfs(int start, int end){
	queue<int> q;
	q.push(start);

	while (!q.empty()) {
		int x = q.front(); 
		q.pop(); 

		for (int i = 0; i < n; i++) {
			if (arr[x][i] && i == end) {
				return 1; 
			}

			if (arr[x][i] && !visited[x][i]) {
				visited[x][i] = 1; 
				q.push(i); 
			}
		}
	}

	return 0; 
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

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			memset(visited, 0, sizeof(visited)); 
			ans[i][j] = bfs(i, j);
		}
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cout << ans[i][j] << ' ';
		}
		cout << '\n';
	}

	return 0; 
}
