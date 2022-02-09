#include <iostream>

using namespace std;

int n, m, h; 
int arr[100][100][100]; //h n m

int main(void) {
	cin >> n >> m >> h; 

	for (int i = 0; i < h; i++) {
		for (int j = 0; j < n; j++) {
			for (int k = 0; k < m; k++) {
				cin>>arr[i][j][k];
				if (arr[i][j][k] == 1) {
					
				}
			}
		}
	}

	
}