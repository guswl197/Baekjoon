#include <bits/stdc++.h>

using namespace std;

int m, n; 
long long arr[1000001]; 
int ans; 

bool solve(int x) {

	if (x == 0) {
		return true; 
	}

	long long cnt = 0; 
	for (int i = 0; i < n; i++) {
		cnt += arr[i] / x; 
	}

	return cnt >= m; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> m >> n; // 조카 수, 과자 수
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n);
	int st = 0, en = arr[n - 1]; 
	while (st <= en) {
		int mid = (st + en) / 2; 
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
