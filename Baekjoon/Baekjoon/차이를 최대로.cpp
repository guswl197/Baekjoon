#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int ans;
int arr[10]; 
int visit[10]; 
vector<int> v; 

int cal() {
	int sum = 0; 
	for (int i = 0; i < n - 1; i++) {
		sum += abs(arr[i] - arr[i + 1]); 
	}
	return sum; 
}

void backTracking(int cnt) {
	if (cnt == n) {
		int result = cal(); 
		ans= max(cal(), ans); 
	}
	else {
		for (int i = 0; i < n; i++) {
			if (!visit[i]) {
				int x = v[i];
				visit[i] = 1; 
				arr[cnt] = x;
				backTracking(cnt + 1);
				visit[i] = 0; 
			}
			
		}
	}
}

int main() {
	cin >> n;
	for (int i = 0; i < n; i++) {
		int a; 
		cin >> a;
		v.push_back(a); 
	}

	backTracking(0); 

	cout << ans << '\n';
	return 0; 
}
