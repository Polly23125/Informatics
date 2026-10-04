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

pointers merge_sort(int array[], int n, int l, int r){ //передаем правый и левый указатель, тк массивы возвращать нельзя
    if (n <= 2){
        if (n == 2){
            if (array[l] > array[r]){
                swap(array[l], array[r]);
                pointers p = {l, r};
                return p;
            }
            else{
                pointers p = {l, r};
                return p;
            }
        }
        else{
            pointers p = {l, r};
            return p;
        }
    }
    pointers p1 = merge_sort(array, n/int(2), l, (l+r)/int(2)-1);
    pointers p2 = merge_sort(array, (n+1)/int(2), (l+r)/int(2), r);

    int i = p1.l;
    int j = p2.l;
    while (i < (p1.r+1)){
        while (j < (p2.r+1)){
            if (array[i] > array[j]){
                insert(array, p2.r+1, array[j], i+1);
                i++;
                j++;
            }
            else{
                i++;
            }
        }
    }
    pointers p = {0,n};
    return p;
}