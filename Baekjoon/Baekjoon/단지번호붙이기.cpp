#include <iostream>
#include <vector>
#include <algorithm>
#include <string>

using namespace std;
int n;
int num = 0; 
int arr[25][25]; 
int visit[25][25];
int dx[4] = {1,-1, 0, 0}; 
int dy[4] = {0,0,1,-1};
vector<int> v; 

void dfs(int x, int y) {
	num++; 
	visit[x][y] = 1; 

	for (int i = 0; i < 4; i++) {
		int nx = x+dx[i];
		int ny = y+ dy[i];
		if (nx < 0 || nx >= n || ny < 0 || ny >= n) {
			continue;
		}
		if (!visit[nx][ny] && arr[nx][ny] == 1) {
			dfs(nx, ny); 
		}
	}
}

int main(void) {
	cin >> n; 
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		for (int j = 0; j < n; j++) {
			arr[i][j] = str[j] - '0';
		}
	}
		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				num = 0; 
				if (!visit[i][j] && arr[i][j] == 1) {
					dfs(i, j); 
					v.push_back(num); 
				}
			}
		}

		sort(v.begin(), v.end()); 

		cout << v.size()<<'\n';

		for (int i = 0; i < v.size(); i++) {
			cout << v[i] << '\n'; 
		}
	

	return 0; 
}