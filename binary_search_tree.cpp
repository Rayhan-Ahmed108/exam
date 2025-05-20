#include<bits/stdc++.h>
using namespace std;
struct bst
{
    int val;
    bst *left, *right;
    bst(int x) : val(x), left(NULL), right(NULL) {}
};

void pre(bst * root) {
    if(root == NULL) return;
    cout << root->val << ' ';
    pre(root->left);
    pre(root->right);
}

void in(bst *root) {
    if (root == NULL) return;
    in(root->left);          
    cout << root->val << " ";     
    in(root->right);  
}

// Postorder Traversal: Left → Right → Root
void postorder(bst* root) {
    if (root == NULL) return;
    postorder(root->left);
    postorder(root->right);
    cout << root->val << " ";
}

bst* rec(bst* root, int x){
    if(root == NULL) return new bst(x);
    if(x < root->val){
        root->left = rec(root->left, x);
    }
    else {
        root->right = rec(root->right, x);
    }
    return root;

}

int main() {
    int n;
    cin >> n;
    bst* root = NULL;
    for(int i = 0; i < n; i++) {
        int x;
        cin >> x;
        root = rec(root, x);
    }
    cout << "Preorder: ";
    pre(root);
    cout << endl;

    cout << "Inorder: ";
    in(root);
    cout << endl;

    cout << "PostOrder: ";
    postorder(root);
}