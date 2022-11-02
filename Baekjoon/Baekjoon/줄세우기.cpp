#include <bits/stdc++.h>

using namespace std;

int t, num, h, sum;
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		cin >> num;
		vector<int> v;
		ans = 0;
		for (int i = 0; i < 20; i++) {
			cin >> h;
			sum = 0;
			for (int j = 0; j < v.size(); j++) {
				if (v[j] < h) {
					sum++;
				}
				else {
					break;
				}
			}
			ans += v.size() - sum;
			v.push_back(h);
			sort(v.begin(), v.end());

		}

		cout << num << ' ' << ans << '\n';
	}

	return 0;
}
