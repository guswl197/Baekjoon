#include <bits/stdc++.h>

using namespace std;

int n;
vector<string> v; 

bool cmp(string a , string b) {
	if (a.size() < b.size()) {
		return true;
	}
	else if (a.size() > b.size()) {
		return false; 
	}
	else { //같을 때
		return a < b; 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 

	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str); 
	}

	sort(v.begin(), v.end(), cmp);
	v.erase(unique(v.begin(), v.end()), v.end());

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n'; 
	}

	return 0; 
}
