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
        double K = 5;

        double merge_time = init_rand_sort2(K, N, test_array, merge_sort);
        std :: cout << N << ": Time merge_sort " << merge_time << '\n';

        double shell_time = init_rand_sort1(K, N, test_array, shell_sort);
        std :: cout << N << ": Time shell_sort " << shell_time << '\n';

        double quick_time = init_rand_sort2(K, N, test_array, quick_sort);
        std :: cout << N << ": Time quick_sort " << quick_time << '\n';
        f << N << "," << merge_time << "," << shell_time << "," << quick_time <<  std :: endl;
    }
}