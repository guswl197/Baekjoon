#include <iostream>
#include <algorithm>

using namespace std;

int a[10001]; 
int d[10001][4]; 

int main(void){
	int n;
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}

	d[1][1] = a[1]; 
	for (int i = 2; i <= n; i++) {
		d[i][1] = max({ d[i - 2][1] , d[i - 2][2],d[i - 2][3] }) + a[i];
		d[i][2] = d[i - 1][1]+a[i];
		d[i][3] = max({d[i - 1][1], d[i - 1][2], d[i - 1][3]});
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max({ ans, d[i][1], d[i][2],d[i][3] });
	}
	cout << ans << '\n';
	return 0; 
}