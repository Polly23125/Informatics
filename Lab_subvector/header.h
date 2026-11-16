#ifndef HEADER_H
#define HEADER_H
#include <vector>
struct Time
{
    double data[10];
};


class Subvector{
    unsigned int size_ = 0; //количество элементов
    unsigned int capacity_ = 0; //количество выделенной памяти
    int* data_ = nullptr;

public:

    Subvector(unsigned int capacity){
        capacity_ = capacity;
        data_ = new int[capacity];
        // for (unsigned int i = 0; i < capacity_; i++){
        //     data_[i] = 0;
        // }
    }

    ~Subvector(){
        std :: cout << "Deleted elements: " << size_  <<'\n';
        delete[] data_;
    }

    bool push_back_plus (int value, int step);
    bool push_back_multiply (int value, int myltiplier);

    int pop_back();

    bool resize(unsigned int new_capacity);

    void shrink_to_fit();

    void clear(); 
};

double get_time();
Time init_add_subvector_plus (unsigned int repeat, const int delta[], const int& size);
Time init_add_subvector_myltiply (unsigned int repeat, const int delta[], const int& size);
double init_add_vector (unsigned int repeat);


#endif