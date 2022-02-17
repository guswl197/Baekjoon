#include <iostream>
#include <string>
#include <vector>

using namespace std;

int main(void) {
	string str;
	string temp = ""; 
	cin >> str;
	int result = 0;
	bool minus = false;

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '+' || str[i] == '-' || str[i] == '\0') {
			if (minus == true) {
				result += -stoi(temp); 
			}
			else {
				result += stoi(temp); 
			}
			temp = "";
			if (str[i] == '-') {
				minus = true;
				continue;
			}
			temp += str[i]; 
		}
		
	}
	cout << result << '\n'; 
	return 0; 
}