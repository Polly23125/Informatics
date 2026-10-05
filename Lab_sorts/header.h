#ifndef HEADER_H
#define HEADER_H

//Вспомогательные функции
void swap(int & a, int & b);
void insert(int array[], int n, int cur, int index);
bool is_sort(int array[], int n);
void merge (int array [], int l, int mid, int r);
int partition(int array[], int end, int pivot);
int rand_uns(int min, int max);
int find_min(int array[], int start, int n);

//Инициализация сортировок
double init_rand_sort1(int K, int N, int test_array[], void (*func)(int array[], int));
double init_rand_sort2(int K, int N, int test_array[], void (*func)(int array[], int, int));
double init_best_sort1(int K, int N, int test_array[], void (*func)(int array[], int));
double init_best_sort2(int K, int N, int test_array[], void (*func)(int array[], int, int));
double init_worse_sort1(int K, int N, int test_array[], void (*func)(int array[], int));
double init_worse_sort2(int K, int N, int test_array[], void (*func)(int array[], int, int));

//Объявление сортировок
void buble_sort (int array[], int n);
void insert_sort(int array[], int n);
void select_sort(int array[], int n);
void merge_sort(int array[], int l, int r);
void shell_sort (int array[], int n);
void quick_sort (int array[], int l, int r);

#endif