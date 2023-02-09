#include <bits/stdc++.h>

using namespace std;

int n, d, k, c; 
int arr[60002]; 
int sushi[3001]; 
int mx; 
bool flag = true; 
int ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> d >> k >> c;
	for (int i = 0; i < n; i++) {
		cin >> arr[i];
	}

	for (int i = 0; i < k - 1; i++) {
		arr[n + i] = arr[i];
	}

	sushi[c] = 1;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < k; j++) {
			if (arr[i + j] == c) {
				flag = false;
			}
			if (sushi[arr[i + j]] == 0) {
				ans++;
				sushi[arr[i + j]] = 1;
			}
		}

		if (flag) {
			mx = max(mx, ans + 1); 
		}
		else {
			mx = max(mx, ans); 
		}
		
		ans = 0;
		memset(sushi, 0, sizeof(sushi));
		flag = true;
	}

	cout << mx << '\n';
	return 0; 
}
