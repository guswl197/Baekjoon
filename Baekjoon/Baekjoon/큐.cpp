#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	string c; 
	queue<int> q; 
	cin >> n; 

	while (n--) {
		cin >> c; 

		if (c == "push") {
			int num;
			cin >> num; 
			q.push(num); 
		}
		else if (c == "pop") {
			if (q.empty()) {
				cout << -1 << '\n'; 
			}
			else {
				cout << q.front() << '\n';
				q.pop(); 
			}
		}
		else if (c == "size") {
			cout << q.size() << '\n'; 
		}
		else if (c == "empty") {
			if (q.empty()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (c == "front") {
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.front() << '\n';
			}
		}
		else { //back
			if (q.empty()) {
				cout << -1 << '\n';
			}
			else {
				cout << q.back() << '\n';
			}
		}
	}
	return 0; 
}
