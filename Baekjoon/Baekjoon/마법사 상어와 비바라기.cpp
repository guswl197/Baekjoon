#include <bits/stdc++.h>

using namespace std;

int n, m; 
int a[51][51];
int tmp[51][51]; 
int cloud[51][51];
int dx[] = {0,0,-1,-1,-1,0,1,1,1};
int dy[] = {0,-1,-1,0,1,1,1, 0,-1}; 
int dx2[] = { -1,-1,1,1 };
int dy2[] = { -1,1,-1,1 }; 

int add(int x, int y) {
	int cnt = 0; 
	for (int i = 0; i < 4; i++) {
		int nx = x + dx2[i]; 
		int ny = y + dy2[i]; 
		if (nx <= 0 || nx > n || ny <= 0 || ny > n) {
			continue;
		}
		if (a[nx][ny] >= 1) {
			cnt++;
		}
	}

	return cnt; 
}

void solve(int d, int s) {

	// 1,2,3번 
	memset(tmp, 0, sizeof(tmp)); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cloud[i][j]) {
				int nx = i + dx[d] * s; 
				int ny = j + dy[d] * s;

				while (nx <= 0) {
					nx += n; 
				}
				while (ny <= 0) {
					ny += n; 
				}
				while (nx > n) {
					nx -= n; 
				}
				while (ny > n) {
					ny -= n; 
				}

				cloud[i][j] = 0; 
				tmp[nx][ny] = 1; 
				a[nx][ny] += 1; 
			}
		}
	}
	//show(); 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cloud[i][j] = tmp[i][j];
		} 
	}

	// 4번
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cloud[i][j]) {
				a[i][j]+=add(i,j); 
			}
		}
	}

	//5번
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			if (cloud[i][j]) {
				cloud[i][j] = 0; 
				continue; 
			}
			if (a[i][j] >= 2) {
				cloud[i][j] = 1; 
				a[i][j] -= 2; 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> a[i][j]; 
		}
	}

	cloud[n][1] = cloud[n][2] = cloud[n - 1][1] = cloud[n - 1][2] = 1; // 비구름 
	for (int i = 0; i < m; i++) {
		int d, s; 
		cin >> d >> s;
		solve(d,s);
	}

	int ans = 0;
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			ans += a[i][j]; 
		}
	}

	cout << ans << '\n'; 
	return 0; 

}
