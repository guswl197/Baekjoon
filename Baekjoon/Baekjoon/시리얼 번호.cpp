#include <bits/stdc++.h>

using namespace std;

int n; 
vector<string> v;

bool comp(const string& a, const string& b) {
	if (a.size() < b.size()) {
		return true;
	}
	else if (a.size() > b.size()) {
		return false;
	}
	else { //같다면 
		int asum = 0, bsum = 0; 
		for (int i = 0; i < a.size(); i++) {
			if (isdigit(a[i])) {
				asum += a[i] - '0'; 
			}
		}

		for (int i = 0; i < b.size(); i++) {
			if (isdigit(b[i])) {
				bsum += b[i] - '0';
			}
		}
	
		if (asum < bsum) {
			return true;
		}
		else if (asum > bsum) {
			return false;
		}
		else { // 같다면 
			return a < b; 
		}
	}
	
	return false;
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin>> n; 
	for (int i = 0; i < n; i++) {
		string str;
		cin >> str;
		v.push_back(str); 
	}

	sort(v.begin(), v.end(), comp);

	for (int i = 0; i < v.size(); i++) {
		cout << v[i] << '\n';
	}
	return 0; 
}
