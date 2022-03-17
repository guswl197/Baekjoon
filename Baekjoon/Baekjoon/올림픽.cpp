#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, target;
	int number; 
	int ans = 1;
	cin >> n>>target;

	vector<vector<int>> v(n+1, vector<int>(4,0)); 

	for (int i = 1; i <= n; i++) {
		cin >> number;
		for (int j = 0; j < 3; j++) {
			cin >> v[number][j];
		}
	}

	for (int i = 1; i <= n; i++) {
		if (target != i) {
			if (v[target][0] < v[i][0]) {
				ans++;
			}
			else if (v[target][0] == v[i][0]) {
				if (v[target][1] < v[i][1]) {
					ans++;
				}
				else if (v[target][1] == v[i][1]) {
					if (v[target][2] < v[i][2]) {
						ans++;
					}

				}
			}
		}
	}
	
	cout << ans << '\n'; 
}