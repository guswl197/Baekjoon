#include <iostream>
#include <algorithm>
#include <cstring>

using namespace std;

int arr[101][101]; 
int n; 
int ma = 0; 
int ans=0;
int visit[101][101]; 
int dx[4] = { 0,0,1,-1 }; 
int dy[4] = { 1,-1,0,0 }; 

void dfs(int x, int y,int h) {

	visit[x][y] = 1; 

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 

		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			continue;
		}
		if(!visit[nx][ny] && arr[nx][ny]>h){
			dfs(nx, ny, h); 
		}
	}

}

int main(void) {
	cin >> n; 
	memset(visit, 0, sizeof(visit)); 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> arr[i][j]; 
			ma = max(ma, arr[i][j]); 
		}
	}

	for (int k = 0; k <= ma; k++) {
		int num = 0; 
		memset(visit, 0, sizeof(visit));
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (visit[i][j] == 0&&arr[i][j]>k) {
					dfs(i, j,k);
					num++;
				}
			}
		}
		ans = max(ans, num); 
	}

	cout << ans << '\n'; 

	return 0; 
}