#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; 
vector<int> v; 
int arr[10]; 

void backTracking(int cnt ) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n'; 
	}
	else {
		for (int i = 0; i < n; i++) {
			int x = v[i];
			arr[cnt] = x;
			backTracking(cnt + 1);
		}
	}
}

int main() {
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		int a;
		cin >> a;
		v.push_back(a); 
	}

	sort(v.begin(), v.end()); 
	backTracking(0); 
	return 0; 
}
