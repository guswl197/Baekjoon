#include <iostream>
#include <vector>
#include <map>

using namespace std;

long long a, b;
long long x;
map<long long, int> visit;

void dfs(long long x) {
	if (x >= b) {
		return;
	}

	if (visit[x * 2] == 0 || visit[x * 2] > visit[x] + 1) {
		visit[x * 2] = visit[x] + 1;
		dfs(x * 2);
	}
	if (visit[x * 10 + 1] == 0 || visit[x * 10 + 1] > visit[x] + 1) {
		visit[x * 10 + 1] = visit[x] + 1;
		dfs(x * 10 + 1);
	}
}
int main() {
	cin >> a >> b;
	x = a;

	dfs(a);

	if (visit[b] == 0) {
		cout << -1 << '\n';
	}
	else {
		cout << visit[b] + 1 << '\n';
	}

	return 0;
}
