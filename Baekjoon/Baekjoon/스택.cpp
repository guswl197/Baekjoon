#include <bits/stdc++.h>

using namespace std;

int n; 
stack<int> st; 
string cmd; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 

	while (n--) {
		cin >> cmd;
		int num; 

		if (cmd == "push") {
			cin >> num; 
			st.push(num); 
		}
		else if (cmd == "pop") {
			if (st.empty()) {
				cout << -1 << '\n'; 
			}
			else {
				cout << st.top()<<'\n';
				st.pop(); 
			}

		}
		else if (cmd == "size") {
			cout << st.size() << '\n'; 
		}
		else if (cmd == "empty") {
			if (st.empty()) {
				cout << 1 << '\n'; 
			}
			else {
				cout << 0 << '\n'; 
			}
		}
		else { //top
			if (st.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << st.top() << '\n';
			}
		}
	}

	return 0; 
}
