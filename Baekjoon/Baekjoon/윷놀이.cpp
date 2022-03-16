#include <iostream>

using namespace std;

int main(void) {
	int t = 3; 
	while (t--) {

		int num = 0;
		for (int i = 0; i < 4; i++) {
			int a;
			cin >> a;
			if (a == 1) {
				num++;
			}
		}

		switch (num) {
		case 0:
			cout << 'D' << '\n';
			break; 

		case 1:
			cout << 'C' << '\n';
			break;

		case 2:
			cout << 'B' << '\n';
			break;

		case 3:
			cout << 'A' << '\n';
			break;

		case 4:
			cout << 'E' << '\n';
			break;
		}
	}
	return 0; 
}