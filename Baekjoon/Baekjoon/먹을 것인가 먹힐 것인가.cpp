#include <bits/stdc++.h>

using namespace std;

int t; 
int n, m;
vector<int> a;
vector<int> b; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> n >> m;
		int cnt = 0; 
		vector<int> a;
		vector<int> b;

		for (int i = 0; i < n; i++) {
			int x; 
			cin >> x; 
			a.push_back(x); 
		}
		for (int i = 0; i < m; i++) {
			int x;
			cin >> x;
			b.push_back(x);
		}

		sort(a.begin(), a.end()); 
		sort(b.begin(), b.end()); 

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < m; j++) {
				if (a[i] > b[j]) {
					cnt++; 
				}
				else {
					break;
				}
			}
		}
		cout << cnt << '\n'; 
	}

	return 0; 
}
