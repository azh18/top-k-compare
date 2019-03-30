#include <heap.h>
#include <utils.h>
#include <string.h>
#include <stdlib.h>
#include <stdio.h>

int initHeap(int maxSize, MaxHeap *heap){
    if(heap == NULL){
        return -1;
    }
    int *p = (int*)malloc(sizeof(int)*maxSize);
    if(p != NULL)
    {
        heap->data = p;
        heap->maxSize = maxSize;
        heap->nowSize = 0;
        return maxSize;
    } else {
        return -1;
    }
}

int buildHeapFromArray(int *a, int length, MaxHeap *heap){
    if(heap == NULL){
        return -1;
    }
    if(heap->maxSize < length){
        return -1;
    }
    memcpy(heap->data, a, length * sizeof(int));
    heap->nowSize = length;
    heapify(heap);
    return 0;
}

void heapify(MaxHeap *heap){
    int size = heap->nowSize;
    for(int i=size-1;i>=0;i--){
        bool needSwap = false;
        if((i-1)/2 >= 0 && heap->data[i] > heap->data[(i-1)/2])
            needSwap = true;
        if(needSwap){
            swap(heap->data, i, (i-1)/2);
            down(heap, i);
        }
    }
}

void up(MaxHeap *heap, int i){
    while(i>0){
        if(((i-1)/2 >= 0) && (heap->data[i] > heap->data[(i-1)/2])){
            swap(heap->data, i, (i-1)/2);
            i = (i-1)/2;
        } else {
            break;
        }
    }
}

void down(MaxHeap *heap, int i){
    int size = heap->nowSize;
    while(i<=size/2){
        bool swapDirection = 0; // false = left, true = right
        bool needSwap = false;
        if((i*2+1 < size) && (i*2+2 < size)){
            if(heap->data[i*2+1] >= heap->data[i*2+2] && heap->data[i*2+1] > heap->data[i]){
                swapDirection = false;
                needSwap = true;
            } else if(heap->data[i*2+1] <= heap->data[i*2+2] && heap->data[i*2+2] > heap->data[i]){
                swapDirection = true;
                needSwap = true;
            }
        } else {
            if((i*2+1 < size) && (heap->data[i] < heap->data[i*2+1])){
                needSwap = true;
                swapDirection = false;
            } else if(i*2+2 < size && heap->data[i] < heap->data[i*2+2]){
                needSwap = true;
                swapDirection = true;
            }
        }
        if(needSwap){
            if(!swapDirection){
                swap(heap->data, i, i*2+1);
                i = i*2+1;
            } else {
                swap(heap->data, i, i*2+2);
                i = i*2+2;
            }
        } else {
            break;
        }
    }
}

int push(MaxHeap *heap, int elem){
    if(heap->maxSize == heap->nowSize){
        return -1;
    }
    heap->data[heap->nowSize++] = elem;
    up(heap, heap->nowSize-1);
    return 0;
}

int pop(MaxHeap *heap, int *elem){
    if(heap->nowSize == 0){
        return -1;
    }
    *elem = heap->data[0];
    heap->data[0] = heap->data[--heap->nowSize];
    down(heap, 0);
    return 0;
}

int top(MaxHeap *heap, int *elem){
    if(heap->nowSize > 0){
        *elem = heap->data[0];
        return 0;
    } else {
        return 1;
    }
}

bool isEmpty(MaxHeap *heap){
    if(heap->nowSize == 0 && heap->nowSize < heap->maxSize){
        return true;
    }
    return false;
}

bool isFull(MaxHeap *heap){
    if(heap->nowSize >= heap->maxSize)
        return true;
    return false;
}

void freeHeap(MaxHeap *heap){
    free(heap->data);
}


//int main(){
//    int a[100];
//    int b[7] = {100000000, 98495853, 94358294, 43434632,87583682, 43589694, 3};
//    read_input(a, 93);
//    MaxHeap hp;
//    int buildRet = -1;
//    if(initHeap(100, &hp, true) >= 0){
//        buildRet = buildHeapFromArray(a, 93, &hp);
//    }
//    if(buildRet < 0){
//        printf("build heap failed. ret=%d\n", buildRet);
//        return -1;
//    }
//    for(int i=0;i<7;i++){
//        push(&hp, b[i]);
//    }
//    while(hp.nowSize > 0){
//        int temp;
//        pop(&hp, &temp);
//        printf("%d\n", temp);
//    }
//    return 0;
//}