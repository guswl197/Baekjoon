#include <iostream>
#include <vector>
#include <algorithm>
#include <queue>

using namespace std;

int m, n, k; 
int arr[101][101]; 
int visit[101][101];
int dx[] = { 1,-1 ,0,0 }; 
int dy[] = { 0,0, 1,-1 }; 
int lx, ly, rx, ry;
int result; 
int Max; 
vector<int> ans; 
queue < pair<int, int>> q;

int bfs(int x , int y) {
	int cnt=1; 
	q.push({ x,y }); 
	visit[x][y] = 1;

	while (!q.empty()) {
		int px = q.front().first;
		int py = q.front().second; 
		q.pop(); 

		for (int i = 0; i < 4; i++) {
			int nx = px + dx[i]; 
			int ny = py + dy[i]; 

			if (nx < 0 || nx >= m || ny < 0 || ny >= n) {
				continue;
			}
			if (visit[nx][ny] == 0 && arr[nx][ny] == 0) {
				cnt++; 
				visit[nx][ny] = 1;
				q.push({ nx ,ny }); 
			}
		}
	}

	return cnt;
}

void change(int x1,int y1, int x2, int y2) {
	lx = m - y2; 
	ly = x1; 
	rx = m - y1;
	ry = x2; 
}

int main() {
	cin >> m >> n >> k; 
	for (int i = 0; i < k; i++) {
		cin >> lx >> ly>>rx>>ry;
		change(lx, ly, rx, ry); 
		for (int j = lx; j < rx; j++) {
			for (int l = ly; l <ry; l++) {
				arr[j][l] = 1; 
			}
		}
	}
	
	for (int i = 0; i < m; i++) {
		for (int j = 0; j < n; j++) {
			if (arr[i][j] == 0 &&  visit[i][j]==0) {
				result++;
				ans.push_back(bfs(i, j));
			}
		}
	}

	sort(ans.begin(), ans.end()); 
	cout << result<<'\n';

	if (result != 0) {
		for (int i = 0; i < ans.size(); i++) {
			cout << ans[i] << ' ';
		}
	}
	return 0; 
}
