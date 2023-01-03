#include <bits/stdc++.h>

using namespace std;

long d[2000002]; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n; 
	cin >> n; 

	d[0] = 0;
	d[1] = 1;

	for (int i =2; i <=abs(n); i++) {
		d[i] = d[i - 1] % 1000000000 + d[i - 2] % 1000000000;
	}


	if (n == 0) {
		cout << 0 << '\n'; 
	}
	else if (n > -2) {
		cout << 1 << '\n'; 
	}
	else if(abs(n)%2 ==0){
		cout << -1 << '\n'; 
	}
	else {
		cout << 1 << "\n"; 
	}

	cout << abs(d[abs(n)])% 1000000000 << '\n';
}
