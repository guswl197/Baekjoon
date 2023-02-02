#include <bits/stdc++.h>

using namespace std;

int n;
int arr[10001];
long long m; 
long long mx; 
long long ans; 
int mid;
int re;

long long solve(int x) {
	long long mx = 0; 

	for (int i = 0; i < n; i++) {
		if (arr[i] > x) {
			mx += x;
		}
		else {
			mx += arr[i];
		}
	}

	return mx; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}
	cin >> m;

	sort(arr, arr + n);
	int st = 0, en = arr[n - 1]; 

	while (st <= en) {
		mid = (st + en) / 2; 
		ans = solve(mid); 

		if (m< ans) {
			en = mid - 1; 
		}
		else {
			st = mid + 1; 
			re = max(re, mid); 
		}
	}

	cout << re << '\n';
	return 0; 
}
