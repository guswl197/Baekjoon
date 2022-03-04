#include <iostream>

using namespace std;

int d[101][10]; 

int main(void) {
	int n;
	long long ans = 0; 
	cin >> n; 

	for (int i = 1; i <= 9; i++) {
		d[1][i] = 1; 
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 0; j <= 9; j++) {
			if (j + 1 <= 9 ) {
				d[i][j] = d[i - 1][j + 1] % 1000000000;
			}
			if (j - 1 >= 0) {
				d[i][j]+= d[i - 1][j - 1] % 1000000000;
			}
		}
	}

	for (int i = 0; i <= 9; i++) {
		ans += d[n][i]; 
	}

	cout << ans % 1000000000 << '\n'; 
	return 0;
}