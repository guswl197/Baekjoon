#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

int n,l;
int dx[] = { -2,-2,-1,-1,1,1,2,2 }; 
int dy[] = { -1,1,-2,2,-2,2,-1,1 }; 
int visit[301][301]; 
pair<int, int> pos; 
pair<int, int> des;
queue<pair<int, int>> q; 

void bfs(int x, int y) {
	q.push({ x,y }); 

	while (!q.empty()) {
		int px = q.front().first; 
		int py = q.front().second; 
		q.pop(); 

		for (int i = 0; i < 8; i++) {
			int nx = px + dx[i]; 
			int ny = py + dy[i]; 

			if (nx < 0 || nx >= l || ny < 0 || ny >= l) {
				continue;
			}

			if (visit[nx][ny] == 0 || visit[nx][ny] > visit[px][py] + 1) {
				visit[nx][ny] = visit[px][py] + 1;
				q.push({ nx,ny }); 
			}
		}
	}
}

int main() {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		memset(visit, 0, sizeof(visit)); 
		cin >> l;
		cin >> pos.first >> pos.second;
		cin >> des.first >> des.second;

		if (pos.first == des.first && pos.second == des.second) {
			cout << 0 << '\n';
			continue;
		}

		bfs(pos.first, pos.second);


		cout<<visit[des.first][des.second]<<'\n';
	}

	return 0; 
}
