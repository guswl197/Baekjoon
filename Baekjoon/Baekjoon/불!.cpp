#include <bits/stdc++.h>

using namespace std;

int r, c; 
char arr[1001][1001]; 
int jvisited[1001][1001];
int fvisited[1001][1001]; 
queue<pair<int, int>> jq;
queue<pair<int, int>> fq; 
int dx[] = { 1,-1 ,0,0 }; 
int dy[] = { 0,0,1,-1 }; 

int jbfs() {
	while (!jq.empty()) {
		int x = jq.front().first; 
		int y = jq.front().second; 
		jq.pop(); 

		if (x == 0 || y == 0 || x == r - 1 || y == c - 1) {
			return jvisited[x][y]+1;
		}

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				continue; 
			}
			if (arr[nx][ny] == '.' &&!jvisited[nx][ny] && (fvisited[nx][ny] > jvisited[x][y] + 1 || !fvisited[nx][ny])) {
				jvisited[nx][ny] = jvisited[x][y] + 1; 
				jq.push({ nx,ny }); 
			}
		}
	}

	return 0; 
}

void fbfs() {

	while (!fq.empty()) {
		int x = fq.front().first;
		int y = fq.front().second;
		fq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];

			if (nx < 0 || nx >= r || ny < 0 || ny >= c) {
				continue;
			}
			if (arr[nx][ny] == '.' && !fvisited[nx][ny]) {
				fvisited[nx][ny] = fvisited[x][y] + 1;
				fq.push({ nx,ny });
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int ans=0; 
	cin >> r >> c; 
	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			cin >> arr[i][j]; 
		}
	}

	for (int i = 0; i < r; i++) {
		for (int j = 0; j < c; j++) {
			if (arr[i][j] == 'F') {
				fq.push({ i,j }); 
			}
			if (arr[i][j] == 'J') {
				jq.push({ i,j });
			}
		}
	}

	fbfs(); 
	ans=jbfs(); 

	if (ans == 0) {
		cout << "IMPOSSIBLE" << '\n';
	}
	else {
		cout << ans << '\n';
	}
	return 0;
}
