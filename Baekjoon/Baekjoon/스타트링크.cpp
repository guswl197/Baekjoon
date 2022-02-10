#include <iostream>
#include <queue>

using namespace std;

int f, s, g, u, d; 
queue<int> q; 
int visit[1000001]; 

void bfs() {
	q.push(s); 
	visit[s]= 1;

	while (!q.empty()) {
		int top = q.front();
		q.pop(); 

		for (int i = 0; i < 2; i++) {
			int nx = i == 0 ? top + u : top - d; 

			if (0 >= nx || nx > f) {
				continue;
			}
			if (visit[nx] == 0) {
				q.push(nx); 
				visit[nx] = visit[top]+1;
			}
			if (nx == g) {
				return;
			}
		}

	}

}

int main(void) {
	cin >> f >> s >> g >> u >> d; 
	bfs(); 

	if (visit[g] == 0) {
		cout << "use the stairs" << '\n'; 
	}
	else {
		cout << visit[g]-1 << '\n';
	}

	return 0; 
}