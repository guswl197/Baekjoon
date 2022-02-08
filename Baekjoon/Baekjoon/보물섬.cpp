#include <stdio.h>
#include <iostream>
#include <stdlib.h>
#include <cstring>
#include <queue>
using namespace std;

int dy[4] = { 1,-1,0,0 };
int dx[4] = { 0,0,1,-1 };
char map[50][50];
bool visit[50][50];
int t = 0;
int n, m;

void bfs(int x, int y) {
	int path = 0;
	memset(visit, 0, sizeof(visit));
	queue< pair<int, int> > q;
	q.push(make_pair(x, y));
	visit[x][y] = true;

	while (!q.empty()) {
		int qsize = q.size();

		for (int i = 0; i < qsize; ++i) {
			int cur_x = q.front().first;
			int cur_y = q.front().second;
			q.pop();

			for (int j = 0; j < 4; ++j) {
				int nx = cur_x + dx[j];
				int ny = cur_y + dy[j];

				if (0 > nx || nx >= n || 0 > ny || ny >= m) continue;
				if (map[nx][ny] == 'W' || visit[nx][ny]) continue;

				q.push(make_pair(nx, ny));
				visit[nx][ny] = true;
			}
		}
		path++;
	}
	t = max(t, path - 1);
}

int main() {
	cin >> n >> m;

	for (int i = 0; i < n; ++i) {
		cin >> map[i];
	}

	for (int i = 0; i < n; i++) {
		for (int j = 0; j < m; j++) {
			if (map[i][j] == 'L') {
				bfs(i, j);
			}
		}
	}

	cout << t;

}