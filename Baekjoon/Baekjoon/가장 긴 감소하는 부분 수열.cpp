#include <iostream>
#include <algorithm>

using namespace std;

int a[10001];
int d[10001];

int main(void) {
	int n;
	int result = 0; 
	cin >> n;
	for (int i = 1; i <= n; i++) {
		cin >> a[i];
	}

	for (int i = 1; i <= n; i++) {
		d[i] = 1;
		for (int j = 1; j < i; j++) {
			if (a[i] < a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1; 
			}
		}
	}

	for (int i = 1; i <= n; i++) {
		result = max(result, d[i]); 
	}

	cout << result << '\n';
	return 0; 
}