#include <iostream>
#include <fstream>
#include <vector>
#include "header.h"

int main() { 
    std::ofstream f("results.csv", std::ios::out); 
    f << "n,time1,time2,time3,time4,time5" << std::endl; 
    unsigned int repeats[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int delta1[] = {10, 100};
    int delta2[] = {4, 2};

    Time time1;
    Time time2;
    double time;

    for (int i = 0; i < 7; i++){
        time1 = init_add_subvector_plus(repeats[i], delta1, 2);
        time2 = init_add_subvector_myltiply(repeats[i], delta2, 2);
        time = init_add_vector(repeats[i]);
        std::cout << repeats[i] << "," << time << "," << time1.data[0] << "," << time1.data[1] << "," << time2.data[0] << "," << time2.data[1] << '\n';
        f << repeats[i] << "," << time << "," << time1.data[0] << "," << time1.data[1] << "," << time2.data[0] << "," << time2.data[1] << std::endl; 
    }
    f.close();
}