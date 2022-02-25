#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	long long n;
	long long need = 0;
	long long ans = 0;
	long long pmin = 1000000000;
	cin >> n;
	vector<long long> len(n - 1);
	vector<long long> p(n);

	for (long long i = 0; i < n - 1; i++) {
		cin >> len[i]; 
		need += len[i]; 
	}
	for (long long i = 0; i < n; i++) {
		cin >> p[i];
		if (pmin > p[i] && i!=n-1) {
			pmin = p[i]; 
		}
	}

	if (pmin != p[0]) {
		int i = 0, long long num = p[0]; 
		while (pmin != p[i]) {
			if (num > p[i]) {
				num = p[i];
			}
			ans += (long long)num * len[i];
			need -= len[i++];
		}
		ans += (long long)pmin * (need); 
	}
	else {
		ans += (long long)p[0] * need;
	}

	cout << ans << '\n'; 
	return 0; 
}