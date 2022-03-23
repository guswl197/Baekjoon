#include <iostream>
#include <vector>
#include<algorithm>

using namespace std;

long long d[100001][4];

int main() {
	int t;
	cin >> t;
	vector<int> v; 
	for (int i = 0; i < t; i++) {
		int a; 
		cin >> a;
		v.push_back(a); 
	}

	int Max = *max_element(v.begin(), v.end()); 

	d[1][1] = 1; 
	d[2][2] = 1; 
	d[3][1] = 1;
	d[3][2] = 1;
	d[3][3] = 1;
	for (int i = 4; i <= Max; i++) {
		d[i][1] =d[i - 1][2] % 1000000009 +d[i - 1][3] % 1000000009;
		d[i][2] = d[i - 2][1] % 1000000009 + d[i - 2][3] % 1000000009;
		d[i][3] = d[i - 3][2] % 1000000009 +d[i - 3][1] % 1000000009;
	}

	for (int i = 0; i < t; i++) {
		long long ans = d[v[i]][1] + d[v[i]][2] + d[v[i]][3];
		cout << ans % 1000000009 << '\n';
	}
	
	return 0; 
}