#include <bits/stdc++.h>

using namespace std;

int n, k;
int dist[200002];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> k;
	int MAX = 200000;
	fill(dist, dist + MAX, -1);
	queue<int> dq;
	dq.push(n);
	dist[n] = 0;

	while (!dq.empty()) {
		int cur = dq.front();
		dq.pop();

		if (cur == k) {
			break;
		}

		if (2 * cur < MAX && dist[2 * cur] == -1) {
			dist[2 * cur] = dist[cur];
			dq.push(2 * cur);
		}

		for (int nxt : {cur - 1, cur + 1}) {
			if (nxt < 0 || nxt >= MAX || dist[nxt] != -1) {
				continue;
			}
			dist[nxt] = dist[cur] + 1;
			dq.push(nxt);
		}
	}

	cout << dist[k];
	return 0;
}
