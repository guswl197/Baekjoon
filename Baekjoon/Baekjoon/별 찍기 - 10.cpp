#include <bits/stdc++.h>

using namespace std;

void print(int i, int j, int num) {
	if ((i / num) % 3 == 1 && (j / num) % 3 == 1) {
		cout << ' ';
	}
	else {
		if (num ==1) {
			cout << '*';
		}
		else {
			print(i, j, num / 3); 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int num; 
	cin >> num; 
	
	for (int i = 0; i < num; i++) {
		for (int j = 0; j < num; j++) {
			print(i, j, num); 
		}
		cout << '\n';
	}
	return 0; 
} 
