#include <bits/stdc++.h>

using namespace std;

int n, cnt; 
int arr[100001]; 
bool visited[100001]; 
bool done[100001]; //더 이상 방문하지 않을 것이라고 확신하는 배열

void dfs(int node) {
	visited[node] = true; 
	int next = arr[node]; 
	
	//사이클
	if (!visited[next]) {
		dfs(next); 
	}
	else if (!done[next]) {
		for (int i = next; i != node; i = arr[i]) {
			cnt++;
		}
		cnt++;
	}

	done[node] = true; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 

	int t; 
	cin >> t;
	while (t--) {
		memset(visited, false, sizeof(visited)); 
		memset(done, false, sizeof(done));

		cin >> n; 

		for (int i = 1; i <= n; i++) {
			cin >> arr[i]; 
		}

		cnt = 0; 
		for (int j = 1; j <= n; j++) {
			if (!visited[j]) {
				dfs(j); 
			}
		}
		cout << n - cnt << '\n'; 
	}

	return 0; 
}
