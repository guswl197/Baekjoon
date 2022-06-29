#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>

using namespace std;

int n, m, k, x; 
vector<vector<int>> v(300001);
queue<int> q; 
int visit[300001];
vector<int> ans;

void bfs(int x) {
	q.push(x);
	visit[x] = 1; 
	while (!q.empty()) {
		int nx = q.front(); 
		q.pop(); 

		for (int i = 0; i < v[nx].size(); i++) {
			if (visit[v[nx][i]] == 0) {
				visit[v[nx][i]] = visit[nx] + 1;
				q.push(v[nx][i]);
			}
		}
	}
}

int main() {
	cin >> n >> m >> k >> x;

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[a].push_back(b);
	}

	bfs(x);

	for (int i = 1; i <= n; i++) {
		if (visit[i]-1 == k) {
			ans.push_back(i); 
		}
	}

	if (ans.empty()) {
		cout << -1 << '\n'; 
	}
	else {
		sort(ans.begin(), ans.end());
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << '\n';
		}
	}

	return 0; 
}