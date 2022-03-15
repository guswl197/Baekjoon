#include <iostream>
#include <vector>
#include <utility>

using namespace std;

int board[9][9]; 
vector<pair<int, int>> points; 
int cnt = 0;
bool found = false; 

bool check(pair<int,int> p) {
	int square_x = p.first / 3;
	int square_y = p.second / 3;

	for (int i = 0; i < 9; i++) {
		if (board[p.first][i] == board[p.first][p.second] && i != p.second) {
			return false; 
		}
		if (board[i][p.second] == board[p.first][p.second] && i != p.first) {
			return false;
		}
	}

	for (int i = square_x * 3; i < square_x * 3 + 3; i++) {
		for (int j = square_y * 3; j < square_y * 3 + 3; j++) {
			if (board[i][j] == board[p.first][p.second]) {
				if (i != p.first && j != p.second) {
					return false; 
				}
			}

		}
	}

	return true; 
}

void sudoku(int N) {
	if (cnt== N) {
		for (int i = 0; i < 9; i++) {
			for (int j = 0; j < 9; j++) {
				cout << board[i][j] << ' '; 
			}
			cout << '\n'; 
		}
		found = true; 
		return; 
	}

	for (int j = 1; j <= 9; j++) {
		board[points[N].first][points[N].second] = j; 
		if (check(points[N])) {
			sudoku(N + 1); 
		}
		if (found == true) {
			return; 
		}
		board[points[N].first][points[N].second] = 0;
	}

	return; 
}

int main(void) {

	for (int i = 0; i < 9; i++) {
		for (int j = 0; j < 9; j++) {
			cin >> board[i][j]; 
			if (board[i][j] == 0) {
				cnt++; 
				points.push_back(make_pair(i, j)); 
			}
		}
	}

	sudoku(0); 
	return 0; 
}