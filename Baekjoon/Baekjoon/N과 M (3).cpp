#include <iostream>

using namespace std;

int n, m;
int arr[10]; 
int visit[10]; 

void backTracking(int cnt) {
	if (cnt==m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout << '\n'; 
	}
	else {
		for (int i = 1; i <= n; i++) {
				arr[cnt] = i; 
				backTracking(cnt + 1); 
		}
	}
}

int main() {
	cin >> n>>m; 
	backTracking(0); 

	return 0; 
}
