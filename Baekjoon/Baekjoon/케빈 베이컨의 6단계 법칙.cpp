#include <iostream>
#include <vector>
#include <queue>
#include <cstring>
#include <algorithm>

using namespace std;

int n, m; 
vector<vector<int>> v(101); 
vector<int> ans; 
int visit[101]; 
int Min,idx;

void bfs(int x) {
	queue<int> q;
	q.push(x); 
	
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

int sum() {
	int s = 0;
	for (int i = 1; i <= n; i++) {
		s += visit[i]; 
	}

	return s; 
}

int main() {
	cin >> n >> m; 
	Min = n * n+1;
	for (int i = 0; i < m; i++) {
		int x, y; 
		cin >> x >> y; 
		v[x].push_back(y);
		v[y].push_back(x); 
	}

	for (int i = 1; i <= n; i++) {
		memset(visit, 0, sizeof(visit)); 
		bfs(i);
		ans.push_back(sum());
	}

	for (int i = 0; i < ans.size(); i++) {
		if (Min > ans[i]) {
			Min = ans[i];
			idx = i + 1; 
		}
	}

	cout << idx << '\n';
	return 0; 
}
