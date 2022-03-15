#include <iostream>

using namespace std;

int n, m;
int arr[10];
int visit[10];

void dfs(int num, int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = num; i <= n; i++) {
			if (!visit[i]) {
				visit[i] = 1;
				arr[cnt] = i;
				dfs(i + 1, cnt + 1);
				visit[i] = 0;
			}
		}
	}

}

int main(void) {
	cin >> n >> m;
	dfs(1, 0);

	return 0;
}