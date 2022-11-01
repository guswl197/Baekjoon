#include <bits/stdc++.h>

using namespace std;
int num; 
int x, y; 

bool check(string str) {
	for (int i = 0; i < str.size(); i++) {
		if (str[i] == 'a' || str[i] == 'e' || str[i] == 'i' || str[i] == 'o' || str[i] == 'u') {
			num++; 
			x=0, y++;
		}
		else {
			y = 0; 
			x++; 
		}
		if (x >= 3 || y >= 3) {
			return false; 
		}

		if (i != 0 && str[i] == str[i - 1] && str[i] !='e' && str[i]!='o') {
			return false;
		}
	}

	if (num == 0) {
		return false;
	}

	return true; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
 
	while (1) {
		string str;
		cin >> str;
		num = 0;
		x = 0, y = 0; 
		if (str == "end") {
			break; 
		}

		if (check(str) == true) {
			cout << '<' << str << '>' << " is acceptable."<<'\n';
		}
		else {
			cout << '<' << str << '>' << " is not acceptable." << '\n';
		}
	}

	return 0;
}
