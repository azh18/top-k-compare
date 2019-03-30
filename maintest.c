#include <brute_force_top_k.h>
#include <linear_top_k.h>
#include <max_top_k.h>
#include <min_top_k.h>

#include <utils.h>
#include <stdio.h>
#include <stdlib.h>


int main(){
    int *bigData, *medData, *smaData;
    int bigN = 10000000, medN, smallN;
    int bigKSc, medKSc, smallKSc;

    int *result = (int*)malloc(sizeof(int)*bigN);
    bigData = (int*)malloc(sizeof(int)*bigN);

    int k = 100;
    int n = 10000;
    read_input(bigData, n);
    quick_sort(bigData, 0, n-1);
    printf("linear method O(n):\n");
    linear_top_k(bigData, n, k, result);
    printf("max heap method O(n + klog(n)):\n");
    max_top_k(bigData, n, k, result);
    printf("min heap method O(k + nlog(k)):\n");
    min_top_k(bigData, n, k, result);
    printf("brute force method O(nlog(n)):\n");
    b_top_k(bigData, n, k, result);
    return 0;

    // on almost sorted:

    // test 1: bigN, bigK

    // test 2: bigN, medium k

    // test 3: bigN, small k

    // test 4: medium N, big k

    // test 5: medium N, small k

    // test 6: small N, big k

    // test 7: small N, small k

    // on almost unsorted:

    // ...
}