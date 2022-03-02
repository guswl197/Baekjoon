#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n, k;
	int ans = 0;
	cin >> n >> k;
	vector<int> schedule(k);
	vector<int> tab(n, 0);

	for (int i = 0; i < k; i++) {
		cin >> schedule[i];
	}

	for (int i = 0; i < k; i++) {
		bool flag = false;
		for (int j = 0; j < n; j++) {
			if (tab[j] == schedule[i]) {
				flag= true;
				break;
			}
		}

		if (flag == true) {
			continue;
		}

		for (int j = 0; j < n; j++) {
			if (tab[j] == 0) {
				tab[j] = schedule[i];
				flag = true;
				break;
			}
		}
		if (flag == true) {
			continue;
		}

		int last = -1;
		int index = -1;
		for (int j = 0; j < n; j++) {
			int tmp = 0;
			for (int t = i + 1; t < k; t++) {
				if (schedule[t] == tab[j]) {
					break;
				}
				tmp++;
			}
			if (tmp > last) {
				last = tmp;
				index = j;
			}
		}

		tab[index] = schedule[i];
		ans++;
	}

	cout << ans << '\n';
	return 0;
}