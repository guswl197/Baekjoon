#include <bits/stdc++.h>

using namespace std;

string s; 
vector<string> v;

bool cmp(string a, string b) {
	return a < b; 
}
int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> s;

	for (int i = 0; i < s.size(); i++) {
		string str; 
		for (int j = i; j < s.size(); j++) {
			str += s[j]; 
		}
		v.push_back(str); 
	}

	sort(v.begin(), v.end(), cmp); 

	for (auto s : v) {
		cout << s << '\n'; 
	}

	return 0; 
}
