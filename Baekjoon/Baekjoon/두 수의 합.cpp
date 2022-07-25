#include <bits/stdc++.h>

using namespace std;

int arr[2000001];
int ans;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n;
	cin >> n; 
	vector<int> v;
	for (int i = 0; i < n; i++) {
		int x;
		cin >> x;
		v.push_back(x); 
	}
	int x; 
	cin >> x; 

	for (int i = 0; i < v.size(); i++) {
		if (arr[v[i]] == 1) {
			ans++;
		}

		if (x - v[i] > 0) {
			arr[x - v[i]] = 1;
		}
	}

	cout << ans << '\n'; 
	return 0; 
}
