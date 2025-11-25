#include <stdio.h>
#include <stdlib.h>



#define TABLE_SIZE 11



typedef struct node{
    int value;
    int key;
    struct node* next;
}node;

typedef struct hashTable{
    node* buckets[TABLE_SIZE];

}hashTable;

node* createNode(int value){
    node* n = malloc(sizeof(node));
    if(!n) return NULL;
    n->next = NULL;
    n->value = value;
    return n;
}
void initHashTable(hashTable** ht){
    *ht = malloc(sizeof(hashTable));
    if(*ht == NULL) return;
    for(int i = 0; i < TABLE_SIZE; i++){
        (*ht)->buckets[i] = NULL;
    }
}
int hash(int key){
    return abs(key) % TABLE_SIZE;
}

void insertAtHead(hashTable* ht, int key, int value){
    int index = hash(key);
    
    node* newNode = createNode(value);
    if(!newNode)return;
    newNode->key = key;

    newNode->next = ht->buckets[index];
    ht->buckets[index] = newNode;

}
void insertAtTail(hashTable* ht, int key, int value){
    int index = hash(key);

    node* newNode = createNode(value);
    if(!newNode)return;

    newNode->key = key;
   
    if(ht->buckets[index] == NULL){
        ht->buckets[index] = newNode;
        return;
    }

    node* current = ht->buckets[index];
    while(current->next != NULL){
        current = current->next;
    }
    current->next = newNode;
}
void delete(hashTable* ht, int key){
    int index = hash(key);
    
    // Check if bucket is empty
    if(ht->buckets[index] == NULL){
        printf("Key %d not found\n", key);
        return;
    }
    
    node* current = ht->buckets[index];
    
    // Case 1: Deleting the first node in the chain
    if(current->key == key){
        ht->buckets[index] = current->next;
        free(current);
        printf("Deleted key %d from bucket %d\n", key, index);
        return;
    }
    
    // Case 2: Deleting from middle or end of chain
    // Traverse until we find the node before the target
    while(current->next != NULL && current->next->key != key){
        current = current->next;
    }
    
    // If we found the key
    if(current->next != NULL){
        node* toDelete = current->next;
        current->next = current->next->next;  // Unlink the node
        free(toDelete);
        printf("Deleted key %d from bucket %d\n", key, index);
    } else {
        printf("Key %d not found in bucket %d\n", key, index);
    }
}
