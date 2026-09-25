#include "buble_sort.h"

void buble_sort (int array[], int n){
    for (int i = 0; i < n; i++){
        for (int j = 0; j < n - i - 1; j++){
            if (array[j] > array [j+1]){
                swap(array[j], array[j+1]);
            }
        }
    }
}

