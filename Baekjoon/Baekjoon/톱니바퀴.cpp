#include <bits/stdc++.h>

using namespace std;

string wheel[4]; 
int k; 
int num, dir; 
vector<int> dirs(5); 

void rotateWheel() {
	dirs[num] = dir; 

	for (int i = num; i <3; i++) {
		if (wheel[i][2] != wheel[i + 1][6]) {
			dirs[i + 1] = -dirs[i]; 
		}
		else {
			dirs[i + 1] = 0;
		}
	}

	for (int i = num; i >0; i--) {
		if (wheel[i][6] != wheel[i -1][2]) {
			dirs[i - 1] = -dirs[i];
		}
		else {
			dirs[i - 1] = 0;
		}
	}

	for (int i = 0; i < 4; i++) {
		if (dirs[i] == 1) { //시계 방향 
			rotate(wheel[i].begin(), wheel[i].begin()+7, wheel[i].end()); 
		}
		else if (dirs[i] == -1) { //반시계 방향 
			rotate(wheel[i].begin(), wheel[i].begin() + 1, wheel[i].end());
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 4; i++) { 
		cin >> wheel[i]; 
	}
	
	cin >> k; 
	for (int i = 0; i < k; i++) {
		cin >> num >> dir; 
		num--; 
		rotateWheel(); 
	}

	int ans = 0; 
	int number = 1; 
	for (int i = 0; i < 4; i++) { //s-1 , n-0 
		if (wheel[i][0] == '1') {
			ans += number; 
		}
		number *= 2; 
	}

	std::cout<< ans << '\n';
	return 0; 
}
