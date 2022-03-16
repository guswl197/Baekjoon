#include <iostream>
#include <string>
using namespace std;

int main(void) {
	string s;
	string result;
	cin >> s; 

	for (int i = 0; i < s.size(); i++) {
		char temp; 
		temp = s[i] - 3; 
		if (temp<'A') {
			temp += 26; 
		}
		result += temp; 
	}

	cout << result << '\n';
	return 0; 
}