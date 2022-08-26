#include <bits/stdc++.h>

using namespace std;

int n, m; 
int arr[100001]; 
int d[100001];
vector<pair<int, int>>  v; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m;
	for (int i = 1; i <= n; i++) {
		cin >> arr[i]; 
	}

	for (int i = 0; i < m; i++) {
		int x, y; 
		cin >> x >> y; 
		v.push_back({ x,y }); 
	}

	d[0] = 0; 
	d[1] = arr[1]; 
	for (int i = 2; i <= n; i++) {
		d[i] = d[i - 1] + arr[i]; 
	}

	for (int i = 0; i < m; i++) {
		int x = v[i].first; 
		int y = v[i].second; 
		cout << d[y] - d[x-1] << '\n'; 
	}

	return 0; 
}
