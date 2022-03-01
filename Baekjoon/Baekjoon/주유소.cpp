#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n;
	long long lsum = 0; 
	int cheap = 0; 
	long long ans = 0;
	cin >> n;
	vector<int> len(n - 1); 
	vector<int> p(n); 
	for (int i = 0; i < n - 1; i++) {
		cin >> len[i]; 
		lsum += len[i]; 
	}
	for (int i = 0; i < n; i++) {
		cin >> p[i]; 
		if (i != n - 1) {
			cheap = min(cheap, p[i]);
		}
	}
	
	ans += (long long)len[0] * p[0];
	lsum -= len[0];
	int num = p[0]; 
	for (int i = 1; i < n-1; i++) {
		if (cheap == p[i]) {
			ans += (long long)lsum * p[i];
			break;
		}
		else if(num<p[i]){
			ans += (long long)len[i] * num;
		}
		else {
			ans += (long long)len[i] * p[i];
			num = p[i]; 
		}
		lsum -= len[i]; 
	}

	cout << ans << '\n';
	return 0; 
}