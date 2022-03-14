#include <iostream>

using namespace std;

int col[15]; 
int n, total = 0; 

bool check(int level)
{
	for (int i = 0; i < level; i++)
		if (col[i] == col[level] || abs(col[level] - col[i]) == level - i)
			return false;
	
	return true;
}

void nqeen(int x) {
	if (x == n) {
		total++; 
	}
	else {
		for (int i = 0; i < n; i++) {
			col[x] = i; 
			if (check(x)) {
				nqeen(x + 1); 
			}
		}
	}
}
int main(void) {
	cin >> n;
	nqeen(0); 
	cout << total << '\n';
	return 0; 
}