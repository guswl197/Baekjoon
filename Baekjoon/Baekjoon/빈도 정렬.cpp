#include <bits/stdc++.h>

using namespace std;

bool cmp(const pair<int, int> &a, const pair<int, int> &b) {
	return a.first > b.first; 
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	int n, c;
	cin >> n >> c;
	vector<pair<int, int>> arr; //{cnt, num} 
	for (int i = 0; i < n; i++) {
		int x; 
		cin >> x;
		bool chk = false; 
		for (auto &a : arr) {
			if (a.second == x) {
				chk = true;
				a.first++;
				break;
			}
		}

		if (!chk) {
			arr.push_back({ 1,x }); 
		}
	}

	stable_sort(arr.begin(), arr.end(), cmp); 

	for (auto b : arr) {
		while (b.first--) {
			cout << b.second << ' '; 
		}
	}
}
