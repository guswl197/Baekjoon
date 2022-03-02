#include <cstdio>
using namespace std;
int d[11];

int main(void) {

	int t;
	scanf("%d", &t);

	d[0] = 1;

	for (int i = 1; i <= 11; i++) {

		if (i - 1 >= 0) {
			d[i] += d[i - 1];
		}
		if (i - 2 >= 0) {
			d[i] += d[i - 2];
		}
		if (i - 3 >= 0) {
			d[i] += d[i - 3];
		}
	}

	while (t--) {
		int n;
		scanf("%d", &n);
		printf("%d\n", d[n]);
	}
	return 0;
}