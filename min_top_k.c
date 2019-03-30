//
// Created by ZHANG Bowen on 2019-03-30.
//

#include <utils.h>
#include <heap.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>

int min_top_k(int *ar, int n, int k, int *result){
    int* arNeg = (int*)malloc(sizeof(int)*n);
    for(int i=0;i<n;i++){
        arNeg[i] = -ar[i];
    }
    clock_t start, end;
    get_timer(&start);
    MaxHeap hp;
    initHeap(k, &hp);
    buildHeapFromArray(arNeg, k, &hp);
    for(int i=k;i<n;i++){
        int topElem;
        top(&hp, &topElem);
        if(arNeg[i] < topElem){
            int temp;
            pop(&hp, &temp);
            push(&hp, arNeg[i]);
        }
    }
    for(int i=k-1;i>=0;i--){
        int temp;
        pop(&hp, &temp);
        result[i] = -temp;
    }
    get_timer(&end);
    print_duration(&start, &end);
    free(arNeg);
    freeHeap(&hp);
    return 0;
}

//int main(){
//    int a[100];
//    int b[7] = {100000000, 98495853, 94358294, 43434632,87583682, 43589694, 3};
//    read_input(a, 93);
//    for(int i=0;i<93;i++){
//        printf("%d\n", a[i]);
//    }
//    int result[10];
//    min_top_k(a, 93, 10, result);
//    for(int i=0;i<10;i++){
//        printf("%d\n", result[i]);
//    }
//    return 0;
//}