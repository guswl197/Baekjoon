include <bits/stdc++.h>

using namespace std;

int n, l;
deque<pair<int, int>> st;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n >> l; 

	for (int i = 1; i <= n; i++) {
		int x; 
		cin >> x; 
		
		while (!st.empty() && st.back().first > x) {
			st.pop_back(); 
		}
		if (!st.empty() && st.front().second < i - l + 1) {
			st.pop_front(); 
		}
		st.push_back({ x, i });

		cout<<st.front().first << ' '; 
	}

	return 0; 
}
