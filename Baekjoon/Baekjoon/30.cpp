#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	string str;
	string ans; 
	vector<int> v;
	int sum = 0, ten = 0; 
	cin >> str; 

	for (int i = 0; i < str.size(); i++) {
		v.push_back(str[i]); 
	}

	for (int i = 0; i < v.size(); i++) {
		if (v[i] == '0') {
			ten = 1;
		}
		sum += v[i]; 
	}

	if (sum % 3 != 0 || ten == 0) {
		cout << -1 << '\n'; 
		return 0; 
	}

	sort(v.begin(), v.end(), greater<int>()); 

	for (int i = 0; i < v.size(); i++) {
		ans += v[i]; 
	}
	
	cout << ans << '\n';

	return 0; 
}