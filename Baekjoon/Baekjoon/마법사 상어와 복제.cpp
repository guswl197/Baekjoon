#include <iostream>
#include <vector>

using namespace std;

struct fish {
	int x;
	int y;
	int dir; 
};

int m, s, maxEating;
vector<fish> fishMap[5][5],cMap[5][5];
pair<int, int> shark; 
int smellMap[5][5]; 
int tempRoute[3], route[3];

int fdx[] = { 0, 0, -1, -1, -1, 0, 1, 1, 1 };
int fdy[] = { 0, -1, -1, 0, 1, 1, 1, 0, -1 };

int sdx[] = { 0, -1, 0, 1, 0 };
int sdy[] = { 0, 0, -1, 0, 1 };

void copyMap(vector<fish> a[5][5], vector<fish> b[5][5]) {
	for (int i = 1; i<= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			a[i][j] = b[i][j]; 
		}
	}
}

int changeDir(int dir) {
	switch (dir) {
	case 1:
		return 8;
	case 2:
		return 1;
	case 3:
		return 2;
	case 4:
		return 3;
	case 5:
		return 4;
	case 6:
		return 5;
	case 7:
		return 6;
	case 8:
		return 7;
	}
}

void moveFish() {
	vector<fish> tempMap[5][5];

	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < fishMap[i][j].size(); k++) {
				int x = fishMap[i][j][k].x; 
				int y = fishMap[i][j][k].y;
				int dir = fishMap[i][j][k].dir;
				int nx, ny;
				bool flag = false;
				for (int l = 0; l < 8; l++) {
					nx = x + fdx[dir]; 
					ny = y + fdy[dir]; 
					if (nx >= 1 && nx <= 4 && ny >= 1 && ny <= 4) {
						if ((nx != shark.first || ny != shark.second) && smellMap[nx][ny] == 0) {
							flag= true;
							break; 
						}
					}
					dir = changeDir(dir); 
				}
				if (flag == true) {
					fish f = { nx, ny, dir }; 
					tempMap[nx][ny].push_back(f);
				}
				else {
					fish f = { x, y, dir };
					tempMap[x][y].push_back(f);
				}
			}
		}
	}

	copyMap(fishMap, tempMap);
}

int routeSimulation() {
	bool visit[6][6] = { false, }; 
	int x = shark.first; 
	int y = shark.second; 
	int eat = 0; 
	for (int i = 0; i < 3; i++) {
		int dir = tempRoute[i]; 
		int nx = x + sdx[dir]; 
		int ny = y + sdy[dir]; 
		if (nx < 1 || nx>4 || ny < 1 || ny>4) {
			return -1; 
		}
		if (visit[nx][ny] == false) {
			visit[nx][ny] = true;
			eat += fishMap[nx][ny].size(); 
		}
		x = nx; 
		y = ny; 
	}

	return eat; 
}

void findRoute(int cnt) {
	
	if (cnt == 3) {
		int eatNum = routeSimulation();
		if (eatNum > maxEating) {
			for (int i = 0; i < 3; i++) {
				route[i] = tempRoute[i]; 
			}
			maxEating = eatNum; 
		}
		return; 
	}

	for (int i = 1; i <= 4; i++) {
		tempRoute[cnt] = i; 
		findRoute(cnt + 1);
	}
}

void moveShark(int time) {
	vector<fish> tempMap[5][5];
	copyMap(tempMap, fishMap);

	int x = shark.first; 
	int y = shark.second; 
	for (int i = 0; i < 3; i++) {
		int dir = route[i]; 
		int nx = x + sdx[dir]; 
		int ny = y + sdy[dir];
		if (tempMap[nx][ny].size() != 0) {
			smellMap[nx][ny] = time; 
			tempMap[nx][ny].clear(); 
		}
		x = nx;
		y = ny;
		shark.first = x; 
		shark.second = y; 
	}
	copyMap(fishMap, tempMap);
}

void removeSmell(int time) {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			if (smellMap[i][j] == 0) {
				continue;
			}
			if (time - smellMap[i][j] == 2) {
				smellMap[i][j] = 0; 
			}
		}
	}
}

void bornFish() {
	for (int i = 1; i <= 4; i++) {
		for (int j = 1; j <= 4; j++) {
			for (int k = 0; k < cMap[i][j].size(); k++) {
				fishMap[i][j].push_back(cMap[i][j][k]); 
			}
		}
	}
}

int main() {
	cin >> m >> s; 
	for (int i = 0; i < m; i++) {
		int x, y, d; 
		cin >> x >> y >> d; 
		fish f = { x,y ,d }; 
		fishMap[x][y].push_back(f); 
	}

	cin >> shark.first >> shark.second;

	for (int i = 1; i <= s; i++) {
		copyMap(cMap, fishMap); 
		moveFish();
		maxEating = -1; 
		findRoute(0);
		moveShark(i);
		removeSmell(i);
		bornFish();
	}

	int ans = 0;
	for (int i = 1; i <=4; i++) {
		for (int j = 1; j <=4; j++) {
			ans += fishMap[i][j].size();
		}
	}

	cout << ans << endl; 
	return 0; 
}