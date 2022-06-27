#include <iostream>
#include <vector>

using namespace std;

int n, m;
int result;
int visit[1001];
vector<vector<int>> v(1001);

void dfs(int x) {
    visit[x] = 1;

    for (int i = 0; i < v[x].size(); i++) {
        int y = v[x][i];
        if (visit[y] == 0) {
            dfs(y);
        }
    }
}

int main() {
    cin >> n >> m;
    for (int i = 0; i < m; i++) {
        int a, b;
        cin >> a >> b;
        v[a].push_back(b);
        v[b].push_back(a);
    }

    for (int i = 1; i <= n; i++) {
        if (visit[i] == 0) {
            dfs(i);
            result++;
        }
    }
    cout << result;
}
