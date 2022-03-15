#include <iostream>
#include <algorithm>
#include <algorithm>

using namespace std;

int n; 
int s[21][21];
int ans = 1000; 
int svisit[21]; 
int start = 0;
int link = 0; 

void dfs(int cnt, int pos) {
	if (cnt == n / 2) {
		int start = 0;
		int link = 0;
		for (int i = 1; i <= n; i++) {
			for (int j = 1; j <= n; j++) {
				if (svisit[i] && svisit[j]) {
					start += s[i][j];
				}
				else if (!svisit[i] && !svisit[j]) {
					link += s[i][j];
				}
			}
		}
		ans = min(ans, abs(start - link)); 
		return; 
	}

	for (int i = pos; i <= n; i++) {
		if (!svisit[i]) {
			svisit[i] = 1; 
			dfs(cnt + 1, i+1); 
			svisit[i] = 0; 
		}
	}
}

int main(void) {
	cin >> n; 
	for (int i = 1; i <= n; i++) {
		for (int j = 1; j <= n; j++) {
			cin >> s[i][j]; 
		}
	}

	dfs(0,1);
	cout << ans << '\n';
	return 0; 
}