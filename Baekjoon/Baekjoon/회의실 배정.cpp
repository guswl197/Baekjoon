#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

bool compare(pair<int, int>& a, pair<int, int>& b) {
	if (a.second == b.second) {
		return a.first < b.first;
	}
	return a.second < b.second; 
}

int main(void) {
	int n; 
	int ans = 1; 
	cin >> n; 
	vector<pair<int, int>> v; 

	for (int i = 0; i < n; i++) {
		int a, b; 
		cin >> a >> b; 
		v.push_back(make_pair(a, b)); 
	}

	sort(v.begin(), v.end(), compare); 
	int end = v[0].second;
	for (int i = 1; i < n; i++) {
		if (end <= v[i].first) {
			ans++;
			end = v[i].second;
		}
	}

	cout << ans << '\n'; 

	return 0; 
}