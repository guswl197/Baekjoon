#include <iostream>
#include <queue>
#include <algorithm>
#include <cstring>

using namespace std;
const int MAX = 22;

int arr[MAX][MAX];
int check[MAX][MAX];
int n;

//�Ʊ��� ��ġ
int sy, sx, sh = 2;
//�Ʊ�� ���� �����
int shsum = 0;

//��ǥ ����ü, ť ����
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

//�̵��Ÿ� ����
int maxsum = 0;

//���� �� �ִ� ����� ��
//BFS() ������ ������ 0 �̶�� ��
int ableFish = 0;
//���� ����� �����
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
	//for�� ���ߴ� flag;
	int fflag = 0;
	while (true) {
		// 1. ��� ���� ��ġ �������� BFS ������
		//    ���� �� �ִ� ��� �ľ�
		check[sx][sy] = 1;
		q.push({ sx,sy,1 });
		bfs();
		//���� �� �ִ� ����Ⱑ ���ٸ� ��.
		if (ableFish == 0) break;

		//���� ����� �Ÿ��� ���� �� �ִ� ������ check�迭�� minFish ��
		// 2. ���� �� �ִ� �����
		//    ���� ���̶��, ���� '��' �̸鼭 ���� '����' �� �����
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (check[i][j] == minFish && arr[i][j] < 0) {
					//���� ����� 
					shsum += 1;
					//��� ��ġ ����
					sx = i; sy = j;
					//�ʿ��� ����� ���ֱ�...
					arr[i][j] = 0;
					//�̵��Ÿ� ���ϱ�
					maxsum += minFish - 1;

					cout << sx << ' ' << sy << ' ' << maxsum<< ' ' << sh << '\n';
					for (int i = 0; i < n; i++) {
						for (int j = 0; j < n; j++) {
							cout << arr[i][j] << ' ';
						}
						cout << '\n';
					}
					cout << '\n';


					fflag = 1;
					//���� ���� ����� ���� ���ũ�Ⱑ ���ٸ� ���ũ��+1
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
		//���� �� �ִ� ����� 0���� �ʱ�ȭ
		ableFish = 0;
		//�湮 �迭 �ʱ�ȭ
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