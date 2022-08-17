#include <bits/stdc++.h>

using namespace std;

int n, m; 
int board1[51][51];
int board2[51][51];
int visited[51][51]; 
int mn; 
vector<pair<int, int>> choice; 
vector<pair<int, int>> chicken; 
vector<pair<int, int>> house; 

int distance(int x, int y ) {
	int ans = 2 * n*n*n;

	for (int i = 0; i<choice.size(); i++) {
		int cx = choice[i].first; 
		int cy = choice[i].second; 
		ans = min(abs(cx - x) + abs(cy - y), ans); 
	}

	return ans; 
}

void checkBoard() {
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			board2[i][j] = board1[i][j]; 
		}
	}

	for (int i = 0; i < m; i++) {
		int x = choice[i].first;
		int y = choice[i].second; 

		board2[x][y] = 3; 
	}
	
}

void choiceChicken(int start,int cnt) {
	if (cnt == m ) {
		checkBoard();
		int ans = 0; 

		for (int i = 0; i < house.size(); i++) {
			int x = house[i].first;
			int y = house[i].second; 
			ans+= distance(x,y);
		}
		mn = min(ans, mn); 
		return; 
	}
	else {
		for (int i = start; i < chicken.size(); i++) {
			int x = chicken[i].first; 
			int y = chicken[i].second; 

			if (!visited[x][y]) {
				visited[x][y] = 1; 
				choice.push_back({ x,y });
				choiceChicken(i, cnt + 1); 
				visited[x][y] = 0;
				choice.pop_back(); 
			}
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> m; 
	mn =2*n * n*n; 
	for (int i = 0; i < n; i++) {
		for (int j = 0; j < n; j++) {
			cin >> board1[i][j];
			if (board1[i][j] == 2) {
				chicken.push_back({ i,j });
			}
			if (board1[i][j] == 1) {
				house.push_back({ i,j });
			}
		}
	}

	choiceChicken(0,0); 
	
	cout << mn << '\n'; 
	return 0; 
}
