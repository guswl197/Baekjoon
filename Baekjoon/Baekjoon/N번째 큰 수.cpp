#include <bits/stdc++.h>

using namespace std;

int n; 
priority_queue<int, vector<int>, greater<int>> pq; 
int x; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n*n; i++) {
		cin >> x;
		if (pq.size() == n) {
			if (pq.top() < x) {
				pq.pop(); 
				pq.push(x); 
			}
		}
		else {
			pq.push(x); 
		}
	}

	cout << pq.top() << '\n'; 
	return 0; 
}
