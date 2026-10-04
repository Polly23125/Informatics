#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

int main(){
    std :: ofstream f("4.csv", std :: ios::out); 
    int test_array[100000];
    int test_size [8] = {10, 100, 1000, 5000, 10000, 25000, 50000, 100000};

    f << "Number" << "," << "Time of select_sort" << std :: endl;

    for (int j = 0; j < 8; j++){

        int N = test_size[j];
        double select_time = 0;
        double K = 5;
        
        for (int k = 0; k < K; k++){
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto select_t1=std::chrono::steady_clock::now();
            select_sort(test_array, N);
            auto select_t2=std::chrono::steady_clock::now();

            select_time += std::chrono::duration<double>(select_t2-select_t1).count();
            std :: cout << is_sort(test_array, N) << ' ';

        }
        std :: cout << N << ": Time select_sort " << select_time/K << '\n';
        f << N << "," << select_time/K <<  std :: endl;
    }
}