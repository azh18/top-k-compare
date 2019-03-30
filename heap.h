#ifndef _HEAP_H
#define _HEAP_H

#include <stdbool.h>

typedef struct MaxHeap{
    int nowSize;
    int maxSize;
    int *data;
}MaxHeap;


int initHeap(int maxSize, MaxHeap *heap);
int buildHeapFromArray(int *a, int length, MaxHeap *heap);
void heapify(MaxHeap *heap);
void up(MaxHeap *heap, int i);
void down(MaxHeap *heap, int i);
int push(MaxHeap *heap, int elem);
int pop(MaxHeap *heap, int *elem);
int top(MaxHeap *heap, int *elem);
void freeHeap(MaxHeap *heap);
bool isEmpty(MaxHeap *heap);
bool isFull(MaxHeap *heap);

#endif