#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[1005];

int main(void) {
	int n;
	cin >> n;
	vector<int> v(n + 1);
	for (int i = 1; i <= n; i++) {
		cin >> v[i]; 
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 1; 
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (d[i]< d[j]+1 && v[i] < v[j]) {
				d[i] = max(d[j] + 1, d[i]); 
			}
			
		}
	}
	
	int ans = 0;
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]); 
	}
	cout << ans << '\n';
	return 0; 
}