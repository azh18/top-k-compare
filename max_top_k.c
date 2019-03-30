//
// Created by ZHANG Bowen on 2019-03-30.
//

#include <stdio.h>
#include <utils.h>
#include <heap.h>
#include <stdlib.h>
#include <string.h>

int max_top_k(int *ar, int n, int k, int *result){
    int* cpy_ar = (int*)malloc(sizeof(int)*n);
    memcpy(cpy_ar, ar, n*sizeof(int));
    clock_t start, end;
    get_timer(&start);
    MaxHeap hp;
    initHeap(n, &hp);
    buildHeapFromArray(cpy_ar, n, &hp);
    for(int i=0;i<k;i++){
        pop(&hp, &result[i]);
    }
    get_timer(&end);
    print_duration(&start, &end);
    freeHeap(&hp);
    free(cpy_ar);
    return 0;
}