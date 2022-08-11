#include <bits/stdc++.h>

using namespace std;

int n; 
char arr[65][65]; 
string ans; 

bool check(int x, int y, int n){

char first = arr[x][y];

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			if (first != arr[x+i][y+j]) {
				return false; 
			}
		}
	}
	return true; 
}

void recur(int x, int y, int n) {
	if (n == 1) {
		ans += arr[x][y]; 
		return; 
	}

	if (check(x,y,n)) {
		ans += arr[x][y];
		return; 
	} 
	else {
		ans += "("; 
		recur(x, y, n / 2); 
		recur(x, y + n / 2, n / 2); 
		recur(x + n / 2, y, n / 2); 
		recur(x + n / 2, y + n / 2, n / 2); 
		ans += ")"; 
	}

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

	recur(0,0,n); 

	cout << ans << '\n';
	return 0; 
}
