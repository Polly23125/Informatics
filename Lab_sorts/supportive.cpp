#include "header.h"
#include <chrono> 
#include <random> 
#include <iostream>


int rand_uns(int min, int max) { 
    unsigned seed = std::chrono::steady_clock::now().time_since_epoch().count(); 
    static std::default_random_engine e(seed); 
    std::uniform_int_distribution<int> d(min, max); 
    return d(e); 
}

bool is_sort(int array[], int n){
    for (int i = 0; i < n-1; ++i){
        if (array[i+1] < array[i]){
            return false;
        }
    }
    return true;
}

void swap(int & a, int & b){
    int tmp = a;
    a = b;
    b = tmp;
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

int find_min(int array[], int start, int n){
    int min_index = start;
    for (int j = start; j < n; j++){
        if (array[j] < array[min_index]){
            min_index = j;
        }
    }
    return min_index;
}

void merge (int array [], int l, int mid, int r){
    int n1 = mid - l + 1;
    int n2 = r - mid;

    int left_array[n1];
    int right_array[n2];

    for (int i = 0; i < n1; i++){
        left_array[i] = array[l + i];
    }
    for (int j = 0; j < n2; j++){
        right_array[j] = array[mid + j + 1];
    }

    int i = 0;
    int j = 0;
    int k = l;
    while (i < n1 && j < n2){
        if (left_array[i] < right_array [j]){
            array[k] = left_array[i];
            i++;
        }
        else{
            array[k] = right_array[j];
            j++;
        }
        k++;
    }

    while (i < n1){
        array[k] = left_array[i];
        i++;
        k++;
    }

    while (j < n2){
        array[k] = right_array[j];
        j++;
        k++;
    }
}

int partition(int array[], int end, int pivot){
    int i = end;
    while (i > pivot){
        if (array[i] < array[pivot] && i == pivot+1){
            swap(array[i], array[pivot]);
            pivot++;
        }
        else if (array[i] < array[pivot]){
            swap(array[pivot], array[pivot+1]);
            swap(array[i], array[pivot]);
            pivot++;
        }
        else{
            i--;
        }    
    }
    return pivot;
}

double init_rand_sort1(int K, int N, int test_array[], void (*func)(int array[], int)){
    double result_time;
    for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto t1=std::chrono::steady_clock::now();
            func(test_array, N);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
    return result_time/K;
}

double init_rand_sort2(int K, int N, int test_array[], void (*func)(int array[], int, int)){
    double result_time;
    for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto t1=std::chrono::steady_clock::now();
            func(test_array, 0, N-1);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
    return result_time/K;
}

double init_best_sort1(int K, int N, int test_array[], void (*func)(int array[], int)){
    double result_time;
    for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = i;
            }
            
            auto t1=std::chrono::steady_clock::now();
            func(test_array, N);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
    return result_time/K;
}

double init_best_sort2(int K, int N, int test_array[], void (*func)(int array[], int, int)){
    double result_time;
    for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = i;
            }
            
            auto t1=std::chrono::steady_clock::now();
            func(test_array, 0, N-1);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
    return result_time/K;
}

double init_worse_sort1(int K, int N, int test_array[], void (*func)(int array[], int)){
    double result_time;
    for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = N-i;
            }
            
            auto t1=std::chrono::steady_clock::now();
            func(test_array, N);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
    return result_time/K;
}

double init_worse_sort2(int K, int N, int test_array[], void (*func)(int array[], int, int)){
    double result_time;
    for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = N-i;
            }
            
            auto t1=std::chrono::steady_clock::now();
            func(test_array, 0, N-1);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
    return result_time/K;
}