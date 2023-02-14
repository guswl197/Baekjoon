#include <bits/stdc++.h>

using namespace std;

set<string> st; 
string str;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> str;

	int k = 0; 
	for (int i = 0; i < str.length(); i++) {
		for (int j = 1; j <= str.length(); j++) {
			st.insert(str.substr(i, j)); 
		}
	}

	cout << st.size() << '\n'; 
	return 0; 
}
