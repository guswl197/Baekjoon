#include <iostream>
#include <queue>
#include <string>
using namespace std;

int main(void) {

	queue<int> q1;
	queue<int> q2;
	int n, k;
	cin >> n >> k;

	for (int i = 0; i < n; i++) {
		q1.push(i + 1);
	}

	while (1) {

		if (q2.size() == n) {
			break;
		}

		for (int i = 0; i < k - 1; i++) {
			int num = q1.front();
			q1.pop();
			q1.push(num);
		}
		q2.push(q1.front());
		q1.pop();
	}

	cout << '<';
	for (int i = 0; i < n - 1; i++) {
		cout << q2.front() << ", ";
		q2.pop();
	}
	cout << q2.front() << '>' << '\n';

	return 0;
}