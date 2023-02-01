#include <bits/stdc++.h>

using namespace std;

int n; 
int card[500001]; 
int m; 
int t;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n;
	for (int i = 0; i < n; i++) {
		cin >> card[i];
	}
	
	cin >> m; 
	sort(card, card + n); 

	for (int i = 0; i < m; i++) {
		cin >> t;
		cout << upper_bound(card,card+n , t) - lower_bound(card, card + n , t) << ' '; 
	}

	return 0; 
}
