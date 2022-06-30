#include <iostream>

using namespace std;

long long a, b, c;
long long ans;

long long mul(long long a, long long b, long long c) {
	if (b == 1) {
		return a % c;
	}

	long long val = mul(a, b / 2, c);
	val = val * val %c;

	//b- even
	if (b % 2 == 0) {
		return val;
	}
	//b- odd
	return val * a%c;
}
int main() {
	cin >> a >> b >> c;
	ans = mul(a, b, c);

	cout << ans << '\n';
	return 0;
}