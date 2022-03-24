#include <iostream>
#include <vector>
#include <algorithm>

using namespace std; 

int d[1005][5]; 

int main() {
	int n; 
	cin >> n; 
	vector<vector<int >> v(n+2, vector<int>(5, 0)) ; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= 3; j++) {
			cin >> v[i][j]; 
		}
	}

	d[1][1] = v[1][1]; 
	d[1][2] = v[1][2];
	d[1][3] = v[1][3];
	for (int i = 1; i <= n; i++) {
		d[i][1] = min(d[i - 1][2], d[i - 1][3])+v[i][1];
		d[i][2]= min(d[i - 1][1], d[i - 1][3]) + v[i][2];
		d[i][3]= min(d[i - 1][1], d[i - 1][2]) + v[i][3];
	}
	
	cout << min({ d[n][1], d[n][2], d[n][3] })<<endl;

	return 0; 

}