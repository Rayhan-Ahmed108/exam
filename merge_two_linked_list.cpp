#include<bits/stdc++.h>
using namespace std;

struct Node {
    int n;
    Node* next;
    Node(int n) {
        this -> n = n;
        next = nullptr;
    }  
};
//travarsal
void rec(Node* head) {
    while(head != nullptr) {
        cout << head -> n << ' ';
        head = head -> next;
    }
}
//add 2 linked list
void merge(Node* head2, Node* tail1) {
    if(tail1 != nullptr) {
        tail1 -> next = head2;
    }
}
//insert on specific index and value(0 based index)
void insert(Node*& head, int pos, int val) {
        struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
        newNode->n = val;
        newNode->next = NULL;
        if(pos == 0) {
        newNode->next = head;
        head = newNode;
        return;
    }
    Node* temp = head;
    for(int i = 0; i < pos - 1 && temp != nullptr; i++) {
        temp = temp->next;
    }
    //temp holo je position a add korbo oi position er ager index er pointer
    // cout << temp -> n << "end" << endl;
    if(temp == nullptr) {
        cout << "Position out of bounds!" << endl;
        return;
    }
    newNode->next = temp->next;
    temp->next = newNode;
}

//delete one index(0 based index)
void delete1(Node* &head, int position) {
    if(position == 0) {
        Node* temp = head;
        head = head -> next;
        delete temp;
        return;
    }
    Node* current = head;
    for(int i = 0; i < position - 1 and current != nullptr; i++) {
        current = current -> next;
    }
    if(current == nullptr or current -> next == nullptr) return;
    Node* toDelete = current->next;
    current->next = current->next->next;
    delete toDelete;
}

int main() {
    int n;
    cin >> n;
    Node* head = nullptr;
    Node* tail = nullptr;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->n = x;
        temp->next = NULL;
        // struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        // temp -> n = x;
        // temp -> next = NULL;

        if(head == nullptr) {
            head = temp;
            tail = temp;
        }
        else {
            tail -> next = temp;//previous node er pointer a present node rakse
            tail = tail -> next;//previous node ke present node er link a rakse
        }
    }
    Node* jk = nullptr;
    Node* kj = nullptr;
    int m;
    cin >> m;
    while(m--) {
        int x;
        cin >> x;
        struct Node* temp = (struct Node*)malloc(sizeof(struct Node));
        temp->n = x;
        temp->next = NULL;
        if(jk == nullptr) {
            jk = temp;
            kj = temp;
        }
        else {
            kj -> next = temp;
            kj = kj -> next;
        }
    } 

    cout << endl;
    rec(jk);//2nd linked list run
    cout << endl;
    merge(jk, tail);//merge first and second linked list
    //rec(head);//after merger display first linked list
    //cout << endl;
    insert(head, 3, 100);//add position 3 at value 100
    rec(head);//after add showing display our final linked list
    cout << endl;
    delete1(head, 5);
    rec(head);

    return 0;
}

// #include<bits/stdc++.h>
// using namespace std;
// struct Node {

//     int n;
//     Node* next;
//     Node(int n) {
//         this -> n = n;
//     }

// };

// void travarsal(Node* head) {
//     while(head != nullptr) {
//         cout << head -> n << ' ';
//         head = head -> next;
//     }
// }

// void merge(Node* tail, Node* jk) {
//     if(tail != nullptr) {
//         tail -> next = jk;
        
//     }
// }

// void insert(Node* head, int position, int val) {
//     Node* newNode = new Node(val);
//     if(position == 0) {
//         newNode -> next = head;
//         head = newNode;
//         return;
//     }
//     Node* temp = head;
//     for(int i = 0; i < position - 1 and newNode != nullptr; i++) {
//         temp = temp -> next;
//     }
//     newNode->next = temp->next;
//     temp->next = newNode;
// }
// int main() {

// int n;
// cin >> n;
// Node* head = nullptr;
// Node* tail = nullptr;
// while(n--) {
//     int x;
//     cin >> x;
//     Node* temp = new Node(x);
//     if(head == nullptr) {
//         head = temp;
//         tail = temp;
//     }
//     else {
//         tail -> next = temp;
//         tail = tail -> next;
//     }
// }

// //travarsal(head);
// Node* jk = nullptr;
// Node* kj = nullptr;
// int m;
// cin >> m;
// while(m--) {
//     int x;
//     cin >> x;
//     Node* temp = new Node(x);
//     if(jk == nullptr) {
//         jk = temp;
//         kj = temp;
//     }
//     else {
//         kj -> next = temp;
//         kj = kj -> next;
//     }
// }
// //travarsal(jk);
// cout << endl;
// merge(tail, jk);
// //travarsal(head);

// insert(head, 3, 78);
// travarsal(head);
// }

