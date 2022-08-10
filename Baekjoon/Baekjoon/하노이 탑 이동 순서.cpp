#include <iostream>

using namespace std;

int n;

void hanoi(int start, int end, int cnt) {
	if (cnt == 1) {
		cout << start << ' ' << end << '\n';
		return;
	}

	hanoi(start, 6 - start - end, cnt - 1);
	cout << start << ' ' << end << '\n';
	hanoi(6 - start - end, end, cnt - 1);
}

int main() {
	cin >> n;
	int ans;
	cout << (1 << n) - 1 << '\n';
	hanoi(1, 3, n);

	return 0;
}