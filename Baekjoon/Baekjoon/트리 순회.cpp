#include <bits/stdc++.h>

using namespace std;

int n;
int rc[27]; 
int lc[27]; 

void preorder(int cur) { 
	cout << char(cur + 'A' -1);
	if (lc[cur] != 0) {
		preorder(lc[cur]); 
	}
	if (rc[cur] != 0) {
		preorder(rc[cur]);
	}
}

void inorder(int cur) { 
	if (lc[cur] != 0) {
		inorder(lc[cur]);
	}
	cout << char(cur + 'A' - 1);
	if (rc[cur] != 0) {
		inorder(rc[cur]);
	}
}

void postorder(int cur) { 
	if (lc[cur] != 0) {
		postorder(lc[cur]);
	}
	if (rc[cur] != 0) {
		postorder(rc[cur]);
	}
	cout << char(cur + 'A' - 1);
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> n;
	for (int i = 0; i < n; i++) {
		char e, l, r; 
		cin >> e >> l >> r; 
		if (l != '.') {
			int idx = e - 'A' + 1; 
			int child = l - 'A' + 1; 
			lc[idx] = child; 
		}

		if (r != '.') {
			int idx = e - 'A' + 1;
			int child = r - 'A' + 1;
			rc[idx] = child;
		}
	}

	preorder(1); cout << '\n'; 
	inorder(1); cout << '\n';
	postorder(1); cout << '\n';
}
