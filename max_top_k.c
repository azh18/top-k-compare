//
// Created by ZHANG Bowen on 2019-03-30.
//

#include <stdio.h>
#include <utils.h>
#include <heap.h>

int max_top_k(int *ar, int n, int k, int *result){
    clock_t start, end;
    get_timer(&start);
    MaxHeap hp;
    initHeap(n, &hp);
    buildHeapFromArray(ar, n, &hp);
    for(int i=0;i<k;i++){
        pop(&hp, &result[i]);
    }
    get_timer(&end);
    print_duration(&start, &end);
    freeHeap(&hp);
    return 0;
}