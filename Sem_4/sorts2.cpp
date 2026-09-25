#include <iostream>
#include <chrono>
#include <time.h>
#include "utility.h"
#include "buble_sort.h"

int main(){
    int my_array[100000];
    for (int N = 100; N < 100000; N*=10){

        double result_time = 0;
        double K = 5;

        for (int k = 0; k < K; k++){
            
            for (int i = 0; i < N; i++){
            my_array[i] = N-i;
            }
            
            auto t1=std::chrono::steady_clock::now();
            buble_sort(my_array,N);
            auto t2=std::chrono::steady_clock::now();

            result_time += std::chrono::duration<double>(t2-t1).count();
        }

        std::cout << N <<": Time " << result_time/K << '\n';
    }
}