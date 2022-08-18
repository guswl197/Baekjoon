#include <bits/stdc++.h>

using namespace std;

char board[15][10]; 
int visited[15][10]; 
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1,0,0 }; 
int cnt,ans; 

void dfs(int x , int y ) {
	visited[x][y] = 1; 
	
	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (nx<0 || nx>=12 || ny<0 || ny>=6){
			continue; 
		}
		if (!visited[nx][ny] && board[nx][ny] == board[x][y]) {
			cnt++;
			dfs(nx, ny); 
		}
	}
}

void remove() {
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (visited[i][j] == 1) {
				board[i][j] = '.'; 
			}
		}
	}
}

bool bomb() {
	bool flag = false; 

	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			if (!visited[i][j] && board[i][j] != '.') {
				memset(visited, 0, sizeof(visited));
				cnt = 1; 
				dfs(i,j);
				if (cnt >=4) {
					remove(); 
					flag = true; 
				}
			}
		}
	}

	return flag; 
}

void down() {
	
	for (int i = 0; i < 6; i++) {
		char tmp[15];
		int idx = 11;

		for (int j = 11; j >= 0; j--) {
			if (board[j][i] != '.') {
				tmp[idx--] = board[j][i];
			}
		}

		for (int i = idx; i >=0; i--) {
			tmp[i] = '.';
		}

		for (int j = 0; j < 12; j++) {
			board[j][i] = tmp[j]; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 12; i++) {
		for (int j = 0; j < 6; j++) {
			cin >> board[i][j]; 
		}
	}

	while (1) {
		if (bomb()) {
			down(); 
			ans++;  
		}
		else {
			break; 
		}
	}

	cout << ans << '\n';
	return 0; 
}
