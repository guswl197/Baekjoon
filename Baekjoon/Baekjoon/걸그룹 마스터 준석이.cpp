#include <bits/stdc++.h>

using namespace std;

int n, m; 
map<string, string> mp; 
string group; 
int cnt;
string name; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> group; 
		cin >> cnt; 
		for (int j = 0; j < cnt; j++) {
			cin >> name;
			mp[name] = group;
		}
	}

	for (int i = 0; i < m; i++) {
		char t; 
		string str;
		
		cin >> str;
		cin >> t;
		if (t == '0') { // 이름 
			for (auto m : mp) {
				if (m.second == str) {
					cout << m.first << '\n';
				}
			}
		}
		else { // 그룹
			cout << mp[str] << '\n';

		}
	}

	return 0; 
}
