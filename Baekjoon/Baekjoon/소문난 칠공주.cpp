#include <bits/stdc++.h>

using namespace std;

int dx[] = { 0,0,1,-1 };
int dy[] = { 1,-1, 0,0 };
char arr[26]; 
int visited[26]; 
int visitedC[5][5];
int ans = 0; 

void bfs() {
	memset(visitedC, 0, sizeof(visitedC));
	int cnt = 0; 
	queue<pair<int, int>> q; 
	for (int i = 0; i < 25; i++) {
		if (visited[i]) {
			q.push({ i / 5,i % 5 }); 
			visitedC[i / 5][i % 5] = 1; 
			cnt++;
			break; 
		}
	}

	while (!q.empty()) {
		int x = q.front().first; 
		int y = q.front().second; 
		q.pop(); 

		if (cnt == 7) {
			ans++; 
			break; 
		}
		for (int i = 0; i < 4; i++) {
			int nx = x + dx[i]; 
			int ny = y + dy[i]; 
			if (nx < 0 || nx >= 5 || ny < 0 || ny >= 5) {
				continue;
			}
			if (visited[nx * 5 + ny] && !visitedC[nx][ny]) {
				visitedC[nx][ny] = 1; 
				q.push({ nx, ny }); 
				cnt++; 
			}
		}
	}
}

void backTracking(int index, int s, int cnt) {
	if (cnt == 7) {
		if (s >= 4) {
			bfs(); //인접 확인
		}
	}

	for (int i = index; i < 25; i++) {
		if (!visited[i]) {
			visited[i] = 1;
			if (arr[i] == 'S') {
				backTracking(i, s + 1, cnt + 1); 
			}
			else {
				backTracking(i, s, cnt + 1);
			}
			visited[i] = 0; 
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	for (int i = 0; i < 25; i++) {
		char c;
		cin >> c;
		arr[i] = c;
	}

	backTracking(0, 0, 0); 
	cout << ans << '\n';
	return 0; 
}

