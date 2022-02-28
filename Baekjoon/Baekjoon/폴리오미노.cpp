#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string str;
	cin >> str;

	while (1) {
		if (str.find("XXXX") != string::npos) {
			int idx = str.find("XXXX");
			str.erase(idx, 4);
			str.insert(idx, "AAAA");
		}
		else if (str.find("XX") != string::npos) {
			int idx = str.find("XX");
			str.erase(idx, 2);
			str.insert(idx, "BB");
		}
		else {
			break; 
		}
	}

	if (str.find('X') != string::npos) {
		cout << -1 << '\n'; 
		return 0; 
	}

	cout << str << '\n'; 
	return 0; 
}