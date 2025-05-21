#include<bits/stdc++.h>
using namespace std;
struct Node {
int n;
Node* next;
Node(int n) {
    this -> n = n;
}
};

void travarse(Node* head) {
    while(head != nullptr) {
        cout << head -> n << ' ';
        head = head -> next;
    }
}

void merge(Node* tail, Node* jk) {
    tail -> next = jk;
}

void insert(Node* &head, int index, int value) {
    Node* newNode = new Node(value);
    if(index == 0) {
        newNode -> next = head;
        head = newNode;-
        return;
    }
    Node* temp = head;
    for(int i = 0; i < index - 1 and temp != nullptr; i++) {
        temp = temp -> next;
    }
    newNode -> next = temp -> next;
    temp -> next = newNode;
}

void cut(Node* head, int pos) {
    if(pos == 0) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    Node* temp = head;
    for(int i = 0; i < pos - 1 and temp != nullptr; i++) {
        temp = temp -> next;
    }
    if(temp == nullptr or temp -> next == nullptr) return;
    Node* toDelete = temp->next;
    temp->next = temp->next->next;
    delete toDelete;
}


int  main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    while(n--) {
        int x;
        cin >> x;
        // Node* temp = new Node(x);
        struct Node* temp = (struct Node*) malloc(sizeof(struct Node));
        temp -> n = x;
        temp -> next = NULL;
        
        if(head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail -> next = temp;
            tail = tail -> next;
        }
    }
    //travarse(head);
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
            kj -> next = temp;
            kj = kj -> next;
        }
    }
    //travarse(jk);

    merge(tail, jk);
    //travarse(head);

    insert(head, 6, 800);
    cut(head, 6);
    travarse(head);

}