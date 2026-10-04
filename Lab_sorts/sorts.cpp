#include "header.h"

void buble_sort (int array[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (array[j] > array [j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

void insert_sort(int array[], int n){
    for (int i = 1; i < n; i++){
        int cur = array[i];
        for (int j = 0; j < i; j++){
            if (array[j] > cur){
                insert(array, n, cur, j);
            }
        }
    }
}

void select_sort(int array[], int n){
    for (int i = 0; i < n; i++){
        int index = find_min (array, i, n);
        swap (array[i], array[index]);
    }
}


void merge_sort(int array[], int l, int r){ //передаем правый и левый указатель, тк массивы возвращать нельзя
    if (l < r){
        int mid = (l + r)/int(2);

        merge_sort(array, l, mid);
        merge_sort(array, mid+1, r);

        merge(array, l, mid,r);
    }
}

void shell_sort (int array[], int n){
    for (int step = n/int(2); step > 0; step /= int(2)){
        for (int i = step; i < n; i++){
            int j = i;
            while (j >= step && array[j-step] > array[j]){
                swap (array[j], array[j-step]);
                j-=step;
            }
        }
    }
}

void quick_sort (int array[], int l, int r){
    if (l < r){
        int pivot = partition(array, r, l);

        quick_sort(array, l, pivot-1);
        quick_sort(array, pivot+1, r);
    }
}