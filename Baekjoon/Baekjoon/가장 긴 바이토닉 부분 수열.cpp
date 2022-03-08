#include <iostream>
#include <algorithm>

using namespace std;

int a[1001]; 
int d1[1001]; 
int d2[1001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d1[1] = 1;
	for (int i = 2; i <= n; i++) {
		d1[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d1[i] < d1[j] + 1) {
				d1[i] = d1[j] + 1;
			}
		}
	}

	d2[n] = 1;
	for (int i = n - 1; i > 0; i--) {
		d2[i] = 1;
		for (int j = n; j > i; j--) {
			if (a[i] > a[j] && d2[i] < d2[j] + 1) {
				d2[i] = d2[j] + 1;
			}
		}
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d1[i]+d2[i]); 
	}

	cout << ans - 1 << '\n';
	return 0; 
}