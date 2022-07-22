#include <bits/stdc++.h>

using namespace std;

int main() {
    ios::sync_with_stdio(0);
    cin.tie(0);

    string str;

    while (1) {
        getline(cin, str);
 
        if (str.size() == 1 && str[0] == '.') { //end
            break; 
        }
        stack<char> st;
        for (int i = 0; i < str.size(); i++) {
            if (str[i] == '[') {
                st.push('['); 
            }
            else if (str[i] == ']') {
                if (!st.empty() && st.top() == '[') {
                    st.pop(); 
                }
                else {
                    st.push(']');
                }
            }
            else if (str[i] == '(') {
                st.push('(');
            }
            else if (str[i] == ')') {
                if (!st.empty() && st.top() == '(') {
                    st.pop();
                }
                else {
                    st.push(')'); 
                }
            }
        }

        if (st.empty()) {
            cout << "yes" << '\n';
        }
        else {
            cout << "no" << '\n';
        }
    }

    return 0; 
}
