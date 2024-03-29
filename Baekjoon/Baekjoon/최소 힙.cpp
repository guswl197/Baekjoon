#include <bits/stdc++.h>

using namespace std;

int n;
priority_queue<int, vector<int>, greater<int>> pq;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		if (x != 0) {
			pq.push(x); 
		}
		else if (pq.empty()) {
			cout << '0' << '\n'; 
		}
		else {
			cout << pq.top() << '\n'; 
			pq.pop(); 
		}
	}

	return 0; 
}
