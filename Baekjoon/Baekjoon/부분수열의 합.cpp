#include <iostream>

using namespace std;

int n, s;
int arr[30];
int cnt = 0;

void func(int cur, int tot) {
	if (cur == n) {
		if (tot == s) {
			cnt++;
		}
		return;
	}
	func(cur + 1, tot); //����X
	func(cur + 1, tot + arr[cur]); //����O
}
int main(void) {
	cin >> n >> s;
	for (int i = 0; i < n; i++){
		cin >> arr[i];
	}

	func(0, 0);
	if (s == 0) {
		cnt--;
	}
	cout << cnt<<'\n';
	return 0; 
}