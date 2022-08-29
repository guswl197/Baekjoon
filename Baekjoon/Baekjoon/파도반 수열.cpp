#include <bits/stdc++.h>

using namespace std;

long long d[105];
int t; 
int n; 
vector<int> v; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> n; 
		v.push_back(n); 
	}
	int mx = *max_element(v.begin(), v.end()); 

	d[1] = 1, d[2] = 1, d[3] = 1, d[4] = 2, d[5] = 2;

	for (int i = 6; i <= mx; i++) {
		d[i] = d[i - 1] + d[i - 5]; 
	}

	for (int i = 0; i < v.size(); i++) {
		cout << d[v[i]] << '\n'; 
	}

	return 0; 
}
