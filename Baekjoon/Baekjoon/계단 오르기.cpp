#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[305][3]; 

int main(void) {
	int n;
	cin >> n; 
	vector<int> v(n+1); 

	for (int i = 1; i <= n; i++) {
		cin >> v[i]; 
	}

	d[1][1] = v[1];

	for (int i = 2; i <= n; i++) {
		d[i][1] = max(d[i - 2][1], d[i - 2][2]) + v[i]; 
		d[i][2] = d[i - 1][1] + v[i]; 
	}

	cout << max(d[n][1],d[n][2]) << '\n'; 
	return 0; 
}