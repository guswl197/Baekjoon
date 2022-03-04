#include <iostream>
#include <algorithm>
using namespace std;
int a[305];
int d[305][3];

int main(void) {

	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1][1] = a[1];

	for (int i = 2; i <= n; i++) {

		d[i][2] = d[i - 1][1] + a[i];
		d[i][1] = max(d[i - 2][2], d[i - 2][1]) + a[i];
	}

	cout << max(d[n][1], d[n][2]) << '\n';
	return 0;
}