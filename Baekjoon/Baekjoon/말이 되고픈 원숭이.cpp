#include <bits/stdc++.h>

using namespace std;

int k, w, h; 
int arr[201][201]; 
int hx[] = {-2,-2,-1,-1,1,1,2,2 }; 
int hy[] = {-1,1,-2,2,-2,2,-1, 1}; 
int dx[] = { 0,0,1, -1 }; 
int dy[] = { 1,-1,0, 0 }; 
int visited[201][201][31];
int x, y, cnt; 

bool check(int x, int y) {
	if (x < 0 || x >= h || y < 0 || y >= w) {
		return false;
	}

	return true;
}

int bfs() {
	queue<tuple<int, int,int>> q;
	q.push({ 0,0,0}); 

	while (!q.empty()) {
		tie(x, y, cnt) = q.front(); 
		q.pop(); 

		if (x == h - 1 && y == w - 1) {
			return visited[x][y][cnt];
		}

		//말
		for (int i = 0; i < 8; i++) {
			int nx = x + hx[i]; 
			int ny = y + hy[i];

			if (!check(nx, ny)) {
				continue; 
			}

			if (cnt<k && !visited[nx][ny][cnt+1] && !arr[nx][ny]) {
				visited[nx][ny][cnt+1] = visited[x][y][cnt] + 1;
				q.push({ nx,ny, cnt+1 });
			}
		}

		//인접 4
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 

			if (!check(nx, ny)) {
				continue;
			}

			if (!visited[nx][ny][cnt] && !arr[nx][ny]) {
				visited[nx][ny][cnt] = visited[x][y][cnt] + 1;
				q.push({ nx,ny, cnt });
			}
		}
	}

	return -1; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> k;
	cin >> w >> h; 
	for (int i = 0; i < h; i++) {
		for (int j = 0; j < w; j++) {
			cin >> arr[i][j]; 
		}
	}

	cout<<bfs(); 

	return 0; 
}
