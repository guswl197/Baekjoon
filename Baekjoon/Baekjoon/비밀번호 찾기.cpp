#include <bits/stdc++.h>

using namespace std;

int n, m;
map<string, string> mp; 
string site, pwd; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for(int i=0; i<n ; i++){
		cin >> site >> pwd;
		mp[site] = pwd; 
	}

	for (int i = 0; i < m; i++) {
		string name;
		cin >> name;
		cout << mp[name] << '\n'; 
	}

	return 0; 
}
