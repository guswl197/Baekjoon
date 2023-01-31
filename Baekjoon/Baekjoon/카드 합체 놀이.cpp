#include <bits/stdc++.h>

using namespace std;

int n, m;
vector<long long> v;
long long ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int num;
		cin >> num;
		v.push_back(num);
	}

	while (m--) {
		sort(v.begin(), v.end());
		long long first = v[0];
		long long second = v[1];
		long long sum = first + second;
		v[0] = sum, v[1] = sum;
	}

	for (int i = 0; i < n; i++) {
		ans += v[i];
	}

	cout << ans << '\n';

	return 0;
}
