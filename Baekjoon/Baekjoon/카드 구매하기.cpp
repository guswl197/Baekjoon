#include <iostream>
#include <algorithm>

using namespace std;

int a[1001];
int d[1001]; 

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	d[1] = a[1]; 
	for (int i = 1; i <= n; i++) {
		d[i] = a[i]; 
		for (int j = 1; j < i; j++) {
			d[i] = max(d[j] + d[i - j], d[i]);
		}
	}

	cout << d[n] << '\n';
	return 0;
}