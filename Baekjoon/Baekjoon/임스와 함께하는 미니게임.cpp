#include <bits/stdc++.h>

using namespace std;

int num;
char game;
map<string, int> m; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> num >> game;

	for (int i = 0; i < num; i++) {
		string str;
		cin >> str; 
		m[str] = 1; 
	}

	if (game == 'Y') {
		cout << m.size() << '\n';
	}
	else if (game == 'F') {
		cout << m.size() / 2 << '\n';
	}
	else { //O
		cout << m.size() / 3 << '\n'; 
	}

	return 0; 
}
