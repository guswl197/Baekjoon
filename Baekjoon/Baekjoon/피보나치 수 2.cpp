#include <iostream>

using namespace std;

long long d[100]; 

int main(void) {
	int n;
	cin >> n; 

	d[0] = 0;
	d[1] = 1;

	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 2] + d[i - 1]; 
	}

	cout << d[n] << '\n';
	return 0; 
}