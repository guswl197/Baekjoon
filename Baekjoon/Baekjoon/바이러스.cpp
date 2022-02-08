#include <iostream>
#include <vector>
using namespace std;

int n, cnt = 0;
int map[101][101];
int visit[101];

void dfs(int x) {
	visit[x] = 1;

	for (int i = 1; i <= n; i++) {
		if (!visit[i] && map[x][i] == 1) {
			cnt++;
			dfs(i);
		}
	}
}

int main(void) {

	int p;
	int u, v;
	cin >> n;
	cin >> p;

	for (int i = 0; i < p; i++) {
		cin >> u >> v;
		map[u][v] = map[v][u] = 1;
	}

	dfs(1);

	cout << cnt << '\n';
}
