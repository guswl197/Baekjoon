#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[22][22];
int visit[22][22];
int n;
int sy, sx, siz = 2;
int eat = 0;
queue <pair<int, int>> q;
int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };
int len = 0;
int ableFish = 0;
int minFish = 987987987;

void bfs() {
	minFish = 987987987;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
				continue;
			}
			if (!visit[nx][ny] && arr[nx][ny] <= siz) {
				visit[nx][ny] = visit[x][y] + 1;
				if (arr[nx][ny] < siz && arr[nx][ny] != 0) {
					ableFish += 1;
					if (visit[nx][ny] < minFish) {
						minFish = visit[nx][ny];
					}
				}
				q.push({ nx, ny });
			}
		}
	}
}

void solution() {

	int fflag = 0;
	while (1) {
		visit[sx][sy] = 1;
		q.push({ sx,sy });
		bfs();

		if (ableFish == 0) {
			break;
		}

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == minFish && arr[i][j]<siz && arr[i][j]!=0) {
					eat += 1;
					sx = i; sy = j;
					arr[i][j] = 0;
					len += minFish - 1;
					
					fflag = 1;
					if (eat == siz) {
						eat = 0;
						siz += 1;
					}
					break;
				}
			}
			if (fflag == 1) break;
		}
		fflag = 0;
		ableFish = 0;
		memset(visit, 0, sizeof(visit));
	}
}

int main() {

	cin >> n;
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j];
			if (arr[i][j] == 9) {
				sx = i;
				sy = j;
				arr[i][j] = 0;
			}
		}
	}

	solution();

	cout << len << endl;

	return 0;
}