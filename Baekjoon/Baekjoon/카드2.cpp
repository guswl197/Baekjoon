#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; 
	queue<int> q; 
	
	for (int i = 1; i <= n; i++) {
		q.push(i); 
	}

	while (q.size()>1) {
		q.pop(); 
		if (q.size() == 1) {
			break; 
		}
		int x = q.front();
		q.pop(); 
		q.push(x); 
	}

	cout << q.front() << '\n'; 
	return 0;
}
