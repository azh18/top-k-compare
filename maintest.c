#include <brute_force_top_k.h>
#include <linear_top_k.h>
#include <max_top_k.h>
#include <min_top_k.h>

#include <utils.h>
#include <stdio.h>
#include <stdlib.h>

void run_test_round(int *ar, int n, int k, int *result){
    printf("linear method O(n):\n");
    linear_top_k(ar, n, k, result);
    printf("max heap method O(n + klog(n)):\n");
    max_top_k(ar, n, k, result);
    printf("min heap method O(k + nlog(k)):\n");
    min_top_k(ar, n, k, result);
    printf("brute force method O(nlog(n)):\n");
    b_top_k(ar, n, k, result);
}


int main(){
    int *bigData;
    int bigN = 1000000, medN=10000, smallN=100;
    int bigKSc = 100000, medKSc = 1000, smallKSc = 10;

    int *result = (int*)malloc(sizeof(int)*bigN);
    bigData = (int*)malloc(sizeof(int)*bigN);

    int k = 100;
    int n = 10000;
    read_input(bigData, bigN);

    // quick_sort(bigData, 0, n-1);

    // on almost non-sorted:

    // test 1: bigN, bigK
    printf("bigN, bigK: \n");
    run_test_round(bigData, bigN, bigKSc, result);

    // test 2: bigN, medium k
    printf("bigN, medium k: \n");
    run_test_round(bigData, bigN, medKSc, result);

    // test 3: bigN, small k
    printf("bigN, small k: \n");
    run_test_round(bigData, bigN, smallKSc, result);

    // test 4: medium N, medium k
    printf("medium N, medium k: \n");
    run_test_round(bigData, medN, medKSc , result);

    // test 5: medium N, small k
    printf("medium N, small k\n");
    run_test_round(bigData, medN, smallKSc, result);

    // test 7: small N, small k
    printf("small N, small k\n");
    run_test_round(bigData, smallN, smallKSc, result);

    // on almost unsorted:
    return 0;

    // ...
}