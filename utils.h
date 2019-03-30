#ifndef _UTILS_H
#define _UTILS_H
#include <time.h>

void swap(int *a, int i, int j);
void read_input(int *a, int n);

void get_timer(clock_t *c);
void print_duration(clock_t *start, clock_t *end);

#endif