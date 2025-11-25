#include <stdio.h>



typedef struct AVLNode{
    int data;
    struct AVLNode *right;
    struct AVLNode *left;
    int height;
}AVLNode;

int height(AVLNode* node) {
    return (node == NULL) ? 0 : node->height;
}
int getBalance(AVLNode* node) {
    return (node == NULL) ? 0 : height(node->left) - height(node->right);
}
int max(int a, int b){
    return (a > b) ? a : b;
}
AVLNode* rightRotate(AVLNode* y){
    AVLNode* x = y->left;
    AVLNode* T2 = x->right;

    x->right = y;
    y->left = T2;

    y->height = 1 + max(height(y->left), height(y->right));
    x->height = 1 + max(height(x->left), height(x->right));

    return x;

}
AVLNode* leftRotate(AVLNode* x){
    AVLNode* y = x->right;
    AVLNode* T2 = y->left;

    y->left = x;
    x->right = T2;

    x->height = 1 + max(height(x->left), height(x->right));
    y->height = 1 + max(height(y->left), height(y->right));

    return y;
}

