#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n, m; 
int arr[8], res[8]; 
int visit[8]; 

void backTracking(int cnt) {
	if (cnt == m) {
		for (int i = 0; i < m; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n'; 
	}
	else {
		int pre = 0; 
		for (int i = 0; i < n; i++) {
			if (!visit[i] && arr[i] != pre) {
				res[cnt] = arr[i]; 
				pre = res[cnt]; 
				visit[i] = 1; 
				backTracking(cnt + 1); 
				visit[i] = 0; 
			}
		}

	}
}

int main(){
	cin >> n >> m;
	for (int i = 0; i < n; i++) {
		cin >> arr[i]; 
	}

	sort(arr, arr + n); 
	backTracking(0); 
}
