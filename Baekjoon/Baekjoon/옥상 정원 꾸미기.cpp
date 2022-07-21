#include <bits/stdc++.h>

using namespace std;

int n;
stack<int> s; 
long long ans; 

int main() {
	ios::sync_with_stdio(0); 
	cin.tie(0); 
	
	cin >> n; 
	long long h; 

	while (n--) {
		cin >> h; 
		while (!s.empty() && s.top() <= h) {
			s.pop(); 
		}
		ans += s.size(); 
		s.push(h); 
	}
	cout << ans << '\n'; 
	return 0; 
}
