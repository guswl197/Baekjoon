#include <bits/stdc++.h>

using namespace std;

int l, r, c; //층수, 행, 열 
int si, sj, sk;
char arr[31][31][31]; 
int visited[31][31][31];
int dx[] = { 1,-1, 0,0, 0,0 }; 
int dy[] = { 0,0, 1,-1,0, 0 }; 
int dz[] = { 0,0,0,0 ,1,-1 }; 
int ans;

void bfs(int i, int j,int k) {
	queue<tuple<int, int, int>> q; 
	q.push({ i,j,k }); 
	visited[i][j][k] = 1;

	while (!q.empty()) {
		int z = get<0>(q.front());
		int x = get<1>(q.front());
		int y = get<2>(q.front());
		q.pop(); 
		 
		for (int i = 0; i < 6; i++) {
			int nz = z + dz[i]; 
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
 
			if (nx < 0 || nx >= r || ny < 0 || ny >= c || nz < 0 || nz >= l) {
				continue; 
			}

			if (arr[nz][nx][ny] == 'E') {
				ans = visited[z][x][y] + 1; 
				return; 
			}

			//cout << visited[nx][ny][nz] << ' ' << arr[nx][ny][nz] << '\n';
			if (visited[nz][nx][ny] == 0 && arr[nz][nx][ny] == '.') {
				visited[nz][nx][ny] = visited[z][x][y] + 1;
				q.push({ nz,nx,ny }); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	while (1) {
		ans = 0; 

		cin >> l >> r >> c;
		if (l == 0 && r == 0 && c == 0) {
			break; 
		}
		memset(arr, 0, sizeof(arr)); 
		memset(visited, 0, sizeof(visited));

		for (int i = 0; i < l; i++) {
			for (int j = 0; j < r; j++) {
				for (int k = 0; k < c; k++) {
					cin >> arr[i][j][k]; 
					if (arr[i][j][k] == 'S') {
						si = i, sj = j, sk = k; 
					}
				}
			}
		}

		bfs(si, sj, sk); 

		if (ans > 0) {
			cout << "Escaped in " << ans-1 << " minute(s)." << '\n'; 
		}
		else {
			cout << "Trapped!" << '\n'; 
		}
	}

	return 0;
}
