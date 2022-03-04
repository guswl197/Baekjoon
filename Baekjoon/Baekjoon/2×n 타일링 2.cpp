#include <iostream>

using namespace std;

int d[1001]; 

int main(void) {
	int n;
	cin >> n; 
	d[0] = 0;
	d[1] = 1;
	d[2] = 3;
	for (int i = 3; i <= n; i++) {
		d[i] = d[i - 1] % 10007 + (d[i - 2] % 10007) * 2;
	}

	cout << d[n]% 10007 << '\n';
	return 0; 
}