#include <bits/stdc++.h>

using namespace std;
int n; 
int arr[101]; 
int ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	for (int i = n - 2; i >= 0; i--) {
		if (arr[i + 1] <= arr[i]) {
			ans += arr[i] - arr[i + 1] + 1; 
			arr[i] = arr[i + 1] - 1; 
		}
	}

	cout << ans << '\n';
	return 0; 
}
