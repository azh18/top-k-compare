#include <stdio.h>
#include <utils.h>
#include <stdlib.h>
#include <string.h>

// [start, end]
// from large to small
// todo: 递归拆循环
void quick_sort(int *ar, int start, int end){
    if(start >= end)
        return;
    int ei = end - 1;
    int si = start;
    int target = ar[end];
    while(si<=ei){
        if(ar[si] >= target){
            si++;
        } else{
            swap(ar, si, ei);
            ei--;
        }
    }
    swap(ar, si, end);
    quick_sort(ar, start, si-1);
    quick_sort(ar, si+1, end);
    return;
}

int b_top_k(int *ar, int n, int k, int *result){
    int* cpy_ar = (int*)malloc(sizeof(int)*n);
    memcpy(cpy_ar, ar, n*sizeof(int));
    clock_t start, end;
    get_timer(&start);
    quick_sort(cpy_ar, 0, n-1);
    for(int i=0;i<k;i++)
        result[i] = cpy_ar[i];
    get_timer(&end);
    print_duration(&start, &end);
    free(cpy_ar);
    return k;
}