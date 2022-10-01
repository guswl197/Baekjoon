#include <bits/stdc++.h>

using namespace std;

int n; 
vector<pair<int, int>> v; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	vector<int> ans(n + 1, 1);

	for (int i = 0; i < n; i++) {
		int x, y; 
		cin >> x >> y;
		v.push_back({ x,y }); 
	}

	for (int i = 0; i < n-1; i++) {
		for (int j = 1 + i; j < n; j++) {
			if (v[i].first > v[j].first && v[i].second > v[j].second) {
				ans[j]++;
			}
			else if (v[i].first < v[j].first && v[i].second < v[j].second) {
				ans[i]++; 
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << '\n'; 
	}

	return 0; 
}
