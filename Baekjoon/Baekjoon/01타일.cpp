#include <bits/stdc++.h>

using namespace std;

int d[1000001]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; 

	d[1] = 1; 
	d[2] = 2; 
	d[3] = 3; 
	d[4] = 5; 

	for (int i = 5; i <= n; i++) {
		d[i] = d[i - 1]% 15746 + d[i - 2]% 15746;
	}

	cout << d[n]% 15746 << '\n';
}
