#include <bits/stdc++.h>

using namespace std;

int k, l;
string student; 
map<string, int > mp; 
int cnt; 

bool comp(pair<string, int> a, pair<string, int> b) {
	return a.second < b.second; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k >> l;
	for (int i = 0; i < l; i++) {
		cin >> student; 
		mp[student] = i; 
	}
	
	vector<pair<string, int>> v(mp.begin(), mp.end()); 
	sort(v.begin(), v.end(), comp);

	if (k > v.size()) {
		k = v.size(); 
	}

	for (int i = 0; i < k; i++) {
		cout << v[i].first << '\n'; 
	}

	return 0; 
}
