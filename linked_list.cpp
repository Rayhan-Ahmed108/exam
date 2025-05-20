#include<bits/stdc++.h>
using namespace std;
struct Node {
    int n;
    Node* next;
    Node(int n) {
        this -> n = n;
    }
};

void rec(Node* head) {
    while(head != nullptr) {
        cout << head -> n << ' ';
        head = head -> next;
    }
}

int main() {

    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    while(n--) {
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if(head == nullptr) {
            head = temp;
            tail = head;
        }
        else {
            tail -> next = temp;
            tail = tail -> next;
        }
    }
    rec(head);
    return 0;
}


