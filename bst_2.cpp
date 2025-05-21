#include<bits/stdc++.h>
using namespace std;
struct Node
{
    int n;
    Node* left;
    Node* right;
    Node (int n) {
        this -> n = n;
    }
};

//PreOrder
void pre(Node* root) {
    if(root == NULL) return;
    cout << root -> n << ' ';
    pre(root -> left);
    pre(root -> right);

}
//in
void in(Node* root) {
    if(root == NULL) return;
    in(root -> left);
    cout << root -> n << ' ';
    in(root -> right);
}
//post
void post(Node* root) {
    if(root == NULL) return;
    post(root -> left);
    post(root -> right);
    cout << root -> n << ' ';
}

//implement bst
Node* rec(Node* root, int x) {
    if(root == NULL) return new Node(x);
    if(x < root -> n) {
        root -> left = rec(root -> left, x);
    }
    else {
        root -> right = rec(root -> right, x);
    }
    return root;    
}

int main() {
    int n;
    cin >> n;
    Node* root = NULL;
    while(n--) {
        int x;
        cin >> x;
        root = rec(root, x);
    }
    pre(root);
    cout << endl;
    in(root);
    cout << endl;
    post(root);
    cout << endl;

}