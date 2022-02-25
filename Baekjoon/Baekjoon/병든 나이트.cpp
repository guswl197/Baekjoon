#include <iostream>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	cin >> n >> m; 

	if (n == 1) {
		cout << 1 << '\n'; 
	}
	else if (n == 2) {
		cout << min(4, (m + 1) / 2) << '\n';
	}
	else {
		if (m <= 4) {
			cout << m << '\n';
		}
		else if (m == 5) {
			cout << 4 << '\n';
		}
		else {
			cout << m-2 << '\n';
		}
	}

	return 0; 
}