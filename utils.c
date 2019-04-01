#include <utils.h>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void swap(int *a, int i, int j){
    int temp = a[i];
    a[i] = a[j];
    a[j] = temp;
    return;
}

// read n nums into a (n<10000000)
void read_input(int *a, int n){
    FILE *fp = fopen("input.txt", "r");
    char buffer[10];
    char *p_buffer = buffer;
    ssize_t readsize = 1000;
    size_t wantsize = 10;
    int idx = -1;
    while(readsize > 0){
        readsize = getline(&p_buffer, &wantsize, fp);
        buffer[readsize-1] = '\0';
        idx++;
        if(idx >= n)
            break;
        if(readsize > 0)
            sscanf(buffer, "%d", &a[idx]);
    }
    fclose(fp);
    return;
}

void get_timer(clock_t *c){
    *c = clock();
}

void print_duration(clock_t *start, clock_t *end){
    printf("duration: %lf ms?\n", ((double) ((*end) - (*start)) / CLOCKS_PER_SEC * 1000));
}