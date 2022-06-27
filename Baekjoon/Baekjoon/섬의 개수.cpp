#include <iostream>
#include <vector>
#include <cstring>

using namespace std;

int w, h; 
int result; 
int visit[51][51]; 
int dx[] = { 1,-1 ,0,0 ,1,1,-1,-1}; 
int dy[] = { 0,0,1,-1 ,1,-1,1,-1}; 
int v[51][51]; 

void dfs(int x, int y ) {
	visit[x][y] = 1; 
	for (int i = 0; i < 8; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 
		if (nx < 0 || nx >= h || ny < 0 || ny >= w) {
			continue; 
		}
		if (visit[nx][ny] == 0  && v[nx][ny]==1) {
			dfs(nx, ny); 
		}
	}
}

int main() {

	while (1) {
		result = 0; 
		memset(visit, 0, sizeof(visit)); 
		memset(v, 0, sizeof(v));
		cin >> w >> h;
		if (w == 0 && h == 0) {
			return 0; 
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				int a; 
				cin >> a; 
				v[i][j] = a; 
			}
		}

		for (int i = 0; i < h; i++) {
			for (int j = 0; j < w; j++) {
				if (visit[i][j] == 0 && v[i][j] == 1) {
					dfs(i, j);
					result++;
				}
			}
		}

		cout << result<<'\n';
	}

	return 0;
}
