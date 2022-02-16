#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	int a = 0;
	int ans = 0; 
	cin >> n; 
	vector<int> v(n); 

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	sort(v.begin(), v.end()); 

	for (int i = 0; i < n; i++) {
		a += v[i]; 
		ans += a; 
	}

	cout << ans << '\n'; 

	return 0; 
}