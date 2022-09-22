#include <bits/stdc++.h>

using namespace std;

int n, m; 
vector<int> v; 
int mn= 2000000001;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		v.push_back(x); 
	}
	sort(v.begin(), v.end()); 
	int idx=0; 

	for (int i = 0; i < n; i++) {
		for (int j = idx; j < n; j++) {
			if (abs(v[i] - v[j]) >= m) {
				mn = min(mn, abs(v[i] - v[j]));
				idx = j; 
				break; 
			}
		}
	}

	cout << mn << '\n'; 
	return 0; 
}
