#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main(void) {
	int n; 
	int number = 1;
	cin >> n;
	vector<int> v(n); 

	for (int i = 0; i < n; i++) {
		cin >> v[i]; 
	}
	
	sort(v.begin(), v.end()); 

	for (int i = 0; i < n; i++) {
		if (number < v[i]) {
			break; 
		}
		number += v[i]; 
	}
	cout << number << '\n'; 

	return 0; 
}