#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

int main(){
    std :: ofstream f("6.csv", std :: ios::out); 
    int test_array[100000];
    int test_size [10] = {1, 5, 10, 50, 75, 100, 250, 500, 750, 1000};

    f << "Number" << "," << "Time of buble_sort" << "," << "Time of insert_sort" << "," << "Time of select_sort" << "," << "Time of merge_sort" << "," << "Time of shell_sort" << "," << "Time of quick_sort" << std :: endl;

    for (int j = 0; j < 10; j++){

        int N = test_size[j];
        double buble_time = 0;
        double select_time = 0;
        double insert_time = 0;
        double merge_time = 0;
        double shell_time = 0;
        double quick_time = 0;
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
        f << N << "," << buble_time/K << "," << insert_time/K << "," << select_time/K <<  "," << merge_time/K << "," << shell_time/K << "," << quick_time/K <<  std :: endl;
    }
}