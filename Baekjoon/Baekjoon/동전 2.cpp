#include <iostream>
#include <algorithm>
using namespace std;
int coin[101];
int d[100001];

int main() {
	int n, k;
	cin >> n >> k;
	for (int i = 1; i <= n; i++) {
		cin >> coin[i];
	}

	fill(d, d + 100001, 100001); 

	d[0] = 0; 
	for (int i = 1; i <= n; i++) {
		for (int j = coin[i]; j <= k; j++) {
			d[j] = min(d[j], d[j - coin[i]] + 1);
		}
	}

	d[k] = d[k] == 100001 ? -1 : d[k]; 
	cout << d[k]<<'\n';
	return 0; 
}