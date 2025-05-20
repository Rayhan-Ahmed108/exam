#include<bits/stdc++.h>
using namespace std;
char st[100];
int top = -1;

int precedence(char c) {
    if(c == '^') return 3;
    if(c == '*' || c == '/') return 2;
    if(c == '+' || c == '-') return 1;
    return 0;
}

void push(char c) {
    top++;
    st[top] = c;
}

int pop() {
    char c = st[top];
    top--;
    return c;
}

int main() {
string s, result = "";
cin >> s;
for(int i = 0; i < s.size(); i++) {
    char ch = s[i];
    if(isalnum(ch)) {
        result += ch;
    }
    else if(ch == '(') {
        push(ch);
    }
    else if(ch == ')') {
        while(top != -1 && st[top] != '(') {
            result += pop();
        }
        if(top != -1 && st[top] == '(') top--;
    }
    else {
        while(top != -1 && precedence(st[top]) >= precedence(ch)) {
            result += pop();
        }
        push(ch);
    }
}
while(top != -1) {
    result += pop();
}
cout << result << endl;
}
