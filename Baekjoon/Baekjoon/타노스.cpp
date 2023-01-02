#include <bits/stdc++.h>

using namespace std;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int zero=0, one=0; 
	string str; 
	string ans; 
	cin >> str; 
	
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') {
			zero++;
		}
		else {
			one++; 
		}
	}

	zero /= 2; 
	one /= 2; 

	int zn = 0, on = 0; 
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '0') {
			zn++;
			if (zn <= zero) {
				ans += '0'; 
			}
		}
		else{
			on++;
			if (on > one) {
				ans += '1';
			}
		}
	}

	cout << ans << '\n'; 
	return 0; 
}
