#include <stdio.h>
#include <utils.h>

// [start, end]
// from large to small
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
    clock_t start, end;
    get_timer(&start);
    quick_sort(ar, 0, n-1);
    for(int i=0;i<k;i++)
        result[i] = ar[i];
    get_timer(&end);
    print_duration(&start, &end);
    return k;
}