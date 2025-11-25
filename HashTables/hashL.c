#include <stdio.h>
#include <stdlib.h>

#define TABLE_SIZE 101

// Linear probing hash table implementation

typedef enum{
    EMPTY_SINCE_START,
    EMPTY_SINCE_REMOVAL,
    OCCUPIED
}State;

typedef struct bucket{
    int value;
    int key;
    State state;
}bucket;

typedef struct hashTable{
    bucket table[TABLE_SIZE];
}hashTable;

int hash(int key){
    return abs(key) % TABLE_SIZE;
}

void insert(hashTable* ht, int key, int value){
    int index = hash(key);
    int ogIndex = index;
    while(ht->table[index].state == OCCUPIED){
        if(ht->table[index]. value == value){
            printf("value already stored in table");
            return;
        }
        index = (index + 1) % TABLE_SIZE;
        
        if(index == ogIndex){
        printf("no space in the table");
        return;
        }

    }

    ht->table[index].value = value;
    ht->table[index].state = OCCUPIED;
    ht->table[index].key = key;
}

void delete(hashTable* ht, int key){
    int index = hash(key);

    for(int i = 0; i < TABLE_SIZE; i++){
        int bucketindex = (index + i) % TABLE_SIZE;
        if(ht->table[bucketindex].state == EMPTY_SINCE_START){
            printf("item is not in table");
            return;
        }else{
            if(ht->table[bucketindex].state == OCCUPIED && ht->table[bucketindex].key == key){
                ht->table[bucketindex].state = EMPTY_SINCE_REMOVAL;
                printf("item deleted from table\n");
                return;
            }
        }
    }

}