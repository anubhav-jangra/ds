#include <iostream>
#include <queue>
#include <algorithm>
using namespace std;

struct node {
    int data;
    struct node *left;
    struct node *right;
    int ht;
}; 

node *newNode(int val) {
    node *n  = new node;
    n->data  = val;
    n->left  = nullptr;
    n->right = nullptr;
    n->ht    = 0;
    return n;
}

int height(node *root) {
    if(!root)
        return -1;
    return max( height(root->left), height(root->right) ) + 1;
}

node *leftRotate(node *x) {
    node *y  = x -> right;
    node *T2 = y -> left;

    y -> left  = x;
    x -> right = T2;

    y -> ht = height(y);
    x -> ht = height(x);
    return y;
}

node * rightRotate(node *y) {
    node * x  = y -> left;
    node * T2 = x -> right;

    x -> right = y;
    y -> left  = T2;

    y -> ht = height(y);
    x -> ht = height(x);
    return x;
}

int getBalance(node *root) {
    if(!root)
        return 0;
    return height(root -> left) - height(root -> right);
}

node *insert(node *root, int key) {
    if(!root)
        return newNode(key);
    if(root -> data > key)
        root -> left = insert(root->left, key);
    else if(root -> data < key)
        root -> right = insert(root->right, key);
    else                                        // bst dosn't allow repetition
        return root;

    root->ht = height(root);
    int balance = getBalance(root);
    // left left
    if(balance > 1 && root -> left -> data > key)
        return rightRotate(root);
    // right right 
    if(balance < -1 && root -> right -> data < key)
        return leftRotate(root);
    // left right 
    if(balance > 1 && root -> left ->data < key) {
        root -> left = leftRotate(root->left);
        return rightRotate(root);
    }
    // right left
    if(balance < -1 && root -> left -> data > key) {
        root -> right = rightRotate(root->right);
        return leftRotate(root);
    }
    return root;
}

#define COUNT 10
void print(node *root, int space = 0)
{
    if (root == NULL)
        return;
    space += COUNT;
    print(root->right, space);
    printf("\n");
    for (int i = COUNT; i < space; i++)
        printf(" ");
    printf("%d(%d)\n", root->data, root->ht);
    print(root->left, space);
}

int main()
{
    vector<int> que = {14, 25, 21, 10, 23, 7, 26, 12, 30, 16};
    node *root = nullptr;
    while(!que.empty()) {
        root = insert(root, que.back());
        que.pop_back();
    }
    print(root);
    return 0;
}
