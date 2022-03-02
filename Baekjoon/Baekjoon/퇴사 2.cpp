#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[1500000];
vector<pair<int, int>> v;

int main(void) {
	int n;
	cin >> n;
	v.push_back(make_pair(0, 0)); 
	for (int i = 1; i <= n; i++) {
		int a, b; 
		cin >> a >> b;
		v.push_back(make_pair(a, b)); 
	}

	for (int i = 1; i <= n; i++) {
		d[i + v[i].first] = max(d[i + v[i].first], d[i] + v[i].second); 
		d[i + 1] = max(d[i + 1], d[i]); 
	}

	cout << d[n+1] << '\n';
	return 0; 
}