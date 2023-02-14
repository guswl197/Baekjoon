#include <bits/stdc++.h>

using namespace std;

int t; 
int ans;
int n; 
string type, name;
map<string, vector<string>> mp; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;
	while (t--) {
		ans = 1;
		map<string, vector<string>> mp;
		cin >> n;
		for (int i = 0; i < n; i++) {
			cin >> name >> type;
			mp[type].push_back(name);
		}

		for (auto m : mp) {
			ans *= (m.second.size()+1);
		}

		cout << ans - 1 << '\n'; 
	}

	return 0; 
}
