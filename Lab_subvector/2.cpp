#include <iostream>
#include <fstream>
#include "header.h"

int main() { 
    std::ofstream f("2.csv", std::ios::out); 
    f << "n,time1,time2,time3,time4,time5" << std::endl; 
    unsigned int repeats[] = {1, 10, 100, 1000, 10000, 100000, 1000000};
    int delta1[] = {10, 100, 1000, 10000, 100000, 1000000};
    int delta2[] = {2, 3, 4, 5, 6};

    Time time1;
    Time time2;

    for (int i = 0; i < 6; i++){
        time1 = init_add_subvector_plus(repeats[i], delta1, 6);
        //std::cout << repeats[i] << "," << time << "," << time1.data[0] << "," << time1.data[1] << "," << time2.data[0] << "," << time2.data[1] << '\n';
        f << repeats[i] << "," << time1.data[0] << "," << time1.data[1] << "," << time1.data[2] << "," << time1.data[3] << "," << time1.data[4] << "," << time1.data[5] << std::endl; 
    }

    for (int i = 0; i < 7; i++){
        time2 = init_add_subvector_myltiply(repeats[i], delta2, 5);
        //std::cout << repeats[i] << "," << time << "," << time1.data[0] << "," << time1.data[1] << "," << time2.data[0] << "," << time2.data[1] << '\n';
        f << repeats[i] << "," << time2.data[0] << "," << time2.data[1] << "," << time2.data[2] << "," << time2.data[3] << "," << time2.data[4] << std::endl; 
    }
    f.close();
}