#include <iostream>
#include <vector>
#include <string>
#include <map>

using namespace std;

map<string, int> MAP; 
vector<string> vc;

int main() {
	int n, m;
	int ans = 0; 
	cin >> n >> m; 

	//µè
	for (int i = 0; i < n; i++) {
		string s;
		cin >> s;
		MAP[s]++; 
	}

	//º¸
	for (int i = 0; i < m; i++) {
		string s;
		cin >> s;
		MAP[s]++;
	}

	for (auto it = MAP.begin(); it!=MAP.end(); it++) {
		if (it->second == 2) {
			ans++; 
			vc.push_back(it->first); 
		}
	}

	cout << ans << endl;
	for (int i = 0; i < vc.size(); i++) {
		cout << vc[i] << endl; 
	}

	return 0; 
}