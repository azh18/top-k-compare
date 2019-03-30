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

TBA
