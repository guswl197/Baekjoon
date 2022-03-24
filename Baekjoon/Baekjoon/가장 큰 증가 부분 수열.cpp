#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[1005]; 

int main() {
	int n;
	cin >> n;
	vector<int> v(n+1); 
	for (int i = 1; i <= n; i++) {
		cin >> v[i]; 
	}

	d[1] = v[1]; 
	for (int i = 2; i <= n; i++) {
		d[i] = v[i];
		for (int j = 1; j < i; j++) {
			if (v[i] > v[j] && d[i] < d[j] + v[i]) {
				d[i] = d[j] + v[i]; 
			}
		}

	}

	int ans = 0; 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]); 
	}

	cout << ans << endl;
	return 0; 
}