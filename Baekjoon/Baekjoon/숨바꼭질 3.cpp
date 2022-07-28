#include <bits/stdc++.h>

using namespace std;

int n, k; 
int visited[200002];

int bfs() {
	queue<int> q;
	q.push(n);
	visited[n] = 0;

	while (!q.empty()) {
		int cur = q.front(); 
		q.pop(); 

		if (cur == k) {
			return visited[k]; 
		}

		if (2 * cur < 200002 && visited[2 * cur] == -1) {
			visited[2 * cur] = visited[cur]; 
			q.push(2 * cur); 
		}

		for (int next : {cur - 1, cur + 1}) {
			if (next < 200002 && visited[next] == -1) {
				visited[next] = visited[cur] + 1;
				q.push(next); 
			}
		}
	}

	return 0; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k; 
	fill(visited, visited + 200002, -1); 
	
	cout<<bfs()<<'\n';
	
	return 0; 
}
