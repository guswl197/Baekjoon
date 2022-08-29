#include <bits/stdc++.h>

using namespace std;

int n; 
vector<int> v; 
int d[1001]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x); 
	}

	d[0] = v[0]; 
	for (int i = 1; i < n; i++) {
		int mx = 0; 
		for (int j = 0; j < i; j++) {
			if (v[i] > v[j]) {
				mx = max(mx, d[j]); 
			}
		}
		d[i] = max(v[i], mx + v[i]); 
	}

	int ans = 0; 
	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]); 
	}

	cout << ans << '\n'; 
	return 0;
}
