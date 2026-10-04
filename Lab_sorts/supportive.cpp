#include "header.h"

void swap(int & a, int & b){
    int tmp = a;
    a = b;
    b = tmp;
}

bool is_sort(int array[], int n){
    for (int i = 0; i < n-1; ++i){
        if (array[i+1] < array[i]){
            return false;
        }
    }
    return true;
}

void insert(int array[], int n, int cur, int index){ //индексация оносительно всего массива
    int i = n-2;
    while (i > index){
        if (array[i] == cur){
            array[i+1] = array [i-1];
            --i;
        }
        else{
            array[i+1] = array [i];
        }
        --i;
    }
    array[index] = cur;
}