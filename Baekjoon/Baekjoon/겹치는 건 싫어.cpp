#include <bits/stdc++.h>

using namespace std;

int n, k; 
int arr[200001]; 
int check[100001]; 
int mx = 1; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> k; 
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}
	
	int en = 0;
	for (int st = 0; st < n; st++) {
		while (en < n && check[arr[en]] < k) {
			check[arr[en]] += 1; 
			en++;
		}
	
		mx = max(mx, en - st); 
		check[arr[st]]--; 

		if (en == n) {
			break;
		}
	}

	cout << mx << '\n';
	return 0; 
}
