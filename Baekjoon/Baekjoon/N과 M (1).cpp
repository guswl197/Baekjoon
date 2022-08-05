#include <iostream>

using namespace std;

int n, m;
int arr[10];
int visit[10]; 

void dfs(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << arr[i] << ' ';
		}
		cout <<'\n'; 
	}
	else {
		for (int i = 1; i <= n; i++) {
			if (!visit[i]) {
				arr[cnt] = i;
				visit[i] = 1;
				dfs(cnt + 1); 
				visit[i] = 0; 
			}
		}
	}
}
int main() {
	cin>> n >> m; 
	dfs(0); 
	return 0;
}
