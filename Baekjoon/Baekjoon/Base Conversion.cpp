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

	int digit[30]; 
	long long num10 = 0;
	vector<int> ans; 

	for (int i = 0; i < n; i++) {
		cin >> digit[i]; 
	}

	for (int i = n - 1; i >= 0; i--) {
		int temp = digit[i]; 
		num10 += temp * pow(a, n - 1 - i); 
	}

	while (num10 != 0) {
		int temp = num10 % b; 
		num10 /= b;
		ans.push_back(temp); 
	}

	reverse(ans.begin(), ans.end()); 
	for (int i = 0; i < ans.size(); i++) {
		cout << ans[i] << ' ';
	}

	cout << endl; 
	return 0;
}