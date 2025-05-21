#include<bits/stdc++.h>
using namespace std;

char st[100];
int top = -1;

int pre(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void push(char c) {
    st[++top] = c;
}

char pop() {
    return st[top--];
}

int main() {
    string s, res = "";
    cin >> s;

    // reverse(s.begin(), s.end());

    // for(int i = 0; i < s.size(); i++) {
    //     if(s[i] == '(') s[i] = ')';
    //     else if(s[i] == ')') s[i] = '(';
    // }

    for(int i = 0; i < s.size(); i++) {
        char c = s[i];

        if(isalnum(c)) {
            res += c;
        }
        else if(c == '(') {
            push(c);
        }
        else if(c == ')') {
            while(top != -1 && st[top] != '(') {
                res += pop();
            }
            if(top != -1) top--; 
        }
        else {
            while(top != -1 && 
                 ((pre(st[top]) > pre(c)) || 
                 (pre(st[top]) == pre(c) && c != '^'))) {
                res += pop();
            }
            push(c);
        }
    }

    while(top != -1) res += pop();

    //reverse(res.begin(), res.end());
    cout << res << endl;
}
