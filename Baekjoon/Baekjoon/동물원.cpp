#include <iostream>

long long d[100001][4]; 

using namespace std;

int main(void) {
	int n;
	cin >> n;
	d[1][1] = 1, d[1][2] = 1, d[1][3] = 1;
	for (int i = 2; i <= n; i++) {
		d[i][1]= d[i - 1][2]% 9901 + d[i - 1][3] % 9901;
		d[i][2]= d[i - 1][1] % 9901 +  d[i - 1][3] % 9901;
		d[i][3]= d[i - 1][2] % 9901 +  d[i - 1][1] % 9901 + d[i - 1][3] % 9901;
	}

	long long ans = d[n][1] + d[n][2] + d[n][3];
	cout << ans%9901 << '\n';
	return 0; 
}