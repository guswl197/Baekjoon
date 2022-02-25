#include <iostream>
#include <vector>
#include <string>
#include <algorithm>

using namespace std;

int main(void) {
	int n, m;
	int sum = 0;  
	cin >> n >> m;
	vector<string> v(n); 
	string ans;

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	for (int i = 0; i < m; i++) {
		int num = 0;
		int t = 0, a = 0, g = 0, c = 0;
		for (int j = 0; j < n; j++) {
			if (v[j][i] == 'T') {
				t++; 
			}
			else if (v[j][i] == 'A') {
				a++;
			}
			else if (v[j][i] == 'G') {
				g++;
			}
			else { //C 
				c++; 
			}
		}

		num = max(a, c); 
		num = max(num, g); 
		num = max(num, t); 

		if (num == a) {
			ans += 'A'; 
		}
		else if (num == c) {
			ans += 'C';
		}
		else if (num == g) {
			ans += 'G';
		}
		else { //t 
			ans += 'T';
		}
		sum += n - num; 

	}

	cout << ans << '\n' << sum << '\n'; 
	return 0; 
}