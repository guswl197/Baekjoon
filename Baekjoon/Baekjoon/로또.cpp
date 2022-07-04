#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int k; 
vector<int> arr; 
int res[10];
int visit[10];

void backTracking(int start, int cnt) {
	if (cnt == 6) {
		for (int i = 0; i < 6; i++) {
			cout << res[i] << ' ';
		}
		cout << '\n';
	}
	else {
		for (int i = start; i < k; i++) {
			if (!visit[i]) {
				visit[i] = 1; 
				res[cnt] = arr[i]; 
				backTracking(i,cnt + 1); 
				visit[i] = 0; 
			}
		}
	}
}

int main() {
	while (1) {
		cin >> k; 
		if (k == 0) {
			break; 
		}
		vector<int>().swap(arr); 

		for (int i = 0; i < k; i++) {
			int a; 
			cin >> a; 
			arr.push_back(a); 
		}

		sort(arr.begin(), arr.end()); 

		backTracking(0,0); 
		cout << '\n'; 
	}

	return 0;
}
