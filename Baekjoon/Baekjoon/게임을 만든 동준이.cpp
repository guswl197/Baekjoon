#include <bits/stdc++.h>

using namespace std;

int n;
int a[101]; 
int ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}

	int prev = a[n - 1]; 
	for (int i = n - 2; i >= 0; i--) {
		if (a[i] >= prev) {
			ans += a[i] - prev + 1;
			a[i] = prev - 1;
		}
		prev = a[i]; 
	}
	
	cout << ans << '\n';
	return 0; 

}
