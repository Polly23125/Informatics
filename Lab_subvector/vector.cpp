#include <iostream>
#include "header.h"

bool Subvector::push_back_plus (int value, int step){
    if (capacity_ <= size_){
        capacity_ += step;
        int* data_tmp = new int[capacity_];
        for (unsigned int i = 0; i < size_; i++){
            data_tmp[i] = data_[i];
        }
        delete[] data_;
        data_ = data_tmp;
    }
    data_ [size_] = value;
    size_ ++;
    return true;
}

bool Subvector::push_back_multiply (int value, int myltiplier){
    if (capacity_ <= size_){
        capacity_ *= myltiplier;
        int* data_tmp = new int[capacity_];
        for (unsigned int i = 0; i < size_; i++){
            data_tmp[i] = data_[i];
        }
        delete[] data_;
        data_ = data_tmp;
    }
    data_ [size_] = value;
    size_ ++;
    return true;
}

int Subvector::pop_back (){
    if (size_ == 0){
        return 0;
    }
    int cur = data_[size_ - 1];
    int* data_tmp = new int[capacity_ ];
    for (unsigned int i = 0; i < size_ - 1; i++){
            data_tmp[i] = data_[i];
    }
    delete[] data_;
    data_ = data_tmp;
    size_ --;
    return cur;
}

bool Subvector::resize (unsigned int new_capacity){
    unsigned int new_size;
    if (size_ < new_capacity){
        new_size = size_;
    }
    else{
        new_size = new_capacity;
    }
    int* data_tmp = new int[new_capacity];
    for (unsigned int i = 0; i < new_size; i++){
            data_tmp[i] = data_[i];
    }
    delete[] data_;
    data_ = data_tmp;
    size_ = new_size;
    capacity_ = new_capacity;
    return true;
}

void Subvector::shrink_to_fit(){
    int* data_tmp = new int[size_];
    for (unsigned int i = 0; i < size_; i++){
            data_tmp[i] = data_[i];
    }
    delete[] data_;
    data_ = data_tmp;
    capacity_ = size_;
}

void Subvector::clear(){
    int* data_tmp = new int[capacity_];
    delete[] data_;
    data_ = data_tmp;
    size_ = 0;
}