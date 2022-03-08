#include <iostream>
#include <algorithm>

using namespace std;

int a[1001]; 
int d[1001]; 

int main(void) {
	int n;
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		cin >> a[i]; 
	}

	d[1] = a[1]; 
	for (int i = 2; i <= n; i++) {
		d[i] = a[i]; // 길이가 자기자신포함 1일 수도 있기 때문에 
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + a[i]) {
				d[i] = d[j] + a[i]; 
			}
		}
	}

	int ans = 0; 
	for (int i = 1; i <= n; i++) {
		ans = max(ans, d[i]); 
	}

	cout << ans << '\n';
	return 0; 
}