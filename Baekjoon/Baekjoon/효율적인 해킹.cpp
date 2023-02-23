#include <bits/stdc++.h>

using namespace std;

int n, m; 
vector<vector<int>> v(10001);
int visited[10001]; 
int mx; 
vector<pair<int, int>> ans; 

void bfs(int x) {
	int cnt = 0; 
	queue<int> q; 
	q.push(x); 

	while (!q.empty()) {
		int mx = q.front(); 
		q.pop(); 

		for (int i = 0; i < v[mx].size(); i++) {
			if (!visited[v[mx][i]] && v[mx][i]!= x) {
				cnt++;
				q.push(v[mx][i]); 
				visited[v[mx][i]] = visited[mx] + 1; 
			}
		}
	}

	mx = max(mx, cnt); 
	ans.push_back({x, cnt});
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b; 
		v[b].push_back(a); 
	}

	for (int i = 1; i <= n; i++) {
		if (v[i].size() != 0) {
			memset(visited, 0, sizeof(visited));
			bfs(i); 
		}
	}

	sort(ans.begin(), ans.end()); 
	for (int i = 0; i < ans.size(); i++) {
		if (mx == ans[i].second) {
			cout << ans[i].first << ' '; 
		}
	}

	return 0; 
}
