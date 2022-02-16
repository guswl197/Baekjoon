#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n; 
	int k;
	int ans = 0; 
	cin >> n >> k;
	vector<int> v(n);

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	sort(v.begin(), v.end(), greater<int>()); 

	for (int i = 0; i < n; i++) {
		ans += k / v[i]; 
		k = k % v[i]; 
	}

	cout << ans << '\n'; 

	return 0; 
}