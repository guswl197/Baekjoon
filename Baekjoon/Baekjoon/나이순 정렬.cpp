#include <bits/stdc++.h>

using namespace std;

vector<pair<int, string>> v; 
int n;

bool cmp(pair<int, string> a, pair<int ,string> b) {
	return a.first < b.first; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int age;
		string name;
		cin >> age >> name;
		v.push_back({ age, name }); 
	}

	stable_sort(v.begin(), v.end(), cmp); 

	for (auto x : v) {
		cout << x.first << ' ' << x.second << '\n'; 
	}

	return 0; 
}
