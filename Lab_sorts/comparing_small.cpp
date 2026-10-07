#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

int main(){
    std :: ofstream f("9.csv", std :: ios::out); 
    int test_array[100];
    int test_size [9] = {3, 5, 10, 15, 20, 25, 30, 35, 40};

    f << "Number" << "," << "Time of buble_sort" << "," << "Time of insert_sort" << "," << "Time of select_sort" << "," << "Time of merge_sort" << "," << "Time of shell_sort" << "," << "Time of quick_sort" << std :: endl;

    for (int j = 0; j < 9; j++){

        int N = test_size[j];
        double K = 500;

        double merge_time = init_rand_sort2(K, N, test_array, merge_sort);
        std :: cout << N << ": Time merge_sort " << merge_time << '\n';

        double shell_time = init_rand_sort1(K, N, test_array, shell_sort);
        std :: cout << N << ": Time shell_sort " << shell_time << '\n';

        double quick_time = init_rand_sort2(K, N, test_array, quick_sort);
        std :: cout << N << ": Time quick_sort " << quick_time << '\n';

        double buble_time = init_rand_sort1(K, N, test_array, buble_sort);
        std :: cout << N << ": Time buble_sort " << buble_time << '\n';

        double insert_time = init_rand_sort1(K, N, test_array, insert_sort);
        std :: cout << N << ": Time isert_sort " << insert_time << '\n';

        double select_time = init_rand_sort1(K, N, test_array, select_sort);
        std :: cout << N << ": Time select_sort " << select_time << '\n';
        f << N << "," << buble_time << "," << insert_time << "," << select_time <<  "," << merge_time << "," << shell_time << "," << quick_time <<  std :: endl;
    }
}