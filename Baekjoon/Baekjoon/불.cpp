#include <bits/stdc++.h>

using namespace std;

int n; 
int w, h; 
char arr[1001][1001]; 
queue<pair<int, int>> fq; 
queue<pair<int, int>> sq; 
int fvisit[1001][1001]; 
int svisit[1001][1001];
int dx[] = { 1,-1,0,0 }; 
int dy[] = { 0,0,-1,1 }; 
int ans; 

void bfs() {

	//불
	while (!fq.empty()) {

		int x = fq.front().first; 
		int y = fq.front().second;
		fq.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				continue;
			}

			if (fvisit[nx][ny] == -1 && arr[nx][ny] != '#') {
				fvisit[nx][ny] = fvisit[x][y] + 1; 
				fq.push({ nx,ny });
			}
		}
	}

	//상근이
	while (!sq.empty()) {
		int x = sq.front().first;
		int y = sq.front().second;
		sq.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i]; 

			if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
				ans = svisit[x][y] + 1; 
				return; 
			}
			
			if ((fvisit[nx][ny]>=0 && fvisit[nx][ny] <= svisit[x][y] + 1) || arr[nx][ny] == '#') {
				continue;
			}
			if (svisit[nx][ny] == -1 && arr[nx][ny] == '.') {
				svisit[nx][ny] = svisit[x][y] + 1; 
				sq.push({ nx, ny }); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n; 
	
	while (n--) {
		ans = 0; 
		cin >> w >> h;

		while (!sq.empty()) sq.pop();
		while (!fq.empty()) fq.pop();
		
		memset(arr, 0, sizeof(arr));
		for (int i = 0; i < h; i++) {
			fill(fvisit[i], fvisit[i] + w, -1);
			fill(svisit[i], svisit[i] + w, -1);
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				cin >> arr[i][j];
				if (arr[i][j] == '*') {
					fq.push({ i,j }); 
					fvisit[i][j] = 0; 
				}
				if (arr[i][j] == '@') {
					sq.push({ i,j }); 
					svisit[i][j] = 0;
				}
			}
		}

		bfs();

		if (ans > 0) {
			cout << ans << '\n'; 
		}
		else {
			cout << "IMPOSSIBLE" << '\n'; 
		} 
	}

	return 0; 
}
