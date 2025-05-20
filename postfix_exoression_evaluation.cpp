#include<bits/stdc++.h>
using namespace std;
int st[100];
int top = -1;

void push(int x) {
    top++;
    st[top] = x;
}

int pop() {
    int c = st[top];
    top--;
    return c;
}
 
int main() {
string s;
getline(cin, s);
for(int i = 0; i < s.size(); i++) {
    if(s[i] == ' ') continue;
    if(s[i] == '+' or s[i] == '-' or s[i] == '*' or s[i] == '/') {
        int ans = pop(), ans1 = pop();
        if(s[i] == '+') {
            push(ans + ans1);
        }
        else if(s[i] == '-') {
            push(ans1 - ans);
        }
        else if(s[i] == '*') {
            push(ans * ans1);
        }
       else if(s[i] == '/') {
            push(ans1 / ans);
        }
    }
        else {
            string s1 = "";
            while(isalnum(s[i])) {
            s1 += s[i];
            i++;
            }
            int sum = 0, k = 1;
            for(int j = s1.size() - 1; j >= 0; j--) {
            sum += (s1[j] - '0') * k;
            k *= 10;
        }
            push(sum);
        }
    }
    cout << pop();
}
