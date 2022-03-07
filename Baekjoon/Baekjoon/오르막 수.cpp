#include <iostream>

using namespace std;

long long d[1001][11]; 

int main(void) {
	int n;
	cin >> n; 

	for (int i = 0; i <= 9; i++) {
		d[1][i] = 1; 
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			for (int k = 0; k <=j; k++) {
				d[i][j] += d[i - 1][k]%10007;
			}
		}
	}

	long long ans=0;
	for (int i = 0; i <= 9; i++) {
		ans += d[n][i] % 10007;
	}

	cout << ans % 10007 << '\n';
	return 0; 
}