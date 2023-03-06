#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> adj[100001]; 
queue<int> q; 
int parent[100001]; 

void bfs(int x) {
	q.push(x); 

	while (!q.empty()) {
		int f = q.front(); 
		q.pop(); 

		for (int i = 0; i < adj[f].size(); i++) {
			if (parent[f] == adj[f][i]) {
				continue;
			}
			q.push(adj[f][i]); 
			parent[adj[f][i]] = f; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n-1; i++) {
		int a, b;
		cin >> a >> b;
		adj[a].push_back(b), adj[b].push_back(a); 
	}

	bfs(1);

	for (int i = 2; i <= n; i++) {
		cout << parent[i] << '\n'; 
	}

	return 0; 
}
