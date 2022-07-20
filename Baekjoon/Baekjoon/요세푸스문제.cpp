#include <bits/stdc++.h>

using namespace std;

int n, k; 
list<int> l; 
vector<int> v; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 

	cin >> n >> k; 

	for (int i = 1; i <= n; i++) {
		l.push_back(i); 
	}
	
	auto cur = l.begin();
	
	for (int i = 0; i < k - 1; i++) {
		cur++; 
	}

	while (1) {
		v.push_back(*cur);
		cur = l.erase(cur);

		if (l.empty()) {
			break; 
		}

		for (int i = 1; i < k; i++) {
			if (cur == l.end()) {
				cur = l.begin(); 
			}
			cur++;
			if (cur == l.end()) {
				cur = l.begin();
			}
		}
	}

	cout << '<'; 
	for (int i = 0; i < v.size()-1; i++) {
		cout << v[i] << ','<<' ';
	}
	cout << v[n-1] << '>';

	return 0; 
}
