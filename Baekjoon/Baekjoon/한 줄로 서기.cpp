#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	cin >> n;
	int left;
	vector<int> ans(n);

	for (int i = 0; i < n; i++) {
		cin >> left;

		for (int j = 0; j < n; j++) {
			if (left == 0 && ans[j] == 0) {
				ans[j] = i + 1;
				break;
			}
			else if (ans[j] == 0) {
				left--;
			}
		}
	}

	for (int i = 0; i < n; i++) {
		cout << ans[i] << " ";
	}
	cout << "\n";
	return 0;
}