#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	string word = "UCPC"; 
	getline(cin, str);

	for (int i = 0; i < 4; i++) {
		if (str.find(word[i]) != string::npos) {
			int idx = str.find(word[i]);
			str.erase(0, idx);
		}
		else {
			cout << "I hate UCPC" << '\n'; 
			return 0; 
		}
	}

	cout << "I love UCPC" << '\n';
	return 0;
}