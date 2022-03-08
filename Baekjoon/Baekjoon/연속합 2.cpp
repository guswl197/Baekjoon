#include <iostream>
#include <algorithm>
using namespace std;
int a[100002];
int d1[100002];
int d2[100002];

int main(void) {
	int n;
	cin >> n;
	d1[0] = 0;
	d2[0] = 0;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	d2[n] = a[n];

	for (int i = 1; i <= n; i++) {
		d1[i] = a[i];
		if (d1[i] < d1[i - 1] + a[i]) {
			d1[i] = d1[i - 1] + a[i];
		}
	}

	for (int i = n - 1; i > 0; i--) {
		d2[i] = a[i];
		if (d2[i] < d2[i + 1] + a[i]) {
			d2[i] = d2[i + 1] + a[i];
		}
	}

	long ans1 = -1001;
	for (int i = 1; i < n; i++) {
		if (ans1 < d1[i - 1] + d2[i + 1]) {
			ans1 = d1[i - 1] + d2[i + 1];
		}
	}

	long ans2 = -1001;
	for (int i = 1; i <= n; i++) {
		if (ans2 < d1[i]) {
			ans2 = d1[i];
		}
	}

	cout << max(ans1, ans2) << '\n';
	return 0;
}