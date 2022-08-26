#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v(305); 
int d[305]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin>>v[i]; 
	}

	d[1] = v[1]; 
	d[2] = v[1] + v[2]; 
	d[3] = max(v[1], v[2]) + v[3]; 

	for (int i = 4; i <= n; i++) {
		d[i] = max(d[i - 3]+v[i-1], d[i - 2]) + v[i]; 
	}

	cout << d[n] << '\n'; 
	return 0; 
}
