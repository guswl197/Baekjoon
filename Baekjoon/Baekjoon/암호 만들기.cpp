#include <bits/stdc++.h>

using namespace std;

int l, c;
vector<char> v;
char arr[20];
int visited[30];
int a, b; 

bool check() {
	a = 0, b = 0; 

	for (int i = 0; i < l; i++) {
		char x = arr[i];
		if (x == 'a' || x == 'e' || x == 'i' || x == 'o' || x == 'u') {
			a++;
		}
		else {
			b++;
		}
	}

	if (a >= 1 && b >= 2) {
		return true;
	}

	return false;
}

void backTracking(int start, int cnt) {
	if (cnt == l && check()) {
		for (int i = 0; i < l; i++) {
			cout << arr[i];
		}
		cout << '\n';
	}

	for (int i = start; i < c; i++) {
		char x = v[i]; 
		int ix = v[i] - 'a' + 1;
		if (!visited[ix]) {
			arr[cnt] = x;
			visited[ix] = 1;
			backTracking(i, cnt + 1);
			visited[ix] = 0;
		}
	}
}

int main() {
	ios::sync_with_stdio(0);
	cin.tie(0);
	cin >> l >> c; 
	for (int i = 0; i < c; i++) {
		char ch;
		cin >> ch;
		v.push_back(ch);
	}
	
	sort(v.begin(), v.end());
	backTracking(0, 0);

	return 0;
}
