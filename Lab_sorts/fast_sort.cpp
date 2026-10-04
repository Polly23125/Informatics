#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

int main(){
    std :: ofstream f("5.csv", std :: ios::out); 
    int test_array[100000];
    int test_size [8] = {10, 100, 1000, 5000, 10000, 25000, 50000, 100000};

    f << "Number" << "," << "Time of merge_sort" << "," << "Time of shell_sort" << "," << "Time of quick_sort" << std :: endl;

    for (int j = 0; j < 8; j++){

        int N = test_size[j];
        double merge_time = 0;
        double shell_time = 0;
        double quick_time = 0;
        double K = 5;

        for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto merge_t1=std::chrono::steady_clock::now();
            merge_sort(test_array, 0, N-1);
            auto merge_t2=std::chrono::steady_clock::now();

            merge_time += std::chrono::duration<double>(merge_t2-merge_t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
        std :: cout << N << ": Time merge_sort " << merge_time/K << '\n';
        
        for (int k = 0; k < K; k++){
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto shell_t1=std::chrono::steady_clock::now();
            shell_sort(test_array, N);
            auto shell_t2=std::chrono::steady_clock::now();

            shell_time += std::chrono::duration<double>(shell_t2-shell_t1).count();
            std :: cout << is_sort(test_array, N) << ' ';
        }
        std :: cout << N << ": Time shell_sort " << shell_time/K << '\n';
        for (int k = 0; k < K; k++){
            for (int i = 0; i < N; i++){
            test_array[i] = rand_uns(0, 1000000);
            }
            
            auto quick_t1=std::chrono::steady_clock::now();
            quick_sort(test_array, 0, N-1);
            auto quick_t2=std::chrono::steady_clock::now();

            quick_time += std::chrono::duration<double>(quick_t2-quick_t1).count();
            std :: cout << is_sort(test_array, N) << ' ';

        }
        std :: cout << N << ": Time quick_sort " << quick_time/K << '\n';
        f << N << "," << merge_time/K << "," << shell_time/K << "," << quick_time/K <<  std :: endl;
    }
}