#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

int main(){
    std :: ofstream f("7.csv", std :: ios::out); 
    int test_array[100000];
    int test_size [10] = {1, 5, 10, 50, 75, 100, 250, 500, 750, 1000};

    f << "Number" << "," << "Time of buble_sort" << "," << "Time of insert_sort" << "," << "Time of select_sort" << "," << "Time of merge_sort" << "," << "Time of shell_sort" << "," << "Time of quick_sort" << std :: endl;

    for (int j = 0; j < 10; j++){

        int N = test_size[j];
        double K = 5;

        double merge_time = init_best_sort2(K, N, test_array, merge_sort);
        std :: cout << N << ": Time merge_sort " << merge_time << '\n';

        double shell_time = init_best_sort1(K, N, test_array, shell_sort);
        std :: cout << N << ": Time shell_sort " << shell_time << '\n';

        double quick_time = init_best_sort2(K, N, test_array, quick_sort);
        std :: cout << N << ": Time quick_sort " << quick_time << '\n';

        double buble_time = init_best_sort1(K, N, test_array, buble_sort);
        std :: cout << N << ": Time buble_sort " << buble_time << '\n';

        double insert_time = init_best_sort1(K, N, test_array, insert_sort);
        std :: cout << N << ": Time isert_sort " << insert_time << '\n';

        double select_time = init_best_sort1(K, N, test_array, select_sort);
        std :: cout << N << ": Time select_sort " << select_time << '\n';
        f << N << "," << buble_time << "," << insert_time << "," << select_time <<  "," << merge_time << "," << shell_time << "," << quick_time <<  std :: endl;
    }
}