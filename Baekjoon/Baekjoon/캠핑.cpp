#include <iostream>

using namespace std;

int main(void) {

	int i = 1; 
	while (1) {
		int l, p, v;
		cin >> l >> p >> v;
		if (l == 0 && p == 0 && v == 0) {
			return 0;
		}
		int n1 = (v / p)*l;
		int n2 = l < v%p ? l : v % p;
	
		cout << "Case " << i << ": " << n1 + n2 << '\n'; 
		i++; 
	}

	return 0; 
}