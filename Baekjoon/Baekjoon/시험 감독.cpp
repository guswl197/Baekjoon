#include <iostream>

using namespace std;

int a[1000001];

int main(void) {
	int n;
	int b, c;
	long long ans = 0; 
	cin >> n; 
	for (int i = 0; i < n; i++) {
		cin >> a[i]; 
	}
	cin >> b >> c;

	for (int i = 0; i < n; i++) {
		int num = a[i];
		num -= b;
		ans++; 
		if (num > 0) {
			ans += num / c; 
			if(num%c!=0){
				ans++; 
			}
		}
	}

	cout << ans << '\n';
	return 0; 
}