#include <bits/stdc++.h>

using namespace std;

long long arr[2200][2200]; 
int a, b, c; 

void recur(int x, int y, int cnt) {
	if (cnt == 0) {
		return;
	}

	int same = 0; 
	int start = arr[x][y]; 
	for (int i = 0; i < cnt; i++) {
		for (int j = 0; j < cnt; j++) {
			if (start == arr[i+x][j+y]) {
				same++;
			}
		}
	}

	if (same == cnt * cnt) {
		if (start == -1) {
			a++;
		}
		else if (start == 0) {
			b++;
		}
		else {
			c++;
		}

		return; 
	}

	int div = cnt / 3;
	for (int i = 0; i < 3; i++) {
		for (int j = 0; j < 3; j++) {
			recur(x + div * i, y + div * j, div);
		}
	}
}

int main(void) {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n;
	cin >> n; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 
		}
	}

	recur(0,0,n); 
	cout << a << '\n' << b << '\n' << c << '\n'; 
	return 0; 
}
