#include <iostream>

using namespace std;

int main(void) {
	long long s;
	long long n;
	cin >> s;

	long long i = 1;
	while (1) {
		if (i*(i + 1) > 2*s) {
			n = i - 1;
			break;
		}
		i++; 
	}

	cout << n << '\n';
	return 0; 
}