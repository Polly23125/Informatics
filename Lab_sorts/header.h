#ifndef HEADER_H
#define HEADER_H

struct pointers
{
    int l;
    int r;
};

void swap(int & a, int & b);
void insert(int array[], int n, int cur, int index);
bool is_sort(int array[], int n);

void buble_sort (int array[], int n);
void insert_sort(int array[], int n);
void select_sort(int array[], int n);
pointers merge_sort(int array[], int n, int l, int r);

#endif