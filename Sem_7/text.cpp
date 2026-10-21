#include <iostream>
#include <fstream>
#include "text.h"

void initialize(Data & d, int size, int number){
    d.data = new int[10];
    d.size = size;
    for (int i = 0; i < d.size; i++){
        d.data[i] = 1;
    }
}

void print_data (const Data & d){
    for (int i = 0; i < d.size; i++){
        std :: cout << d.data[i] << ' ';
    }
    std :: cout << std :: endl;
}

void release(Data & d){
    delete[] d.data;
    d.size = 0;
    d.data = nullptr;
}

void copy_data (const Data & from, Data & to){
    to.data = new int[from.size];
    to.size = from.size;
    for (int i = 0; i < from.size; i++){
        to.data[i] = from.data[i];
    }
}

Text read_from_file (std :: string filename){
    std :: ifstream input (filename);

    std::string  line, all_text;
    std :: size_t number = 0;

    while (std :: getline(input, line)){
        line += '\n';
        all_text += line;
    }

    Text result {all_text.data(), all_text.size()};
    return result;
}

void print_text(const Text & t){
    for (int i = 0; i < t.size; i++){
        std :: cout << t.data[i] << ' '; 
    }
}