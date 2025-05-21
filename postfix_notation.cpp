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
    cin >> s;  
    int a, b, c;
    cin >> a >> b >> c;

    for (int i = 0; i < s.size(); i++) {
        if (s[i] == 'a') push(a);
        else if (s[i] == 'b') push(b);
        else if (s[i] == 'c') push(c);
        else if(isdigit(s[i]))push(s[i] - '0');
        else {
            int val2 = pop(); 
            int val1 = pop(); 
            if (s[i] == '+') push(val1 + val2);
            else if (s[i] == '-') push(val1 - val2);
            else if (s[i] == '*') push(val1 * val2);
            else if (s[i] == '/') push(val1 / val2);
            else if (s[i] == '^') push(pow(val1, val2));
        }
    }

    cout << pop() << endl;
    return 0;
}
