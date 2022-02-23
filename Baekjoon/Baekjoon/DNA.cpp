#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

bool compare(string a, string b) {
	return a > b; 
}

int main(void) {
	int n, m;
	int num=0; 
	string ans; 
	cin >> n >> m; 
	vector<string> v(n); 

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	for (int i = 0; i < m; i++) {
		int a = 0, t = 0, g = 0, c = 0;
		int ma; 
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 'A') {
				a++;
			}
			else if (v[j][i] == 'T') {
				t++;
			}
			else if (v[j][i] == 'G') {
				g++;
			}
			else { //C
				c++; 
			}
		}
		ma = max(a, t);
		ma = max(ma, g);
		ma = max(ma, c); 

		if (ma == a) {
			ans += 'A'; 
			num += n - a; 
		}
		else if (ma == c) {
			ans += 'C';
			num += n - c;
		}
		else if (ma == g) {
			ans += 'G';
			num += n - g;
		}
		else {
			ans += 'T';
			num += n - t;
		}
	}

	cout << ans << '\n'<<num<<'\n'; 

	return 0; 
}