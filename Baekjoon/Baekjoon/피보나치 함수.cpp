#include <bits/stdc++.h>

using namespace std;

int t; 
vector<int> v; 
vector<pair<int, int>> d(45); 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t; 
	while (t--) {
		int n;
		cin >> n; 
		v.push_back(n); 
	}

	int mx = *max_element(v.begin(), v.end()); 
	d[0].first = 1;
	d[1].second = 1;

	for (int i = 2; i <= mx; i++) {
		d[i].first = d[i - 1].first + d[i - 2].first;
		d[i].second = d[i - 1].second + d[i - 2].second; 
	}

	for (int i = 0; i < v.size(); i++) {
		cout << d[v[i]].first << ' ' << d[v[i]].second << '\n'; 
	}

	return 0; 
}
