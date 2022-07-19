#include <iostream>
#include <string>
#include <list>

using namespace std;

string str;
list<char> li; 
int n;
char c;
char in; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0); 
	cin >> str;
	
	for (int i = 0; i < str.size(); i++) {
		li.push_back(str[i]); 
	}
	
	cin >> n; 
	auto cur = li.end(); 
	//cur--; 

	while (n--) {
		cin >> c; 

		if (c == 'L') {
			if (cur != li.begin()) {
				cur--; 
			}
		}
		else if (c == 'D') {
			if (cur != li.end()) {
				cur++; 
			}
		}
		else if (c == 'B') {
			if (cur != li.begin()) { 
				cur--;
				cur=li.erase(cur);
			}
		}
		else { //P
			cin >> in;
			li.insert(cur, in); 
		}
	}

	for (auto i : li) {
		cout << i;
	}
	cout << '\n';
	
	return 0; 

}
