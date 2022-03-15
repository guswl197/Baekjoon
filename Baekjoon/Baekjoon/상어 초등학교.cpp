#include<iostream>
#include<vector>

using namespace std;

vector<pair<int, int>> unit = { {1,0},{-1,0},{0,1},{0,-1} };

int in_range(int n, pair<int, int> p) {
	if (p.first < 0) return 0;
	if (p.first >= n) return 0;
	if (p.second < 0) return 0;
	if (p.second >= n) return 0;
	return 1;
}

int main() {
	int n;
	cin >> n;

	vector<vector<int>> A(n, vector<int>(n, 0));
	vector<int> students(n * n);
	vector<vector<int>> favorites(n * n, vector<int>(4));
	vector<pair<int, int>> located(n * n);

	for (int i = 0; i < n * n; i++) {
		cin >> students[i];
		for (auto& fav : favorites[i]) cin >> fav;
	}

	for (int l = 0; l < n * n; l++) {

		int sn = students[l];
		vector<int>& favorite = favorites[l];

		vector<vector<pair<int, int>>> points(n, vector<pair<int, int>>(n, { 0,0 }));

		pair<int, int> best = { -1,-1 };
		pair<int, int> bestcon = { -1,-1 };

		for (int i = 0; i < n; i++) {
			for (int j = 0; j < n; j++) {
				if (A[i][j] != 0) continue;


				for (auto& dir : unit) {
					pair<int, int> p = { i + dir.first,j + dir.second };
					if (!in_range(n, p)) continue;
					for (auto& fav : favorite) {
						if (A[p.first][p.second] == fav) points[i][j].first += 1;
						if (A[p.first][p.second] == 0) points[i][j].second += 1;
					}
				}
				if (points[i][j] > bestcon) {
					best = { i,j };
					bestcon = points[i][j];
				}
			}
		}
		A[best.first][best.second] = sn;
		located[l] = best;
	}

	//총 만족도 계산 
	int ans = 0;
	const vector<int> sat = { 0,1,10,100,1000 };

	for (int i = 0; i < n * n; i++) {
		pair<int, int>& pos = located[i];
		vector<int>& favs = favorites[i];

		int cur_sat = 0;

		for (auto &dir : unit) {
			pair<int, int> p = { pos.first + dir.first,pos.second + dir.second };
			if (in_range(n, p) == 0) continue;
			for (auto fav : favs) {
				if (A[p.first][p.second] == fav) cur_sat += 1;
			}
		}
		ans += sat[cur_sat];
	}

	cout << ans << '\n';

}