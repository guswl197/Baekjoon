#include <bits/stdc++.h>

using namespace std;

int t;
string str;
int num;
set<int> s;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> t;

	while (t--) {
		cin >> str;
		if (str == "add") {
			cin >> num;
			if (s.find(num) != s.end())
				continue;
			s.insert(num);
		}
		else if (str == "remove") {
			cin >> num;
			if (s.find(num) == s.end())
				continue;
			s.erase(num);
		}
		else if (str == "check") {
			cin >> num;
			if (s.find(num) != s.end()) {
				cout << 1 << '\n';
			}
			else {
				cout << 0 << '\n';
			}
		}
		else if (str == "toggle") {
			cin >> num;
			if (s.find(num) != s.end()) {
				s.erase(num);
			}
			else {
				s.insert(num);
			}
		}
		else if (str == "all")
		{ 
			s = { 1,2,3,4,5,6,7,8,9,10,11,12,13,14,15,16,17,18,19,20 };
		}
		else {
			s.clear(); 
		}
	}
}
