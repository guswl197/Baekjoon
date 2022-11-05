#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int t; cin >> t;

	while (t--) {
		int n; cin >> n;
		vector<int> v(n); 
		map<int, int> num, four, score, five;
		for (int i = 0; i < n; i++) {
			cin >> v[i]; 
			num[v[i]]++; 
		}

		for (int i = 0, t=1; i < n; i++) {
			if (num[v[i]] != 6) {
				continue; 
			}
			if (++four[v[i]] < 5) {
				score[v[i]] += t; 
			}
			else if (four[v[i]] == 5) {
				five[v[i]] = t; 
			}
			t++; 
		}

		vector<tuple<int, int, int>> tp; 
		for (auto x : score) {
			tp.push_back({x.second, five[x.first], x.first});
		}
		sort(tp.begin(), tp.end()); 
		cout << get<2>(tp[0]) << '\n'; 
	}

	return 0; 
}
