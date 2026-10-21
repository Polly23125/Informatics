#pragma once

#include <iostream>

struct Text{
    char* data = nullptr;
    size_t size = 0;
};

struct Data {
    int* data = nullptr;
    int size = 0;
};

void initialize(Data & d, int size, int number);
void print_data (const Data & d);
void release(Data & d);
void copy_data (const Data & from, Data & to);
Text read_from_file (std :: string filename);
