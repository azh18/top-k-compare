# top-k-compare

A practical test to compare the efficient of different top-k selection algorithm based on the non-sorted array. 
The aim of this test is to find the real efficiency of different algorithms under different parameters (i.e. the length of array `N` and value `k`).

## Problem Formulation

Given a non-sorted length-`n` integer array `A`, we want to know the top `k` largest elements from `A`.

## Algorithms

Four algorithms are implemented:

- Max Heap Based (`O(n + klog(n))`)
- Min Heap Based (`O(k + nlog(k))`)
- Linear Time Method (`O(n)`)
- Brute Force Method (quicksort) (`O(nlog(n))`)

## Result

Under non-sorted array:

N=10000000：

|k|Brute Force|Max Heap|Min Heap|Linear Time Method|
|----|----|----|---|---|
|k=100000|1862|355|185|**135**|
|k=1000|1857|278|**33**|107|
|k=10|1869|279|**31**|112|

N=100000:

|k|Brute Force|Max Heap|Min Heap|Linear Time Method|
|----|----|----|---|---|
|k=1000|14.52|3.14|1.48|**1.45**|
|k=10|15.57|2.85|**0.36**|1.56|

N=1000:

|k|Brute Force|Max Heap|Min Heap|Linear Time Method|
|----|----|----|---|---|
|k=10|0.096|0.044|0.012|**0.009**|

Under sorted array:


N=10000000

|k|Brute Force|Max Heap|Min Heap|Linear Time Method|
|----|----|----|---|---|
|k=100000|-|108.3|**53.7**|-|
|k=1000|-|70.2|**32.6**|-|
|k=10|-|71.5|**33.2**|-|

Note that "-" represents too long running time.

N=100000:

|k|Brute Force|Max Heap|Min Heap|Linear Time Method|
|----|----|----|---|---|
|k=1000|9263|0.89|**0.45**|4563|
|k=10|9231|0.64|**0.31**|4560|

N=1000:

|k|Brute Force|Max Heap|Min Heap|Linear Time Method|
|----|----|----|---|---|
|k=10|1.129|0.014|**0.009**|0.521|


