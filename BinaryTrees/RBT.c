#include <stdio.h>


typedef enum Color{
    red, black
}Color;

typedef struct Node{
    int data;
    struct Node* left;
    struct Node* right;
    Color color;
}Node;


