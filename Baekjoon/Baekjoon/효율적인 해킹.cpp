#include <iostream>
#include <vector>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m; 
int cnt; 
vector<vector<int>> v(10001); 
queue<int> q; 
vector<int> ans(10001);
int visit[10001];
vector<int> idx; 
int Max;

int bfs(int x) {
	visit[x] = 1;
	q.push(x);

	while (!q.empty()) {
		int nx = q.front(); 
		q.pop(); 

		for (int i = 0; i < v[nx].size(); i++) {
			if (visit[v[nx][i]] == 0) {
				cnt++;
				visit[v[nx][i]] = 1;
				q.push(v[nx][i]);
			}
		}
	}

	return cnt;
}

int main() {
	cin >> n >> m; 

	for (int i = 0; i < m; i++) {
		int a, b;
		cin >> a >> b;
		v[b].push_back(a); 
	}

	for (int i = 1; i <= n; i++) {
		cnt = 0; 
		memset(visit, 0, sizeof(visit));
		ans[i]=bfs(i);
	}

	Max = *max_element(ans.begin(), ans.end()); 

	for (int i = 1; i <= n; i++) {
		if (Max == ans[i]) {
			idx.push_back(i); 
		}
	}

	sort(idx.begin(), idx.end()); 

	for (int i = 0; i < idx.size(); i++) {
		cout << idx[i] << ' ';
	}

	return 0; 
}
