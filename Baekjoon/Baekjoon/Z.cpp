#include <bits/stdc++.h>

using namespace std;

int n, r, c;
int ans;

int z(int n, int r, int c) {
	if (n == 0) {
		return 0; 
	}
	int div = 1 << (n - 1); 
	if (r < div && c < div) {
		return z(n - 1, r, c); 
	}
	if (r < div && c >= div) {
		return div*div + z(n - 1, r, c-div);
	}
	if (r >= div && c < div) {
		return div*div*2+ z(n - 1, r-div, c);
	}
	if (r >= div && c >= div) {
		return div*div*3+ z(n - 1, r-div, c-div);
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> r >> c;
	cout << z(n, r, c) << '\n';
	return 0;
}

