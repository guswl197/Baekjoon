#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int ans = 0; 
	cin >> n; 
	vector<int> v(n); 

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	sort(v.begin(), v.end(), greater<int>()); 

	for (int i = 0; i < n; i++) {
		ans = max(ans, (i + 1)*v[i]); 
	}

	cout << ans << '\n'; 
	return 0; 
}