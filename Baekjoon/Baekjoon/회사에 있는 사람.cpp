#include <bits/stdc++.h>

using namespace std;

int n; 
string name, state;
set<string> st; 
vector<string> ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> name >> state;
		if (state == "enter") {
			st.insert(name); 
		}
		else {
			st.erase(name); 
		}
	}

	for (auto name : st) {
		ans.push_back(name); 
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << '\n';
	}

	return 0; 
}
