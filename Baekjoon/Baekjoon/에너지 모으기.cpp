#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int n;
int Max;
vector<int> v;

void backTracking(int sum) {
    if (v.size()==2) {
        Max = max(Max, sum);
        return; 
    }
    else {
        for (int i = 1; i < v.size() - 1; i++) {
            int x = v[i];
            int mul = v[i - 1] * v[i + 1];
            v.erase(v.begin() + i);
            backTracking(sum+mul);
            v.insert(v.begin() + i, x); 
        }
    }
}

int main() {
    cin >> n;
    for (int i = 0; i < n; i++) {
        int a;
        cin >> a;
        v.push_back(a);
    }

    backTracking(0);

    cout << Max << '\n';
    return 0;
}
