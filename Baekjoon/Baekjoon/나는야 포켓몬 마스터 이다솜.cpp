#include <iostream>
#include <map>
#include <string>

using namespace std;

int main() {
	
	ios_base::sync_with_stdio(0);
	cin.tie(NULL);

	int n, m; 
	cin >> n >> m;
	map<string, int> poketStr;
	map<int, string> poketNum;
	for (int i = 0; i < n; i++) {
		string s; 
		cin >> s;
		poketStr.insert(make_pair(s ,i + 1)); 
		poketNum.insert(make_pair(i+1, s));
	}
	
	for (int i = 0; i < m; i++) {
		string s; 
		cin >> s;

		if ('1'<= s[0] && s[0] <= '9') {
			int tmp = stoi(s); 
			cout << poketNum[tmp] << '\n';
		}
		else {
			cout << poketStr[s] << '\n';
		}
	}
	
	return 0; 
}