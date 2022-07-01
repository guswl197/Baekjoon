#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; 
vector<int> v; 
int arr[10]; 
int visit[10001]; 

void backTracking(int start , int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n'; 
	}
	
	for (int i = start; i <n; i++) {
		int x = v[i]; 
		if (!visit[x]) {
			arr[cnt] = x;
			visit[x] = 1; 
			backTracking(i, cnt + 1); 
			visit[x] = 0; 
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
	backTracking(0,0); 
	return 0; 
}
