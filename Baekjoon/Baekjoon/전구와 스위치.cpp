#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n;
	int num = 0; 
	int same;
	cin >> n; 
	vector<char> cur(n);
	vector<char> ans(n);

	for (int i = 0; i < n; i++) {
		cin >> cur[i]; 
	}
	for (int i = 0; i < n; i++) {
		cin >> ans[i];
	}

	while (1) {
		same = 0;
		for (int i = 0; i < n; i++) { 
			if (cur[i] != ans[i]) {
				cur[i] == '1' ? cur[i] = '0' : cur[i] = '1';
				if (i - 1 >= 0) {
					cur[i - 1] == '1' ? cur[i - 1] = '0' : cur[i - 1] = '1';
				}
				if (i + 1 < n) {
					cur[i + 1] == '1' ? cur[i + 1] = '0' : cur[i + 1] = '1';
				}
				num++; 
			}
			else {
				same++;
			}
		}

		if (same == n) {
			cout << num << '\n'; 
			return 0; 
		}
	}

	return 0; 
}