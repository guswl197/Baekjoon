#include <bits/stdc++.h>

using namespace std;

int n, k;
int visited[200002];

int temp[200002]; 
stack<int> ans; 

int bfs() {
	queue<int> q; 
	q.push(n); 

	while (!q.empty()) {
		int cur = q.front(); 

		if (cur == k) {
			if (n == 0 && n != k) {
				return visited[cur]; 
			}
			return visited[cur]+1; 
		}
		q.pop(); 

		for (int num : {cur*2, cur + 1, cur - 1}) {
			if (num>=0 && num <= 200002 && visited[num]== -1) {
				visited[num] = visited[cur] + 1;
				q.push(num);
				temp[num] = cur;
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

	for (int i = k; i!=n; i = temp[i]) {
		ans.push(i); 
	}

	ans.push(n); 

	while(!ans.empty()) {
		cout << ans.top() << ' ';
		ans.pop(); 
	}
	cout << '\n'; 
	
	return 0;
}
