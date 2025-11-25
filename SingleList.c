#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    int data;
    struct Node* next;
}Node;

Node* createNode(int data){
    Node *n = malloc(sizeof(Node));
    if(!n)return NULL;

    n->data = data;
    n->next = NULL;
    return n;
}

void append(Node** root, int value){
    Node* n = createNode(value);
    if(!n) return;
    if(*root == NULL){
        *root = n;
        return;
    }
    Node* current = *root;
    while(current->next != NULL){
        current = current->next;
    }
    current->next = n;

}
void prePend(Node** root, int value){
    Node* n = createNode(value);
    if(!n)return; 
    if(*root == NULL){
        *root = n;
        return;
    }
    n->next = *root;
    *root = n;


}
void delete(Node** root, int data){
    if(*root == NULL){
        return;
    }
    
    // Handle deletion of root node
    if((*root)->data == data){
        Node* temp = *root;
        *root = (*root)->next;
        free(temp);
        return;
    }
    
    // Find the node before the one to delete
    Node* current = *root;
    while(current->next != NULL && current->next->data != data){
        current = current->next;
    }
    
    // If we found the node, delete it
    if(current->next != NULL){
        Node* temp = current->next;
        current->next = current->next->next;
        free(temp);
    }
}
void print(Node** root){
    Node* current = *root;
    if(*root == NULL){
        return;
    }

    while(current != NULL){
        printf(" %d ", current->data);
        current = current->next;
    }
}
int main(){
    Node* root = NULL;

    append(&root, 5);
    append(&root, 4);
    append(&root, 55);
    append(&root, 6);
    append(&root, 1);
    append(&root, 2);
    delete(&root, 2);
    delete(&root, 5);
    print(&root);


}