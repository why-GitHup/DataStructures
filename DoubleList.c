#include <stdio.h>
#include <stdlib.h>


typedef struct Node{
    struct Node *next;
    struct Node *prev;
    int data;
}Node;

Node* createNode(int value){
    Node* newNode = malloc(sizeof(Node));
    if(!newNode)return NULL;

    newNode->next = NULL;
    newNode->prev = NULL;
    newNode->data = value;
    
    return newNode;
}

void insertAtBeginning(Node** root, int value){
    Node* n = createNode(value);
    if(!n) return;

    if(*root == NULL){
        *root = n;
        return;
    };

    n->next = *root;
    (*root)->prev = n;
    *root = n;

}

void insertAtEnd(Node** root, int value){
    Node *n = createNode(value);
    if(!n)return;
    if(*root == NULL){
        *root = n;
        return;
    }
    Node* temp = *root;
    while(temp->next != NULL){
        temp = temp->next;
    }
    n->prev = temp;
    temp->next = n;
    n->next = NULL;
}

void insert(Node** root, int data, int index){
    Node *n = createNode(data);
    if(!n)return;

    Node* temp = *root;
    if(index == 0){
        n->next = *root;
        (*root)->prev = n;
        n->prev = NULL;
        *root = n;
        return;
    }

    for(int i = 0; i < index - 1; i++){
        if(temp != NULL){
            temp = temp->next;
        }else{
            return;
        }
        
    }
    n->prev = temp;
    n->next = temp->next;
    temp->next = n;
    if(n->next != NULL){
        n->next->prev = n;
    }
}
void delete(Node** root, int data){
    Node* temp = *root;
    if(*root == NULL)return;

    if((*root)->data == data){
        *root = (*root)->next;
        if(*root != NULL){
            (*root)->prev = NULL;
        }
        free(temp);
        return;
    }

    while(temp->next != NULL && temp->next->data != data ){
        temp = temp->next;
    }
    if(temp->next == NULL && temp->data != data){
        return;
    }
    if(temp->next->next != NULL){
        Node* toDelete = temp->next;
        temp->next = temp->next->next;
        temp->next->prev = temp;
        free(toDelete);
    }else{
        Node* toDelete = temp->next;
        temp->next = NULL;
        free(toDelete);
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

    insertAtBeginning(&root, 3);
    insertAtBeginning(&root, 4);
    insertAtBeginning(&root, 5);
    insertAtBeginning(&root, 6);
    insertAtBeginning(&root, 7);

    insert(&root, 5, 2);
    delete(&root, 5);
    delete(&root, 1);

    print(&root);
}