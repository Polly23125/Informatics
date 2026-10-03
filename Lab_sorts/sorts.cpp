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

void sort_select(int array[], int n){
    for (int i = 0; i < n; i++){
        int m = 2147483647;
        int index;
        for (int j = i; j < n; j++){
            if (array[j] < m){
                m = array[j];
                index = j;
            }
        swap (array[i], array[index]);
        }
    }
}

struct pointers
{
    int l;
    int r;
};

pointers merge_sort(int array[], int n, int l, int r){ //передаем правый и левый указатель, тк массивы возвращать нельзя
    if (n <= 2){
        if (n == 2){
            if (array[l] > array[r]){
                swap(array[l], array[r]);
                pointers p = {l, r};
                return p;
            }
        }
        else{
            pointers p = {l, r};
            return p;
        }
    }
    pointers p1 = merge_sort(array, n/2, l, (l+r)/2-1);
    pointers p2 = merge_sort(array, (n+1)/2, (l+r)/2, r);

    int i = p1.l;
    int j = p2.l;
    while (i < (p1.r+1)){
        while (j < (p2.r+1)){
            if (array[i] < array[j]){
                
            }
        }
    }
}