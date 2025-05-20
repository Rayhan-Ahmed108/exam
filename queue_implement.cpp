#include<bits/stdc++.h>
using namespace std;
int que[100];
int top = -1, inde = -1;

void push(int x) {
    if(inde < 100) {
        inde++;
        que[inde] = x;
    }
}

int pop() {
    if(inde != -1) {
        top++;
        return que[top];
    }
}

int main() {
push(100);
push(230);
push(1230);
push(23);
// cout << pop() << endl;
// cout << pop();
push(70);
pop();
cout << pop() << endl;
}