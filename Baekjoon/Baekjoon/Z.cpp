#include <iostream>
#include<cmath>

using namespace std;

int n, r, c; 
int ans;

void z(int x, int y, int size) {
	if (x == r && y == c) {
		cout << ans << '\n';
		return;
	}

	//r,c가 현재 사분면에 존재한다면
	if (x <= r && x + size > r && y <= c && y + size > c) {
		z(x, y, size / 2); //1사분면
		z(x, y + size/2, size / 2); 
		z(x + size/2, y, size / 2); 
		z(x + size/2, y + size/2, size / 2); 
	}
	else {
		ans += size * size; 
	}
}

int main() {
	cin >> n >> r >> c; 
	z(0, 0, pow(2, n)); 
	return 0; 
}