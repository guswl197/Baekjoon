#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int n, m;
int num1, num2;
int arr[101][101]; 
int visit[101]; 

void bfs(int x) {
	queue<int> q; 
	q.push(x);
	visit[x] = 1;

	while (!q.empty()) {
		int top = q.front(); 
		q.pop(); 

		for (int i = 1; i <= n; i++) {
			if (arr[top][i] == 1 && !visit[i]) { 
				visit[i] = visit[top]+1;
				q.push(i);   
				if (i == num2) {
					return; 
				}
			}
		}

	}
}

int main(void) {
	cin >> n;
	cin >> num1 >> num2;
	cin >> m; 
	memset(visit, 0, sizeof(visit)); 

	for (int i = 0; i < m; i++) {
		int a, b; 
		cin >> a >> b; 
		arr[a][b] = arr[b][a] = 1; 
	}

	bfs(num1); 

	cout << visit[num2]-1 << '\n'; 

}