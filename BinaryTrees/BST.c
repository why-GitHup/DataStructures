#include <stdio.h>
#include <stdlib.h>

typedef struct treeNode{
    int data;
    struct treeNode* left;
    struct treeNode* right;
}treeNode;

treeNode* createNode(int data){
    treeNode* n = malloc(sizeof(treeNode));
    if(!n) return NULL;
    n->data = data;
    n->left = NULL;
    n->right = NULL;

    return n;
}

void insert(treeNode** root, int data){
    treeNode* n = createNode(data);
    if(!n)return;

    if(*root == NULL){
        *root = n;
        return;
    }
    if( data < (*root)->data ){
        insert(&((*root)->left), data);
    }else{
        insert(&((*root)->right), data);
    }
}
void search(treeNode** root, int data){
    if(*root == NULL)return;
    if(data == (*root)->data){
        printf("%d is found in the tree", data);
        return;
    }
   if( data < (*root)->data ){
        search(&((*root)->left), data);
    }else{
        search(&((*root)->right), data);
    }
}
void Deletion(treeNode** root, int data){
    if(*root == NULL) return;
    
    if(data == (*root)->data){
        // Case 1: Leaf node (no children)
        if((*root)->right == NULL && (*root)->left == NULL){
            free(*root);
            *root = NULL;
            return;
        }
        // Case 2: Only left child
        else if ((*root)->left != NULL && (*root)->right == NULL)
        {
            treeNode* temp = *root;
            *root = (*root)->left;
            free(temp);
            return;
        }
        // Case 3: Only right child
        else if((*root)->left == NULL && (*root)->right != NULL){
            treeNode* temp = *root;
            *root = (*root)->right;
            free(temp);
            return;
        }
        // Case 4: Two children - use inorder successor
        else{
            // Find the inorder successor (leftmost node in right subtree)
            treeNode* successor = (*root)->right;
            while(successor->left != NULL){
                successor = successor->left;
            }
            // Copy successor's data to current node
            (*root)->data = successor->data;
            // Delete the successor from right subtree
            Deletion(&((*root)->right), successor->data);
        }
    }
    // Traverse to find the node to delete
    else if(data < (*root)->data){
        Deletion(&((*root)->left), data);
    }
    else{
        Deletion(&((*root)->right), data);
    }
}

void inOrder(treeNode* root){
    if(root == NULL)return;
        inOrder(root->left);
        printf(" %d ", root->data);
        inOrder(root->right);
    
}
void preOrder(treeNode* root){
    if(root == NULL )return;
    printf(" %d ", root->data);
    preOrder(root->left);
    preOrder(root->right);
}
void postOrder(treeNode* root){
    if(root == NULL) return;
    postOrder(root->left);
    postOrder(root->right);
    printf(" %d ", root->data);
}
