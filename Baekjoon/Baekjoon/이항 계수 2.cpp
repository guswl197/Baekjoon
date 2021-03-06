#include <iostream>

using namespace std;

int d[1001][1001]; 

int main(void) {
	int n, k;
	cin >> n >> k; 

	d[1][1] = 1;
	d[1][0] = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= k; j++) {
			d[i][j] = d[i - 1][j - 1] % 10007 + d[i - 1][j] % 10007;
		}
	}

	cout << d[n][k] % 10007 << '\n';
	return 0; 
}