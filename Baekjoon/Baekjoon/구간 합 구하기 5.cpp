#include <bits/stdc++.h>

using namespace std;

int n, m; 
int x, y, w, z; 
int arr[1025][1025];
int d[1025][1025];

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j]; 
			d[i][j] = d[i][j - 1] + d[i - 1][j] - d[i - 1][j- 1] + arr[i][j]; 
		}
	}

	for (int i = 0; i < m; i++) {
		cin >> w>> z >> x >> y;
		cout << d[x][y] - d[x][z - 1] - d[w- 1][y] + d[w - 1][z- 1] << '\n'; 
	}

	return 0; 
}
