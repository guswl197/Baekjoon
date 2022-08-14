#include <bits/stdc++.h>

using namespace std;

int n, m; 
int board[10][10];
int cboard[10][10];
int dx[] = {0,1,0,-1};
int dy[] = {1,0,-1,0}; 
vector<pair<int, int>> cctv; 

void copyArray() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cboard[i][j] = board[i][j]; 
		}
	}
}

void solve(int x, int y, int num) {
	num %= 4; 
	int nx=x, ny=y; 

	while (1)
	{
		nx = nx+ dx[num];
		ny = ny + dy[num]; 

		if (cboard[nx][ny] == 6) {
			break; 
		}
		if (nx < 0 || nx >= n || ny < 0 || ny >= m) {
			break;
		}
		if (cboard[nx][ny] != 0) {
			continue;
		}
		cboard[nx][ny] = 7; 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	int mn = n * m; 

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			cin >> board[i][j]; 
			if (board[i][j] != 0 && board[i][j] != 6) {
				cctv.push_back({ i,j }); 
			}
		}
	}
	

	for (int i = 0; i<(1 << (2 * cctv.size())); i++) {
		int tmp = i;
		copyArray();

		for (int j = 0; j < cctv.size(); j++) {
			int num = tmp % 4;
			tmp /= 4;
			int x = cctv[j].first;
			int y = cctv[j].second;

			if (board[x][y] == 1) {
				solve(x, y, num);
			}
			else if (board[x][y] == 2) {
				solve(x, y, num);
				solve(x, y, num + 2);
			}
			else if (board[x][y] == 3) {
				solve(x, y, num);
				solve(x, y, num + 1);
			}
			else if (board[x][y] == 4) {
				solve(x, y, num);
				solve(x, y, num + 1);
				solve(x, y, num + 2);
			}
			else if (board[x][y] == 5) {
				solve(x, y, num);
				solve(x, y, num + 1);
				solve(x, y, num + 2);
				solve(x, y, num + 3);
			}
		}

		int ans = n * m; 
		for (int k = 0; k < n; k++) {
			for (int l = 0; l < m; l++) {
				if (cboard[k][l] != 0) {
					ans--; 
				}
			}
		}
		mn = min(mn, ans); 
	}

	cout << mn << '\n';
	return 0; 
}
