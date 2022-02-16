#include <iostream>

using namespace std;

int main(void) {
	int p;
	int m;
	int ans = 0; 
	cin >> p; 
	m = 1000 - p; 

	ans += m / 500; 
	m = m % 500;
	
	ans += m / 100;
	m = m % 100;

	ans += m / 50;
	m = m % 50;

	ans += m /10;
	m = m % 10;

	ans += m / 5;
	m = m % 5;

	ans += m / 1;
	m = m % 1;

	cout << ans << '\n'; 
	return 0;
}