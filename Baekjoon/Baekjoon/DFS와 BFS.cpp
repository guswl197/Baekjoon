#include <iostream>
#include <vector>
#include <queue>
#include <stdlib.h>
#include <algorithm>
#include <cstring>

using namespace std;

int n, m, v; 
int arr[1001][1001]; 
int dvisit[10001]; 
int bvisit[10001];
vector<int> d; 
vector<int> b; 

void dfs(int x) {

	dvisit[x] = 1; 
	d.push_back(x); 

	for (int i = 1; i<=n; i++) {
		if (arr[x][i] == 1 && dvisit[i]==0) {
			dfs(i); 
		}
	}
}

void bfs(int x) {
	queue<int> q; 
	q.push(x); 
	b.push_back(x); 
	bvisit[x] = 1;

	while (!q.empty()) {
		int top = q.front(); 
		q.pop(); 

		for (int i = 1; i <= n; i++) {
			if (arr[top][i] == 1 && bvisit[i] == 0) {
				q.push(i);
				b.push_back(i);
				bvisit[i] = 1;
			}
		}

	}
}

int main(void) {
	cin >> n >> m >> v;
	memset(arr, 0, sizeof(arr)); 

	for (int i = 1; i <=m; i++) {
		int a, b; 
		cin >> a >> b; 
		arr[a][b] = arr[b][a] = 1; 
	}

	dfs(v); 
	bfs(v); 

	for (int i = 0; i < d.size()-1; i++) {
		cout << d[i] << ' ';
	}
	cout << d[d.size() - 1] << '\n'; 

	for (int i = 0; i < b.size() - 1; i++) {
		cout << b[i] << ' ';
	}
	cout << b[b.size() - 1] << '\n';

	return 0; 
}