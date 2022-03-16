#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, l;
	int wait = 0; 
	int ans = 0; 
	cin >> n >> l; 
	vector<vector<int>> v(n,vector<int>(3,0));
	for (int i = 0; i < n; i++) {
		cin >> v[i][0]; //D 
		cin >> v[i][1]; //R
		cin >> v[i][2]; //G
	}

	for (int i = 0; i < n; i++) {
		int num = v[i][1]-(v[i][0] % (v[i][1] + v[i][2])); 
		if (num > 0) {
			wait += num; 
			for (int j = i + 1; j < n; j++) {
				v[j][0] += num; 
			}
		}
	}


	cout << wait+l  << '\n';
	return 0;
}