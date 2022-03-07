#include <iostream>
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

	int lis = 1;

	for (int i = 2; i <= n; i++) {
		for (int j = 1; j < i; j++) {
			if (a[i] > a[j] && d[i] < d[j] + 1) {
				d[i] = d[j] + 1;
			}
		}
		if (lis < d[i]) {
			lis = d[i];
		}
	}

	cout << lis << '\n';

	for (int i = n; i >= 1; i--) {
		if (d[i] == lis) {
			s.push(a[i]);
			lis -= 1;
		}
	}

	while (!s.empty()) {
		cout << s.top() << ' ';
		s.pop();
	}

	return 0;
}