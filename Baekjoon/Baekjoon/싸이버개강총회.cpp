#include <bits/stdc++.h>
#include <unordered_set>

using namespace std;

string S, E, Q; 
string T, name; 
unordered_set<string> in; 
unordered_set<string> ans;

int change(string str) {
	int h, m; 
	h = stoi(str.substr(0, 2));
	m = stoi(str.substr(3,2));

	return h * 60 + m; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> S >> E >> Q; 
	int s= change(S);
	int e = change(E); 
	int q = change(Q);

	while (1) {
		if (cin.eof()) {
			break; 
		}
		
		cin >> T >> name;
		int t = change(T); 

		if (t <= s) {
			in.insert(name); 
		}
		else if (e <= t && t <= q && in.find(name) != in.end()) {
			ans.insert(name); 
		}

	}

	cout << ans.size() << '\n'; 
	return 0; 
}
