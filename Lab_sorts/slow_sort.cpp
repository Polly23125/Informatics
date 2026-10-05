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
        double K = 5;
            
        double buble_time = init_rand_sort1(K, N, test_array, buble_sort);
        std :: cout << N << ": Time buble_sort " << buble_time << '\n';

        double insert_time = init_rand_sort1(K, N, test_array, insert_sort);
        std :: cout << N << ": Time isert_sort " << insert_time << '\n';

        double select_time = init_rand_sort1(K, N, test_array, select_sort);
        std :: cout << N << ": Time select_sort " << select_time << '\n';
        f << N << "," << buble_time << "," << insert_time << "," << select_time <<  std :: endl; 
    }
}