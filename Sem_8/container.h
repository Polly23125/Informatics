#pragma once
#include <iostream>

class Journal{
public:
    unsigned size_ = 0; //объём выделенной памяти
    unsigned capacity_ = 0; //количество свободных ячеек
    int* data_ = nullptr;



    Journal(unsigned capacity){
        capacity_ = capacity;
        data_ = new int[capacity];
    }

    ~Journal(){
        std :: cout << "Deleted elements: " << capacity_+size_  <<'\n';
        delete[] data_;
    }

    Journal(Journal& from){
        capacity_ = from.capacity_;
        size_ = from.size_;
        data_ = new int[from.capacity_];
        for (int i = 0; i < size_; ++i){
            data_[i] = from.data_[i];
        }
    } //запрещаем делать журналы от журналов
    Journal& operator=(Journal) = delete; //запрещаем приравнивать журналы

    int get(unsigned index)const{
        if (index < size_){
            return data_[index];
        }
    }

    bool add (int value){
        if (capacity_ <= size_){
            capacity_ *= 3;
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

    int sum ()const{
        int result = 0;
        for (int i = 0; i < size_; i++){
            result += data_[i];
        }
        return result;
    }

    // void print_data(){
    //     for (int i = 0; i < size_; i++){
    //         std :: cout << data_[i] << ' ';
    //     }
    //     std :: cout << '\n';
    // }
};

