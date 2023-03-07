#include <bits/stdc++.h>

using namespace std;

int n; 
vector<int> adj[100001]; 
int p[100001]; 

void bfs(int x) {
	queue<int> q; 
	q.push(x); 

	while (!q.empty()) {
		int nx = q.front(); 
		q.pop(); 

		for (auto ch : adj[nx]) {
			if (p[nx] == ch) {
				continue; 
			}
			q.push(ch); 
			p[ch] = nx; 
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
		cout << p[i] << '\n'; 
	}

	return 0; 
}
