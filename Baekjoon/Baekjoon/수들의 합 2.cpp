#include <bits/stdc++.h>

using namespace std;

int n, m; 
int arr[30001]; 
long long sum; 
int ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	int en = 0; 
	for (int st = 0; st < n; st++) {
		sum = 0; 
		en = st;
		while (en <= n && sum < m) {
			sum += arr[en]; 
			en++; 
		}
		if (en > n) {
			break;
		}
		if (sum == m) {
			ans++;
		}
	}

	cout << ans << '\n';
	return 0; 
}
