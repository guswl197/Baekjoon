#include <bits/stdc++.h>

using namespace std;

int anum, bnum; 
long long a[500001]; 
int b[500001];
vector<int> ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> anum >> bnum;
	for (int i = 0; i < anum; i++) {
		cin >> a[i]; 
	}
	for (int i = 0; i < bnum; i++) {
		cin >> b[i];
	}

	sort(b, b+ bnum);
	sort(a, a + anum); 

	for (int i = 0; i < anum; i++) {
		if (!binary_search(b, b + bnum, a[i])) {
			ans.push_back(a[i]); 
		}
	}

	if (!ans.size()) {
		cout << 0 << '\n'; 
	}
	else {
		cout << ans.size() << '\n'; 
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << " ";
		}
		cout << '\n'; 
	}

	return 0; 
}
