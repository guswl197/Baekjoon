#include <bits/stdc++.h>

using namespace std;

int n; 
long long m; 
long long arr[1000001]; 
long long ans;

bool solve(long long x) {
	long long len = 0; 
	for (int i = 0; i < n; i++) {
		if (arr[i] > x) {
			len += (arr[i] - x); 
		}
	}

	return len >= m; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 
	int st = 0, en = arr[n - 1]; 

	while (st <= en) {
		long long mid = (st + en) / 2;
		if (solve(mid)) {
			st = mid + 1;
			ans = max(ans, mid); 
		}
		else {
			en = mid - 1;
		}
	}

	cout << ans << '\n';
	return 0; 
}
