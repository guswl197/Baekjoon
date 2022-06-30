#include <iostream>

using namespace std;

int n;
        
int fibo(int n) {

	//base
	if (n == 0) {
		return 0; 
	}
	if (n == 1) {
		return 1; 
	}
	//recur
	return fibo(n - 1) + fibo(n - 2); 
}
int main() {
	cin >> n;
	int result= fibo(n);

	cout << result << '\n';
	return 0; 
}