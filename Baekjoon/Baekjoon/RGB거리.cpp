#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[1001][4]; 

int main(void) {
	int n;
	cin >> n; 
	vector<vector<int>> v(n+1,vector<int>(4,0));

	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> v[i][j];
		}
	}

	d[1][1] = v[1][1], d[1][2] = v[1][2], d[1][3] = v[1][3];
	for (int i = 2; i <= n; i++) {
			d[i][1] = v[i][1] + min(d[i-1][3], d[i-1][2]);
			d[i][2] = v[i][2] + min(d[i - 1][3], d[i - 1][1]);
			d[i][3] = v[i][3] + min(d[i - 1][2], d[i - 1][1]);
		}

	cout << min(min(d[n][1], d[n][2]), d[n][3]) << '\n';

	return 0;
	
}