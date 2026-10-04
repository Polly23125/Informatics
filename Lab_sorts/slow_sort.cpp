#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

int main(){
    std :: ofstream f("1.csv", std :: ios::out); 
    int test_array[100000];
    int test_size [8] = {10, 100, 1000, 5000, 10000, 25000, 50000, 100000};

    f << "Number" << "," << "Time of buble_sort" << "," << "Time of insert_sort" << "," << "Time of select_sort" << std :: endl;

    for (int j = 0; j < 8; j++){

        int N = test_size[j];
        double buble_time = 0;
        double select_time = 0;
        double insert_time = 0;
        double K = 5;

        for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto buble_t1=std::chrono::steady_clock::now();
            buble_sort(test_array, N);
            auto buble_t2=std::chrono::steady_clock::now();

            buble_time += std::chrono::duration<double>(buble_t2-buble_t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
        std :: cout << N << ": Time buble_sort " << buble_time/K << '\n';
        
        for (int k = 0; k < K; k++){
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto insert_t1=std::chrono::steady_clock::now();
            insert_sort(test_array, N);
            auto insert_t2=std::chrono::steady_clock::now();

            insert_time += std::chrono::duration<double>(insert_t2-insert_t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
        std :: cout << N << ": Time isert_sort " << insert_time/K << '\n';
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
        f << N << "," << buble_time/K << "," << insert_time/K << "," << select_time/K <<  std :: endl;
    }
}