#include <iostream>
#include <string>

using namespace std;

int main(void) {
	string str;
	int minus = 0; 
	int ans = 0; 
	string num;
	cin >> str; 

	for (int i = 0; i < str.size(); i++) {
		if (str[i] == '-') {
			minus = 1;
		}
		else if (minus == 1 && str[i]=='+') {
			str[i] = '-'; 
		}
	}

	int i = 0; 
		while (1) {
			num += str[i++];
			if (str[i] == '+' || str[i] == '-' ) {
				ans += stoi(num); 
				num = "";
			}
			if (i == str.size()) {
				ans += stoi(num); 
				break; 
			}
		}

	cout << ans << '\n'; 

	return 0; 
}