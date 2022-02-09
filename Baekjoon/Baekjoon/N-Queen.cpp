#include <iostream>
#include <algorithm>
#include <stdlib.h>
#include <queue>

using namespace std;

int n;
int arr[15][15]; 
int dx[8] = {-1,-1,-1,0,1,1,1,0}; 
int dy[8] = {-1,0,1,1,1,0,-1,-1}; 
int ans = 0; 

void bfs(int x, int y) {
	queue<pair<int, int>> q; 
	q.push(make_pair(x, y)); 
	arr[x][y] = 1;

	while (!q.empty()) {
		int cur_x = q.front().first;
		int cur_y = q.front().second;

		for (int i = 0; i < 8; i++) {
			int nx = cur_x + dx[i]; 
			int ny = cur_y + dy[i];

			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue; 
			}
			if (arr[nx][ny] == 0) {
				arr[nx][ny] = 1;
				q.push(make_pair(nx, ny)); 
			}
		}
	}
}

int main(void) { 
	cin >> n; 
	memset(arr, 0, sizeof(arr)); 

	for (int a = 0; a < n; a++) {
		for (int k = 0; k < n; k++) {
			int cnt = 0;
			for (int i = 0; i < n; i++) {
				for (int j = 0; j < n; j++) {
					if (arr[i][j] == 0) {
						bfs(i, j);
						cnt++;
					}
				}
			}
			if (cnt == n) {
				ans++;
			}
		}
	}

}