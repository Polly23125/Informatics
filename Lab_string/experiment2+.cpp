#include <iostream>
#include <fstream>
#include "header.h"

int main(){
    std :: ofstream f("4.csv", std :: ios::out); 
    f << "experiment" << "," << "length" << "," << "mode" << "," << "repeats" << "," << "result" << std :: endl;

    std :: string str1;
    std :: string str2;
    std :: string str3;
    read_from_file("1.txt", str1);
    read_from_file("2.txt", str2);
    read_from_file("3.txt", str3);

    Text t1;
    Text t2;
    Text t3;

    t1.data = (const char*)&str1;
    t1.size = 16;
    t2.data = (const char*)&str2;
    t2.size = 1024;
    t3.data = (const char*)&str3;
    t3.size = 16384;

    int ks[] = {1, 10, 100};
    int G = 100;
    int repeats = 20;

    double time[30];

    for (int p = 0; p < 3; p++){
        time [0 + p*9] = repeat(t1, ks[p], borrow, G, repeats);
        time [1 + p*9] = repeat(t2, ks[p], borrow, G, repeats);
        time [2 + p*9] = repeat(t3, ks[p], borrow, G, repeats);

        time [3 + p*9] = repeat(t1, ks[p], copy_each, G, repeats);
        time [4 + p*9] = repeat(t2, ks[p], copy_each, G, repeats);
        time [5 + p*9] = repeat(t3, ks[p], copy_each, G, repeats);

        time [6 + p*9] = repeat(t1, ks[p], copy_once, G, repeats);
        time [7 + p*9] = repeat(t2, ks[p], copy_once, G, repeats);
        time [8 + p*9] = repeat(t3, ks[p], copy_once, G, repeats);
    }

    std::cout << "text" << "," << "15" << "," << "borrow" << "," << "1_100_20"  << "," << time[0] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "borrow" << "," << "1_100_20" << "," << time[1] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "borrow" << "," << "1_100_20" << "," << time[2] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "copy_each" << "," << "1_100_20"  << "," << time[3] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "copy_each" << "," << "1_100_20" << "," << time[4] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "copy_each" << "," << "1_100_20" << "," << time[5] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "copy_once" << "," << "1_100_20"  << "," << time[6] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "copy_once" << "," << "1_100_20" << "," << time[7] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "copy_once" << "," << "1_100_20" << "," << time[8] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "borrow" << "," << "10_100_20"  << "," << time[9] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "borrow" << "," << "10_100_20" << "," << time[10] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "borrow" << "," << "10_100_20" << "," << time[11] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "copy_each" << "," << "10_100_20"  << "," << time[12] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "copy_each" << "," << "10_100_20" << "," << time[13] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "copy_each" << "," << "10_100_20" << "," << time[14] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "copy_once" << "," << "10_100_20"  << "," << time[15] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "copy_once" << "," << "10_100_20" << "," << time[16] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "copy_once" << "," << "10_100_20" << "," << time[17] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "borrow" << "," << "100_100_20"  << "," << time[18] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "borrow" << "," << "100_100_20" << "," << time[19] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "borrow" << "," << "100_100_20" << "," << time[20] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "copy_each" << "," << "100_100_20"  << "," << time[21] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "copy_each" << "," << "100_100_20" << "," << time[22] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "copy_each" << "," << "100_100_20" << "," << time[23] << std :: endl;

    std::cout << "text" << "," << "15" << "," << "copy_once" << "," << "100_100_20"  << "," << time[24] << std :: endl;
    std::cout << "text" << "," << "1023" << "," << "copy_once" << "," << "100_100_20" << "," << time[25] << std :: endl;
    std::cout << "text" << "," << "16383" << "," << "copy_once" << "," << "100_100_20" << "," << time[26] << std :: endl;
    
    f.close();
}