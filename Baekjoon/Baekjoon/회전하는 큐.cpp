#include <bits/stdc++.h>

using namespace std;

int n, pos;
int cnt;
deque<int> dq;
vector<int> v;

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> n >> pos; 
	for (int i = 0; i < pos; i++) {
		int x;
		cin >> x;
		v.push_back(x); 
	}

	for (int i = 1; i <= n; i++) {
		dq.push_back(i); 
	}

	for (int i = 0; i < v.size(); i++) {
		int x = v[i]; 
		auto it =find(dq.begin(), dq.end(), x); 
		int idx = it - dq.begin(); 
		int size = dq.size(); 

		if (x != dq.front()) {
			if (abs(idx-1) < abs(idx - size)) { //f
				while (dq.front() != x) {
					int f = dq.front();
					dq.push_back(f);
					dq.pop_front();
					cnt++;
				}
			}
			else { //b 
				while (dq.back() != x) {
					int b = dq.back();
					dq.push_front(b);
					dq.pop_back();
					cnt++;
				}
				dq.push_front(dq.back());
				dq.pop_back();
				cnt++;
			}
		}

		dq.pop_front(); 
	}

	cout << cnt << '\n'; 
	return 0; 
}
