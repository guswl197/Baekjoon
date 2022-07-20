#include <bits/stdc++.h>

using namespace std;

int k; 
stack<int> st; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> k; 

	for (int i = 0; i < k; i++) {
		int x; 
		cin >> x; 
		if (x == 0) {
			st.pop(); 
		}
		else {
			st.push(x); 
		}
	}

	int sum = 0; 
	while (!st.empty()) {
		sum += st.top();
		st.pop(); 
	}

	cout << sum << '\n';
	return 0; 
}
