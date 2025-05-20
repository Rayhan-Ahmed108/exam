#include<bits/stdc++.h>
using namespace std;
struct Node {
    int n;
    Node* next;
    Node(int n){
        this -> n = n;
    }  
};

void rec(Node* head) {
    while(head != nullptr) {
        cout << head ->n << ' ';
        head = head -> next;
    }
}

int main() {

    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if(head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail -> next = temp;
            tail = tail ->next;
        }
    }
    rec(head);
    Node* jk = nullptr;
    Node* kj = nullptr;
    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        Node* temp = new Node(x);
        if(jk == nullptr) {
            jk = temp;
            kj = temp;
        }
        else {
            
        }
    } 


}