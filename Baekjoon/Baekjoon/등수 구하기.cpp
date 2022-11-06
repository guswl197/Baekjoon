#include <bits/stdc++.h>

using namespace std;
int n, score, p;
int ans=1;
vector<pair<int, int>> ranking;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> score >> p; 
	for (int i = 0; i < n; i++) {
		int x; cin >> x;
		ranking.push_back({x,0});
	}

	ranking.push_back({ score,-1 });

	sort(ranking.begin(), ranking.end(), greater<pair<int,int>>());
	
	int idx = 0; 
	for (int i = 0; i < ranking.size(); i++) {
		if (ranking[i].first > score && ranking[i].second ==0) {
			ans++; 
		}
		if (ranking[i].second == -1) {
			idx = i + 1; 
		}
	}

	if (idx > p) {
		ans = -1; 
	}
	
	cout << ans << '\n'; 
	return 0; 
}
