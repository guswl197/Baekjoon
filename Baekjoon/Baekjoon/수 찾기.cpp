#include <bits/stdc++.h>

using namespace std;

int n;
int arr[100001]; 
int m;
int t; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 

	cin >> m; 
	while (m--) {
		cin >> t; 
		cout << binary_search(arr, arr + n, t) << '\n';
	}

	return 0; 
}
