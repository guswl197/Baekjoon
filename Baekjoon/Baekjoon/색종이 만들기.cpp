#include <bits/stdc++.h>

using namespace std;

int n; 
int arr[130][130]; 
int wcnt, bcnt; 

void recur(int si, int sj, int n) {
	if (n == 0) {
		return; 
	}

	int start = arr[si][sj];
	int flag = true; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (start != arr[si+i][sj+j]) {
				flag = false; 
			}
		}
	}

	if (flag == true) {
		if (start == 1) {
			bcnt++;
		}
		else {
			wcnt++; 
		}
	}
	else {
		int div = n / 2; 
		for (int i = 0; i < 2; i++) {
			for (int j = 0; j < 2; j++) {
				recur(si + i * div, sj+j*div, div);
			}
		}
	}

	return; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 
		}
	}

	recur(0,0, n);

	cout << wcnt << '\n' << bcnt << '\n'; 
	return 0; 
}
