#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <cstring>

using namespace std;

bool check(int first,int second,int x, int y ) {
	if (first + x >= 1 && first + x <= 8 && second + y >= 1 && second + y <= 8) {
		return true; 
	}
	return false; 
}

int main(void) {
	int n;
	string king; 
	string stone;  
	cin >> king;
	cin >> stone; 
	cin >> n;
	vector<string> v(n); 
	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}

	pair<int, int> pk = { king[0] - 'A' + 1,king[1]-'0' };
	pair<int, int> ps  = { stone[0] - 'A' + 1,stone[1]-'0' };

	for (int i = 0; i < n; i++) {
		int x=0, y=0; 
		if (v[i] == "R") {
				x += 1; 
		}
		else if (v[i] == "L") {
				x -= 1;
		}
		else if (v[i] == "B") {
				y-= 1;
		}
		else if (v[i] == "T") {
				y += 1;
		}
		else if (v[i] == "RT") {
				x += 1;
				y += 1;
		}
		else if (v[i] == "LT") {
				x -= 1;
				y += 1;
		}
		else if (v[i] == "RB") {
				x += 1;
				y -= 1;
		}
		else if (v[i] == "LB") {
				x -= 1;
				y -= 1;
		}

		if (check(pk.first, pk.second, x, y)) {
			pk.first += x;
			pk.second += y;
		}
		else {
			continue; 
		}

		if (pk.first == ps.first && pk.second == ps.second) {
			if (check(ps.first, ps.second, x, y)) {
				ps.first += x;
				ps.second += y;
			}
			else {
				pk.first -= x;
				pk.second -= y;
			}
		}
	}

	string kans= "", sans = "";

	kans += pk.first + 'A' - 1;
	kans += pk.second+'0'; 
	sans += ps.first + 'A' - 1;
	sans += ps.second + '0';

	cout << kans << '\n'<<sans<<'\n';
	return 0; 
}