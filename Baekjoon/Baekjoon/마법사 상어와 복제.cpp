#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

int arr[5][5]; //격자
int temp[5][5]; //이전 물고기(복제)
int tdir[5][5]; //이전 물고기 방향(복제) 
int dir[5][5]; //물고기 방향 
int smell[5][5]; //물고기 냄새 
pair<int, int> visit[5][5]; //상어 bfs
queue<pair<int, int>> q;
int m; //물고기 수
int s; //연습 수
int sx, sy; //상어 위치 
//물고기 방향 
int fx[9] = { 0,0,-1,-1,-1,0,1,1,1 };
int fy[9] = { 0,-1,-1,0,1,1,1,0,-1 };
//상어 방향
int dx[4] = { 1,-1 ,0,0 };
int dy[4] = { 0,0,1,-1 };
int fish_max = 0;

//상어, 냄새, 범위 over check
bool check(int x, int y) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (sx == i && sy == j) {
				return false;
			}
			if (smell[i][j] == 1) {
				return false;
			}
			if (i <= 0 || i > 4 || j <= 0 || j > 4) {
				return false;
			}
		}
	}
	return true;
}

//상어 3칸 이동
void sbfs(int sx, int sy) {
	q.push({ sx,sy });
	visit[sx][sy].first = 0;
	visit[sx][sy].second = 0;
	while (!q.empty()) {
		int x = q.front().first;
		int y = q.front().second;
		q.pop();

		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i];
			int ny = y + dy[i];
			if (nx < 1 || nx>4 || ny < 1 || ny>4) {
				continue;
			}
			if (!visit[nx][ny].first) {
				visit[nx][ny].first = visit[x][y].first + 1;
				visit[nx][ny].second = visit[x][y].second + arr[nx][ny];
				q.push({ nx,ny });
			}
		}
	}
}

void shark_move() {
	//sbfs(sx, sy);

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {

			if (visit[i][j].first == 3) {
				fish_max = max(fish_max, visit[i][j].second);
			}
		}
	}


}

void fish_move() {
	memset(temp, 0, sizeof(temp));
	memset(tdir, 0, sizeof(tdir));

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			//복제 저장 
			temp[i][j] = arr[i][j];
			tdir[i][j] = dir[i][j];
			if (arr[i][j] == 1) {
				if (check(i + dir[i][j], j + dir[i][j])) { //현 방향으로 이동 가능 
					arr[i][j] = 0;
					arr[i + dir[i][j]][j + dir[i][j]] = 1;
					break;
				}
				else { //방향 변경 
					for (int k = 1; k <= 8; k++) {
						int nx = i + fx[dir[i][j] - k];
						int ny = j + fy[dir[i][j] - k];
						if (dir[i][j] - k == 0) {
							int nx = i + fx[8];
							int ny = j + fy[8];
						}
						if (check(nx, ny)) {
							arr[nx][ny] = 0;
							arr[nx][ny] = 1;
							break;
						}
					}
				}
			}
		}
	}
}

int main() {
	cin >> m >> s;
	for (int i = 0; i < m; i++) {
		int a, b, d;
		cin >> a >> b >> d;
		arr[a][b] = 1;
		dir[a][b] = d;
	}
	cin >> sx >> sy;

	for (int i = 0; i < s; i++) {
		fish_move(); //물고기 복제, 이동
		shark_move(); //상어 3칸 이동 
	}
}