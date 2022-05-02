#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int a[10000000];

int random_pivot(int low, int high){
    return (rand() % (high - low + 1)) + low;
}

int partition(int beg, int end){
    int loc, pindex, pivot, temp;
    int piv_ind = random_pivot(beg, end);
    pivot = a[piv_ind];
    pindex = beg;
    for (int i = beg; i < end; i++){
        if (pivot < a[i]){
            continue;
        }
        else{
            temp = a[i];
            a[i] = a[pindex];
            a[pindex] = temp;
            pindex++;
        }
    }
    temp = a[pindex];
    a[pindex] = a[end];
    a[end] = temp;
    return pindex;
}

int normal_partition(int beg, int end){
    int loc, pindex, pivot, temp;
    pivot = a[end];
    pindex = beg;
    for (int i = beg; i < end; i++){
        if (pivot < a[i]){
            continue;
        }
        else{
            temp = a[i];
            a[i] = a[pindex];
            a[pindex] = temp;
            pindex++;
        }
    }
    temp = a[pindex];
    a[pindex] = a[end];
    a[end] = temp;
    return pindex;
}

void quicksort(int beg, int end){
    int p;
    if (beg < end){
        p = partition(beg, end);
        quicksort(beg, p - 1);
        quicksort(p + 1, end);
    }
}

void normal_quicksort(int beg, int end){
    int p;
    if (beg < end){
        p = normal_partition(beg, end);
        normal_quicksort(beg, p - 1);
        normal_quicksort(p + 1, end);
    }
}

void print_arr(int arr[], int n){
    int i;
    for (i = 1; i < n + 1; i++){
        printf("%d\t", arr[i]);
    }
}

void main() {
    int n, i, beg, end;
    clock_t t1, t2;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        a[i] = random_pivot(0, n);
    }
    t1 = clock();
    quicksort(0, n);
    t1 = clock() - t1;
    double time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("Randomized:\t%fs\n", time_taken1);
    t2 = clock();
    normal_quicksort(0, n);
    t2 = clock() - t2;
    double time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("Normal:\t\t%fs\n", time_taken2);
}