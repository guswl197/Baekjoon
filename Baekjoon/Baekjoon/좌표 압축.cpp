#include <bits/stdc++.h>

using namespace std;

int n;
vector<int> v; 
vector<int> tmp; 

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	
	cin >> n; 
	for (int i = 0; i < n; i++) {
		int num; 
		cin >> num; 
		tmp.push_back(num); 
		v.push_back(num); 
	}

	sort(tmp.begin(), tmp.end()); 
	tmp.erase(unique(tmp.begin(), tmp.end()), tmp.end()); 

	for (int i = 0; i < n; i++) {
		cout << lower_bound(tmp.begin(), tmp.end(), v[i])- tmp.begin()<<' '; 
	}

	cout << '\n'; 
	return 0; 

}
