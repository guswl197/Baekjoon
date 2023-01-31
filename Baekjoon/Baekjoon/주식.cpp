#include <bits/stdc++.h>

using namespace std;

int t;
int n; 
int arr[1000001]; 
long long ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> t;
	while (t--) {
		cin >> n;
		memset(arr, 0, sizeof(arr));
		ans = 0; 
		for (int i = 0; i < n; i++) {
			cin >> arr[i]; 
		}

		int max = arr[n - 1];
		for (int i = n - 2; i >= 0; i--) {
			if (max >= arr[i]) {
				ans += max - arr[i]; 
			}
			else {
				max = arr[i]; 
			}
		}
		cout << ans << '\n'; 
	}

	return 0; 
}
