#include <bits/stdc++.h>

using namespace std;

int n, m, k; 
int r, c; //스티커
int notebook[45][45]; 
int sticker[11][11];
bool flag = false; 
vector<pair<int, int>> pos; 

bool checkPut(int x , int y ) {

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (i+x >= n || j+y >= m) {
				vector<pair<int, int>>().swap(pos);
				return false; 
			}
			if (notebook[i+x][j+y] == 0 && sticker[i][j] == 1) {
				pos.push_back({ i + x, j + y });
			}
			else if(notebook[i + x][j + y] ==1 && sticker[i][j] == 1){
				vector<pair<int, int>>().swap(pos);
				return false;
			}
		}
	}

	return true; 
}

bool checkRotate() {
	flag = false;

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (checkPut(i, j)) {
				flag = true;
				return flag; 
			}
		}
	}

	return flag; 
}

void rotate() {
	int temp[45][45]; 

	for (int i = 0; i <r; i++) {
		for (int j = 0; j < c; j++) {
			temp[j][r-1-i] = sticker[i][j]; 
		}
	}
	swap(r, c); 
	memset(sticker, 0, sizeof(sticker)); 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			sticker[i][j] = temp[i][j]; 
		}
	}

}

void put() {
	for (int i = 0; i < 4; i++) {
		if (checkRotate() == false) {
			rotate(); 
		}
		else { //노트북에 붙이기  
			for (int i = 0; i < pos.size(); i++) {
				int x = pos[i].first;
				int y = pos[i].second;
				notebook[x][y] = 1;
			}
				return; 
		}
	}
}


int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m >> k; 

	while (k--) {
		cin >> r >> c; 
		memset(sticker, 0, sizeof(sticker));

		for (int i = 0; i < r; i++) {
			for (int j = 0; j < c; j++) {
				cin >> sticker[i][j]; 
			}
		}
		put();   
	}

	int ans = 0; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (notebook[i][j] == 1) {
				ans++; 
			}
		}
	}

	cout << ans << '\n'; 
	return 0;
}
