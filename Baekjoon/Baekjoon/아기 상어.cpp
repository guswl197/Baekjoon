#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 22;

int arr[MAX][MAX];
int check[MAX][MAX];
int n;

//아기상어 위치
int sy, sx, sh = 2;
//아기상어가 먹은 물고기
int shsum = 0;

//좌표 구조체, 큐 생성
struct coor {
	int x;
	int y;
	int cnt;
};

queue <coor> q;
//inside
bool inside(int x, int y) {
	return x >= 0 && x < n && y >= 0 && y < n;
}

int dx[4] = { 0,0,-1,1 };
int dy[4] = { -1,1,0,0 };

//이동거리 도합
int maxsum = 0;

//잡을 수 있는 물고기 수
//BFS() 돌리고 나서도 0 이라면 끝
int ableFish = 0;
//가장 가까운 물고기
int minFish = 987987987;

void bfs() {
	minFish = 987987987;
	while (!q.empty()) {
		int x = q.front().x;
		int y = q.front().y;
		int cnt = q.front().cnt;
		q.pop();
		check[x][y] = cnt;

		int nx, ny;
		for (int i = 0; i < 4; i++) {
			nx = x + dx[i];
			ny = y + dy[i];
			if (inside(nx, ny) && check[nx][ny] == 0 && arr[nx][ny] <= sh) {
				if (arr[nx][ny] < sh && arr[nx][ny] != 0) {
					if (arr[nx][ny] > 0) {
						arr[nx][ny] *= -1;
					}

					ableFish += 1;
					if (cnt + 1 < minFish) {
						minFish = cnt + 1;
					}
				}
				check[nx][ny] = cnt + 1;
				q.push({ nx, ny, cnt + 1 });
			}
		}
	}
}

void solution() {
	//for문 멈추는 flag;
	int fflag = 0;
	while (true) {
		// 1. 상어 현재 위치 기준으로 BFS 돌리기
		//    먹을 수 있는 고기 파악
		check[sx][sy] = 1;
		q.push({ sx,sy,1 });
		bfs();
		//먹을 수 있는 물고기가 없다면 끝.
		if (ableFish == 0) break;

		//가장 가까운 거리의 먹을 수 있는 물고기는 check배열에 minFish 값
		// 2. 먹을 수 있는 물고기
		//    같은 값이라면, 가장 '위' 이면서 가장 '왼쪽' 인 물고기
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == minFish && arr[i][j] < 0) {
					//먹은 물고기 
					shsum += 1;
					//상어 위치 갱신
					sx = i; sy = j;
					//맵에서 물고기 없애기...
					arr[i][j] = 0;
					//이동거리 더하기
					maxsum += minFish - 1;
					fflag = 1;
					//만약 먹은 물고기 수와 상어크기가 같다면 상어크기+1
					if (shsum == sh) {
						shsum = 0;
						sh += 1;
					}
					break;
				}
			}
			if (fflag == 1) break;
		}
		fflag = 0;
		//잡을 수 있는 물고기 0으로 초기화
		ableFish = 0;
		//방문 배열 초기화
		memset(check, 0, sizeof(check));
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

	cout << maxsum << endl;

	return 0;
}