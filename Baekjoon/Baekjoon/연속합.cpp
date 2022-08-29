#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v; 
int d[100001]; 

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
		d[i] = max(v[i], d[i - 1] + v[i]); 
	}

	int ans = -1001; 
	for (int i = 0; i < n; i++) {
		ans = max(ans, d[i]); 
	}
	cout << ans << '\n'; 
}
