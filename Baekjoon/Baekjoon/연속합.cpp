#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int d[100005];

int main() {
	int n;
	cin >> n; 
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i]; 
	}

	for (int i = 1; i <= n; i++) {
		d[i] = v[i];
		if (d[i] < d[i - 1] + v[i]) {
			d[i] = d[i - 1] + v[i]; 
		}
	}

	int ans = d[1]; 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]); 
	}

	cout << ans << endl;
	return 0; 
}