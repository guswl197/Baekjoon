#include <bits/stdc++.h>

using namespace std;

int n; 
vector<long long> v; 
map<long long, int > mp; 

bool cmp(pair<long long, int>& a, pair<long long, int>& b) {
	if (a.second > b.second) {
		return true; 
	}
	else if (a.second == b.second) {
		return a.first < b.first; 
	}
	
	return false; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		long long num;
		cin >> num; 
		v.push_back(num);
	}

	for (int i = 0; i < n; i++) {
		mp[v[i]]++; 
	}
	
	vector<pair<long long, int>> tmp(mp.begin(), mp.end()); 
	sort(tmp.begin(), tmp.end(), cmp);

	cout << tmp[0].first << '\n'; 
	return 0; 
}
