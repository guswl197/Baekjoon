#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;


int main(void) {
	int t;
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		int min = 100001;
		cin >> n;
		int ans = 0;
		vector<pair<int, int>> v;

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			v.push_back(make_pair(a, b));
		}

		sort(v.begin(), v.end());

		for (int i = 0; i < n; i++) {
			if (min > v[i].second) {
				min = v[i].second;
				ans++;
			}
		}

		cout << ans << '\n';
	}

	return 0;
}