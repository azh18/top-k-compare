//
// Created by ZHANG Bowen on 2019-03-30.
//

#include <utils.h>
#include <stdio.h>
#include <linear_top_k.h>
#include <stdlib.h>
#include <string.h>

int linear_top_k(int *ar, int n, int k, int *result){
    int* cpy_ar = (int*)malloc(sizeof(int)*n);
    memcpy(cpy_ar, ar, n*sizeof(int));
    clock_t start, end;
    get_timer(&start);
    find_top_k(cpy_ar, 0, n-1, k);
    for(int i=0;i<k;i++){
        result[i] = cpy_ar[i];
    }
    get_timer(&end);
    print_duration(&start, &end);
    free(cpy_ar);
    return 0;
}

// 递归拆循环
int find_top_k(int *ar, int start, int end, int k){
//    while(1) {
        // printf("start = %d, end = %d, k = %d\n", start, end, k);
        int si = start;
        int ei = end - 1;
        int mark = end;
        while (si < ei) {
            if (ar[si] < ar[mark]) {
                swap(ar, si, ei);
                ei -= 1;
            } else {
                si += 1;
            }
        }
        swap(ar, si, mark);
        if (si - start == k - 1) {
            return si;
        } else if (si - start < k - 1) {
            int new_k = k - 1 - (si - start);
            return find_top_k(ar, si + 1, end, new_k);
//            k = new_k;
//            start = si + 1;
        } else {
            return find_top_k(ar, start, si - 1, k);
//            end = si - 1;
        }
//    }
}

//int main(){
//    int a[100];
//    int b[7] = {100000000, 98495853, 94358294, 43434632,87583682, 43589694, 3};
//    read_input(a, 93);
//    int result[10];
//    linear_top_k(a, 93, 10, result);
//    for(int i=0;i<10;i++){
//        printf("%d\n", result[i]);
//    }
//    return 0;
//}