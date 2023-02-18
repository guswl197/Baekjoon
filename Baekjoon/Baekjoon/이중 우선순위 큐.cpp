#include <bits/stdc++.h>

using namespace std;

int t; 
int k;
string str; 
int n; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);

	cin >> t;
	while (t--) {
		cin >> k;
		multiset<int> st;
		for (int i = 0; i < k; i++) { 
			cin >> str >> n; 

			if (str == "I") {
				st.insert(n); 
			}
			else if (str == "D" && !st.empty()) {
				if (n == 1) {
					auto it = st.end();
					it--;
					st.erase(it);
				}
				else { // n == -1
					st.erase(st.begin());
				}
			}
		}

		if (st.size() == 0) {
			cout << "EMPTY" << '\n'; 
		}
		else {
			auto it = st.end(); 
			it--; 
			std::cout << *it << " " << *(st.begin()) << '\n';
		}
	}

	return 0; 
}
