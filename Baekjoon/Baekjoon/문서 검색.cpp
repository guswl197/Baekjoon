#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string str;
	string word;
	getline(cin, str);

	getline(cin, word);
	int ans = 0;

	while (1) {
		if (str.find(word) != string::npos) {
			ans++;
			int idx = str.find(word);
			str.erase(0, word.size() + idx);
		}
		else {
			break;
		}
	}

	cout << ans << '\n';
	return 0;
}