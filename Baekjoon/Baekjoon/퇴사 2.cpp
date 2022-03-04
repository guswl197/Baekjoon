#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int d[1500000];
vector<pair<int, int>> v;

int main(void) {
	int n;
	cin >> n;
	v.push_back(make_pair(0, 0));
	for (int i = 1; i <= n; i++) {
		int a, b;
		cin >> a >> b;
		v.push_back(make_pair(a, b));
	}

	/* D[i] = i-1일까지 일했을 때 받는 최대 금액 */
	for (int i = 1; i <= n; i++) {
		d[i + v[i].first] = max(d[i + v[i].first], d[i] + v[i].second);  // i번째 일을 했을 때 갱신
	    d[i + 1] = max(d[i + 1], d[i]); // i+1번째에 일을 하지 않았으니 전값과 비교해 최대 갱신
	}

	cout << d[n + 1] << '\n';
	return 0;
}
