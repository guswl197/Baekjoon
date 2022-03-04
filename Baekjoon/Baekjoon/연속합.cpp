#include <iostream>
#include <algorithm>

using namespace std;

int a[100001];
int d[100001];

int main(void) {
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}
	
	d[1] = a[1]; 
	for (int i = 1; i <= n; i++) {
		if (d[i - 1] > 0) {
			d[i] = a[i] + d[i - 1]; 
		}
		else {
			d[i] = a[i]; 
		}
	}

	int ans = d[1];
	for (int i = 2; i <= n; i++) {
		ans = max(ans, d[i]); 
	}

	cout << ans << '\n';
	return 0; 
}