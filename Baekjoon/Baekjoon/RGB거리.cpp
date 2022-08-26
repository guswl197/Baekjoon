#include <bits/stdc++.h>

using namespace std;

int n;
int arr[1001][5]; 
int d[1001][5]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> arr[i][1] >> arr[i][2] >> arr[i][3]; 
	}

	d[1][1] = arr[1][1];
	d[1][2] = arr[1][2];
	d[1][3] = arr[1][3];

	for (int i = 2; i <= n; i++) {
		d[i][1] = min(d[i - 1][2], d[i - 1][3]) + arr[i][1];
		d[i][2] = min(d[i - 1][1], d[i - 1][3]) + arr[i][2];
		d[i][3] = min(d[i - 1][1], d[i - 1][2]) + arr[i][3];
	}
 
	cout << min({ d[n][1], d[n][2], d[n][3] }) << '\n'; 
	return 0; 

}
