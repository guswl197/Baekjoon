#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; 
	vector<int> v; 
	vector<int> ans; 
	stack<int> s;

	for (int i = 0; i < n; i++) {
		int a; 
		cin >> a; 
		v.push_back(a); 
	}
	
	reverse(v.begin(), v.end());  

	int k = 1; 

	for(int i=0; i<v.size(); i++){

		while (!s.empty() && s.top() <= v[i]) {
			s.pop(); 
		}

		if (!s.empty()) {
			ans.push_back(s.top()); 
		}
		else {
			ans.push_back(-1); 
		}
		
		s.push(v[i]);
	}

	for (int i = ans.size() - 1; i >= 0; i--) {
		cout << ans[i] << ' '; 
	}

	cout << '\n'; 
	return 0; 
}
