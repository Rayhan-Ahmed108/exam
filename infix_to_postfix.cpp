#include<bits/stdc++.h>
using namespace std;

int prec(char c) {
    if (c == '^')
        return 3;
    else if (c == '/' || c == '*')
        return 2;
    else if (c == '+' || c == '-')
        return 1;
    else
        return -1;
}

int main() {
    stack<char> st;
    string s, result;
    getline(cin, s);
    for(int i = 0; i < s.size(); i++) {
        if(isalnum(s[i])) {
            result += s[i];
        }
        else if(s[i] == '(') {
            st.push(s[i]);
        }
        else if(s[i] == ')') {
    while(!st.empty() && st.top() != '(') {
        result += st.top();
        st.pop();
    }
    if (!st.empty()) st.pop();
    }
        else {
            while (!st.empty()) {
                char top = st.top();
                //boror opore choto thakte parbo na
                //boro ber hobe then choto dukbe
                if (prec(s[i]) < prec(top) || (prec(s[i]) == prec(top) && s[i] != '^')) {
                    result += top;
                    st.pop();
                } else {
                    break;
                }
            }
            st.push(s[i]);
        }
    }
    while (!st.empty()) {
        result += st.top();
        st.pop();
    }
    cout << result << endl;
}