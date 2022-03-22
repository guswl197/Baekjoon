#include <iostream>
#include <string>
#include <vector>

using namespace std;

string king, stone; 
int n;  
pair<int, int> k, s; 
int board[9][9]; 

bool check(int a, int b) {
	if (a <= 0 || a > 8 || b <= 0 || b > 8) {
		return false;
	}
	return true; 
}

int main(void) {
	cin >> king >> stone >> n;
	vector<string> m(n + 1);
	for (int i = 0; i < n; i++) {
		cin >> m[i]; 
	}

	k.first = king[0] - 'A' + 1;
	k.second = king[1] - '0'; 
	s.first = stone[0] - 'A' + 1; 
	s.second = stone[1] - '0';

	for (int i = 0; i < n; i++) {
		int x = 0, y = 0; 
		if (m[i] == "R") {
			y = 1; 
		}
		else if (m[i] == "L") {
			y = -1; 
		}
		else if (m[i] == "B") {
			x = -1;
		}
		else if (m[i] == "T") {
			x = 1;
		}
		else if (m[i] == "RT") {
			x = 1, y = 1; 
		}
		else if (m[i] == "LT") {
			x = 1, y = -1;
		}
		else if (m[i] == "RB") {
			x = -1, y = 1; 
		}
		else if (m[i] == "LB") {
			x = -1, y = -1; 
		}

		if (check(k.first + y, k.second + x)){
			if (k.first + y == s.first && k.second + x == s.second) {
				if (check(s.first + y, s.second + x)) {
					k.first += y, k.second += x; 
					s.first += y, s.second += x;
				}
			}
			else {
				k.first += y, k.second += x;
			}
		}
	}

	string kans = "";
	kans+= k.first + 'A' -1;
	kans += k.second + '0';
	string sans = "";
	sans += s.first + 'A' - 1;
	sans += s.second + '0';
	std::cout <<kans<< '\n';
	std::cout << sans << '\n';

	return 0; 
}