#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

int main(void) {
	int n; 
	int ans = 0; 
	cin >> n;
	vector<int> v(n);
	for (int i = 0; i < n; i++) {
		cin >> v[i];
	}

	sort(v.begin(), v.end(),greater<int>());

	for (int i = 0; i < n; i++) {
		ans = max(ans, v[i] + i); 
	}

	cout << ans + 2 << '\n'; 
	return 0; 
}