#include <iostream>
#include <vector>
#include <string>

using namespace std;

int main(void) {
	vector<string> v(5); 
	string result; 

	for (int i = 0; i < 5; i++) {
		string s;
		cin >> s; 
		//v[i] = s; 
		v.push_back(s); 
	}

	for (int i = 0; i < 15; i++) {
		for (int j = 0; j < 5; j++) {
			if (v[j].size() > i) {
				result += v[j][i];
			}
		}
	}

	cout << result << '\n';
	return 0; 
}