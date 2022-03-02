#include <iostream>

using namespace std;

int a[10001];
int d[10001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1] = 1;
	for (int i = 2; i <= n; i++) {
		if (a[i - 1] > a[i]) {
			d[i] = d[i - 1] + 1;
		}
		else {
			d[i] = d[i - 1]; 
		}
	}

	cout << d[n] << '\n';
	return 0; 
}