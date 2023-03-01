#include <bits/stdc++.h>

using namespace std;

int n; 
priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int, int>>> pq; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x; 
		if (x != 0) {
			pq.push({ abs(x), x });
		}
		else if (pq.empty()) {
			cout << '0' << '\n'; 
		}
		else { //0 
			cout << pq.top().second << '\n'; 
			pq.pop(); 
		}
	}

	return 0; 
}
