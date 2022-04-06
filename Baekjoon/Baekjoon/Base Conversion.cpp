#include <iostream>
#include <string>
#include <math.h>
#include <algorithm>
#include <vector>

using namespace std;

int main() {
	int a, b, n; 
	cin >> a >> b;
	cin >> n;

	vector<int> v(n);
	long long num10 = 0; 
	vector<int> ans; 

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	reverse(v.begin(), v.end()); 
	for (int i = 0; i < v.size(); i++) {
		num10 += v[i] * pow(a, i); 
	}

	while (num10 != 0) {
		int tmp = num10 % b;
		ans.push_back(tmp); 
		num10 /= b; 
	}
	
	reverse(ans.begin(), ans.end()); 
	
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	cout << endl; 
	return 0; 
}