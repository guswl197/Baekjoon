#include <bits/stdc++.h>

using namespace std;

int n, m; 
vector<int> v[20001]; 
vector<int> visited(20001,-1); 
queue<int> q; 
int mx; 
int cnt; 

void bfs(int x) {
	q.push(x); 
	visited[x] = 0; 

	while (!q.empty()) {
		int nx = q.front(); 
		q.pop(); 

		for (int i = 0; i < v[nx].size(); i++) {
			if (visited[v[nx][i]] != -1) {
				continue; 
			}
			visited[v[nx][i]] = visited[nx] + 1; 
			mx = max(mx, visited[v[nx][i]]); 
			q.push(v[nx][i]); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b;
		v[a].push_back(b), v[b].push_back(a); 
	}

	bfs(1);

	int ans = n; 
	for (int i = 2; i <= n; i++) {
		if (mx == visited[i]) {
			ans = min(ans, i); 
			cnt++;
		}
	}

	cout << ans << ' ' << mx<< ' ' << cnt << '\n';
	return 0; 
}
