#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);
    string str;
    cin >> str;
    int ans = 0; 
    stack<char> st; 

    for (int i = 0; i < str.size(); i++) {
        if (str[i] == '(' && str[i + 1] == ')') { //레이저
            ans += st.size(); 
            i++; 
        }
        else if (str[i] == '(') {
            st.push('(');
            ans++; 
        }
        else { // ')' 
            if (!st.empty() && st.top() == '(') {
                st.pop(); 
            }
        }
    }

    cout << ans << '\n'; 
    return 0; 
}
