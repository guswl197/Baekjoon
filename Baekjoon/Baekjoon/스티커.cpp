#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int t; 
	cin >> t;

	for (int i = 0; i < t; i++) {
		int n;
		cin >> n;
		int a[3][100001]; 
		int d[100001][4];
		for (int i = 1; i <= 2; i++) {
			for (int j = 1; j <= n; j++) {
				cin >> a[i][j]; 
			}
		}

		d[1][1] = a[1][1]; 
		d[1][2] = a[2][1];
		d[1][3] = 0; 
		for (int i = 2; i <= n; i++) {
			d[i][1] = max(d[i - 1][2] ,d[i-1][3])+ a[1][i]; 
			d[i][2] = max(d[i - 1][1] ,d[i - 1][3])+ a[2][i];
			d[i][3] = max({ d[i - 1][1], d[i - 1][2], d[i - 1][3] });
		}

		int ans = max({ d[n][1] , d[n][2],d[n][3] });
		cout << ans << '\n';
	}

	return 0; 
}