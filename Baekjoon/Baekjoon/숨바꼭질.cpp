#include <iostream>
#include <queue>

using namespace std;

int t;
int n, k;
int arr[100001];
int visit[100001];

void bfs() {
	queue<int> q;
	q.push(n);
	visit[n] = 1;

	while (!q.empty()) {
		int top = q.front();
		q.pop();
		for (int i = 0; i < 3; i++) {
			int x = i == 0 ? top + 1 : i == 1 ? top - 1 : top * 2;

			if (x < 0 || x>100000) {
				continue;
			}

			if (visit[x] == 0) {
				visit[x] = 1;
				q.push(x);
				if (arr[x] > 0) {
					arr[x] = min(arr[top] + 1, arr[x]);
				}

				else {
					arr[x] = arr[top] + 1;
				}
			}
			if (x == k) {
				return;
			}
		}
	}
}

int main(void) {
	cin >> n >> k;

	bfs();

	cout << arr[k] << '\n';
	return 0;
}
? 2022 GitHub, Inc.
Terms