#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {

	int n, k;
	string a;
	vector<char> result;
	cin >> n >> k;
	cin >> a;

	int i = 0;
	while (i != a.size()) {
		while (k != 0 && !result.empty() && result.back() < a[i]) {
			result.pop_back();
			k--;
		}
		result.push_back(a[i]);
		i++;
	}
	while (k--) {
		result.pop_back();
	}
	for (int i = 0; i < result.size(); i++) {
		cout << result[i];
	}

	return 0;
}