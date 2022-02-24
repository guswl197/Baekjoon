#include <iostream>

using namespace std;

int main(void) {
	int n, m, k;
	cin >> n >> m >> k; 

	int ans = 0;
	int total = n + m - k;

	while (n > 1 && m > 0 && total > 2) {
		n -= 2;
		m -= 1;
		total -= 3;
		ans++;
	}

	cout << ans<<'\n';
	
	return 0;
}