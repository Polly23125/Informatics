#pragma once
#include <iostream>

class Journal{
    unsigned size_ = 0; //количество записанных измерений
    unsigned capacity_ = 0; //количество свободных ячеек
    int* data_ = nullptr;


public:
    Journal(unsigned capacity){
        capacity_ = capacity;
        data_ = new int[capacity];
    }

    ~Journal(){
        std :: cout << "Deleted elements: " << capacity_+size_ <<'\n';
        delete[] data_;
    }

    Journal(Journal&) = delete; //запрещаем делать журналы от журналов
    Journal& operator=(Journal) = delete; //запрещаем приравнивать журналы

    int get(unsigned index)const{
        return data_[index];
    }

    bool add (int value){
        if (capacity_ <= 0){
            return false;
        }
        else{
            data_ [size_] = value;
            capacity_ --;
            size_ ++;
            return true;
        }
    }

    int sum ()const{
        int result = 0;
        for (int i = 0; i < size_; i++){
            result += data_[i];
        }
        return result;
    }

    void print_data()const{
        for (int i = 0; i < size_; i++){
            std :: cout << data_[i] << ' ';
        }
        std :: cout << '\n';
    }
};

