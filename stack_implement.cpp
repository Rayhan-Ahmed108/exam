#include<stdio.h>

int stack[100];
int top = -1;

void push(int x) {
    if(top != 100) {
        top++;
        stack[top] = x;
    }
}
int pop() {
    return stack[top--];

}

int main() {
push(10);
push(10);
push(10);
push(40);
printf("%d", pop());

}