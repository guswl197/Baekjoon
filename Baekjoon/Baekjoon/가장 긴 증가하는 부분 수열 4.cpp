#include <iostream>
#include <algorithm>
#include <stack>

using namespace std;

int a[1001], d[1001];
stack<int> s;

int main()
{
	int n;
	cin >> n;

	for (int i = 1; i <= n; i++) {
		cin >> a[i];
		d[i] = 1;
	}

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
	}

	int len = 0;
	for (int i = 1; i <= n; i++) {
		len = max(len, d[i]);
	}

	cout << len << '\n';

	for (int i = n; i >= 1; i--) {
		if (d[i] == len) {
			s.push(a[i]); 
			len--; 
		}
	}
	
	while (!s.empty()) {
		cout <<s.top() << ' '; 
		s.pop(); 
	}

	cout << '\n';
	return 0;
}