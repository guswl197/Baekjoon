#include <bits/stdc++.h>

using namespace std;

int n, l, r; 
int arr[55][55]; 
int visited[55][55]; 
int dx[] = { 0,0,1,-1 }; 
int dy[] = { 1,-1,0,0 }; 
int sum, cnt; 
int ans; 
int day; 
vector<pair<int, int>> v;

void dfs(int x, int y) {
	visited[x][y] = 1;
	sum += arr[x][y];
	cnt++;
	v.push_back({ x,y }); 

	for (int i = 0; i < 4; i++) {
		int nx = x + dx[i]; 
		int ny = y + dy[i]; 
		int sub = abs(arr[nx][ny] - arr[x][y]); 
		if (nx<=0 || nx>n || ny<=0 || ny>n) {
			continue;
		}
		if (!visited[nx][ny] && l <= sub && sub <= r) {
			visited[nx][ny] = 1; 
			dfs(nx, ny); 
		}
	}
}

void population(int sum, int cnt) {
	
	int num = sum / cnt;

	for (int i = 0; i < v.size(); i++) {
		int x = v[i].first;
		int y = v[i].second;
		arr[x][y] = num;
	}
}

void emp() {
	while (!v.empty()) {
		v.pop_back(); 
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l >> r; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> arr[i][j]; 
		}
	}

	while (1) {
		memset(visited, 0, sizeof(visited));
		day = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (!visited[i][j]) {
					emp(); 
					sum = 0, cnt = 0;
					dfs(i, j);

					if (cnt > 1) {
						population(sum, cnt);
					}
					else {
						day++; 
					}
				}
			}
		}

		if (day == n * n) {
			break;
		}
		else {
			ans++;
		}
	}

	cout << ans << '\n'; 
	return 0; 
}
