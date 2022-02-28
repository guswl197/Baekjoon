#include <iostream>
#include <vector>

using namespace std;

int main(void) {
	int n, m;
	int ans = 0;
	cin >> n >> m;
	int a=1, b=m; //¹üÀ§ start, end
	int j;
	cin >> j;
	vector<int> v(j); 
	for (int i = 0; i < j; i++) {
		cin >> v[i]; 
	}

	for (int i = 0; i < j; i++) {
		while (1) {
			if (a <= v[i] && v[i] <= b) {
				break;
			}
			else if (v[i] < a) {
				a--, b--; 
				ans++;
			}
			else if (v[i] > b) {
				a++, b++;
				ans++;
			}
		}
	}

	cout << ans << '\n'; 
	return 0; 
}