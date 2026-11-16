#include <iostream>
#include <chrono>
#include <vector>
#include "header.h"

double get_time() { 
    return std::chrono::duration_cast<std::chrono::microseconds> (std::chrono::steady_clock::now().time_since_epoch()).count() / 1e6; 
} 

Time init_add_subvector_plus (unsigned int repeat, const int delta[], const int& size){
    Time time;
    for (int j = 0; j < size; j++){
        Subvector sub(1);
        double t1 = get_time();
        for (unsigned int i = 0; i < repeat; i++){
            sub.push_back_plus(1, delta[j]);
        }
        double t2 = get_time();
        time.data[j] = (t2 - t1);
    }
    return time;
}

Time init_add_subvector_myltiply (unsigned int repeat, const int delta[], const int& size){
    Time time;
    for (int j = 0; j < size; j++){
        Subvector sub(1);
        double t1 = get_time();
        for (unsigned int i = 0; i < repeat; i++){
            sub.push_back_multiply(1, delta[j]);
        }
        double t2 = get_time();
        time.data[j] = (t2 - t1);
    }
    return time;
}

double init_add_vector (unsigned int repeat){
    std::vector<int> vec(1);
    double t1 = get_time();
    for (unsigned int i = 0; i < repeat; i++){
        vec.push_back(1);
    }
    double t2 = get_time();
    return (t2 - t1);
}