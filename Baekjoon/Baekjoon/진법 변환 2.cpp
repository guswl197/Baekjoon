#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

int main(){
	int n, b;
	cin >> n >> b;

	string ans;
	while (n != 0)
	{
		int tmp = n % b;
		if (tmp > 9){
			tmp = tmp - 10 + 'A';
			ans += tmp;
		}
		else{
			ans += ('0' + tmp);
		}
		n /= b;
	}
	reverse(ans.begin(), ans.end());

	cout << ans << '\n';

	return 0;
}