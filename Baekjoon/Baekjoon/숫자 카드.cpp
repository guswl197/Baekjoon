#include <bits/stdc++.h>

using namespace std;

int n;
int card[500001]; 
int m, t; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i]; 
	}
	cin >> m;

	sort(card, card + n); 

	while (m--) {
		cin >> t;
		cout << binary_search(card, card + n, t) << ' '; 
	}

	return 0; 
}
