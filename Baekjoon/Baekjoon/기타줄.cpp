#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m; 
	int ans = 0; 
	cin >> n >> m;
	vector<int> six(m); 
	vector<int> one(m); 

	for (int i = 0; i < m; i++) {
		cin >> six[i]; 
		cin >> one[i]; 
	}

	sort(six.begin(), six.end());
	sort(one.begin(), one.end());

	if (six[0] < one[0] * 6) {
		ans += (n / 6)*six[0];

		if (six[0] < (n % 6)*one[0]) {
			ans += six[0];
		}
		else {
			ans += (n % 6)*one[0];
		}
	}
	else {
		ans += n * one[0]; 
	}

	cout << ans << '\n'; 
	return 0; 
}