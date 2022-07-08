#include <stdio.h>
#include <conio.h>
#include <stdlib.h>
#include <time.h>

int arr[10000000];

int random_pivot(int low, int high){
    return (rand() % (high - low + 1)) + low;
}

int partition(int low, int high) {
    int piv_ind = random_pivot(low, high);
    int temp1 = arr[piv_ind];
    arr[piv_ind] = arr[low];
    arr[low] = temp1;
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while(1 == 1) {
        i++;
        while (arr[i] < pivot){
            i++;
        }
        j--;
        while(arr[j] > pivot){
            j--;
        }
        if (i >= j){
            return j;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

int normal_partition(int low, int high) {
    int pivot = arr[low];
    int i = low - 1;
    int j = high + 1;
    while(1 == 1) {
        i++;
        while (arr[i] < pivot){
            i++;
        }
        j--;
        while(arr[j] > pivot){
            j--;
        }
        if (i >= j){
            return j;
        }
        int temp = arr[i];
        arr[i] = arr[j];
        arr[j] = temp;
    }
}

void quicksort(int low, int high) {
    if(low < high){
        int p = partition(low, high);
        quicksort(low, p);
        quicksort(p+1, high);
    }
}

void normal_quicksort(int low, int high) {
    if(low < high){
        int p = normal_partition(low, high);
        normal_quicksort(low, p);
        normal_quicksort(p+1, high);
    }
}

void print_arr(int arr[], int n) {
    int i;
    for (i = 1; i < n + 1; i++)
    {
        printf("%d\t", arr[i]);
    }
}

void main() {
    int n, i, beg, end;
    clock_t t1, t2;
    printf("Enter the number of elements: ");
    scanf("%d", &n);
    for (i = 0; i < n; i++) {
        arr[i] = i;
    }
    printf("Worst Case: \n");
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
    printf("\nRandomized array: \n");
    for (i = 0; i < n; i++) {
        arr[i] = random_pivot(0, n);
    }
    t1 = clock();
    quicksort(0, n);
    t1 = clock() - t1;
    time_taken1 = ((double)t1)/CLOCKS_PER_SEC;
    printf("Randomized:\t%fs\n", time_taken1);
    t2 = clock();
    normal_quicksort(0, n);
    t2 = clock() - t2;
    time_taken2 = ((double)t2)/CLOCKS_PER_SEC;
    printf("Normal:\t\t%fs\n", time_taken2);
}