#include <iostream>
#include <fstream>
#include <chrono>
#include <cstddef>
#include "header.h"

int main(){
    std :: string str1;
    std :: string str2;
    std :: string str3;
    read_from_file("1.txt", str1);
    read_from_file("2.txt", str2);
    read_from_file("3.txt", str3);

    int a = 28;
    Block_16 b16;
    Block_1024 b1024;
    Block_16384 b163;
    Text t1;
    Text t2;
    Text t3;

    for (int i = 0; i < sizeof(str1); i++){
        b16.data[i] = str1[i];
        t1.data = (const char*)&str1;
        t1.size = sizeof(str1);
    }

    //std :: cout << str2;
}