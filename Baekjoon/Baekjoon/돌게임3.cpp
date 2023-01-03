#include <iostream>

using namespace std;

int main() {
	int N;
	int table[1001] = { 0, 1, 0, 1, 1 };

	cin >> N;
	for (int i = 5; i <= N; i++) {
		if (table[i - 1] == 0 || table[i - 3] == 0 || table[i - 4] == 0) table[i] = 1;
		else table[i] = 0;
	}

	if (table[N]) cout << "SK";
	else cout << "CY";
}
