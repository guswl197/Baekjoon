#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

long long d[1000001]; 
vector<int> v; 
int main(void) {
	int t;
	int n;
	cin >> t;
	for (int i = 0; i < t; i++) {
		int a;
		cin >> a;
		v.push_back(a); 
	}

	int ma = *max_element(v.begin(), v.end());

	d[1] = 1, d[2] = 2, d[3] = 4;
	for (int i = 4; i <= ma; i++) {
		if (i - 3 >= 0) {
			d[i] += d[i - 3]% 1000000009;
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2] % 1000000009;
		}
		if (i - 1 >= 0) {
			d[i] += d[i - 1] % 1000000009;
		}
	}

	for (int i = 0; i < t; i++) {
		cout <<d[v[i]] % 1000000009<< '\n';
	}

	return 0; 
}
