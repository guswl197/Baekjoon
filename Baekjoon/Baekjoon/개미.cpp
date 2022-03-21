#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int n1, n2;
	int t;
	cin >> n1 >> n2;

	string right, left;
	cin >> right;
	cin >> left;
	cin >> t;
	reverse(right.begin(), right.end());
	string ant = right + left;

	while (t--) {
		for (int i = 0; i < n1 + n2 - 1; i++) {
			if (right.find(ant[i]) != string::npos && left.find(ant[i + 1]) != string::npos) {
				swap(ant[i], ant[i + 1]);
				i++;
			}
		}
	}

	cout << ant << '\n';
	return 0;
}