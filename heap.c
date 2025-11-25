#include<stdio.h>

#define MaxSize 100 



typedef struct heap{
    int data[MaxSize];   
    int size;
}heap;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}
heap initHeap(heap* heap){
    heap->size = 0;
}
void heapifyUp(heap *heap, int index){

    while(index > 0){
        int parentIndex = (index - 1)/2;
        if(heap->data[index] <= heap->data[parentIndex] ){
            return;
        }else{
            swap(&(heap->data[index]), &(heap->data[parentIndex]));
            index = parentIndex;
        }
    }
}
void insert(heap* heap, int data){
    if(heap->size >= MaxSize){
        return;
    }

    heap->data[heap->size] = data;
    heap->size++;
    
    heapifyUp(heap, heap->size -1);
}