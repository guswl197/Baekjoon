#include <iostream>
#include <vector>
#include <queue>
#include <cstring>

using namespace std;

int n; 
pair<int, int> sang;
pair<int, int> goal;
vector<pair<int, int>> con;
int visit[101]; 

bool bfs(int x, int y) {
	queue<pair<int, int>> q;
	q.push({ x,y }); 
	
	while (!q.empty()) {
		int nx = q.front().first; 
		int ny = q.front().second; 
		q.pop(); 

		if (abs(goal.first - nx) + abs(goal.second - ny) <= 1000) {
			return true;
		}
		for (int i = 0; i < con.size(); i++) {
			if (abs(con[i].first - nx) + abs(con[i].second - ny) <= 1000 && visit[i] == 0) {
				q.push({ con[i].first, con[i].second });
				visit[i] = 1;
			}
		}
	}

	return false;
}

int main() {
	int t;
	cin >> t; 
	while (t--) {
		cin >> n; 
		cin >> sang.first >> sang.second; 
		vector<pair<int, int>>().swap(con);
		memset(visit, 0, sizeof(visit)); 

		for (int i = 0; i < n; i++) {
			int a, b;
			cin >> a >> b;
			con.push_back({ a,b }); 
		}

		cin >> goal.first >> goal.second; 

		if (bfs(sang.first, sang.second)==true) {
			cout << "happy" << '\n';
		}
		else {
			cout << "sad" << '\n';
		}
	}

	return 0;
}
