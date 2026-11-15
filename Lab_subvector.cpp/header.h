#ifndef HEADER_H
#define HEADER_H

class Subvector{
    unsigned int size_ = 0; //количество элементов
    unsigned int capacity_ = 0; //количество выделенной памяти
    int* data_ = nullptr;

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

    bool push_back_10 (int value);
    bool push_back_100 (int value);
    bool push_back_2 (int value);
    bool push_back_15 (int value);
    bool push_back_3 (int value);

    int pop_back();

    bool resize(unsigned int new_capacity);

    void shrink_to_fit();

    void clear(); 
};


#endif