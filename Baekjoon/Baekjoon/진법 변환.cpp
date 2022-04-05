#include <iostream>
#include <string>
#include <algorithm>
#include <math.h>

using namespace std;

int main() {
	string str;
	int ans=0; 
	int b;
	cin >> str>>b;
	reverse(str.begin(), str.end()); 

	for (int i = 0; i < str.size(); i++) {
		if ('A' <= str[i] && str[i] <= 'Z') {
			ans += pow(b, i)* (str[i] - 'A'+10);
		}
		else {
			ans += pow(b, i)* (str[i]-'0'); 
		}
	}

	cout << ans << endl;
	return 0; 
}