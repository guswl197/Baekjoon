#include <bits/stdc++.h>

using namespace std;
deque<pair<int, int>> st;
vector<int> ans; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	int n, l;
	int num; 
	
	cin >> n >> l; 

	for (int i =0; i < n; i++) {
		cin >> num;

		while (!st.empty() && st.back().first >= num) {
			st.pop_back();
		}

		st.push_back({ num, i });

		if (st.front().second < i - l + 1) {
			st.pop_front(); 
		}

		cout << st.front().first << " ";
	}

	cout << '\n'; 
	return 0; 
}
   
