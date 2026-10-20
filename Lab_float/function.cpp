#include <iostream>
#include <stdint.h>
#include "header.h"

void binary(unsigned int a){
    int mass [32];
    for (int i = 0; i < 32; i++){
        mass[i] = ((a >> i) & 1);
    }
    int i = 31;
    // while (mass[i]==0){
    //     i--;
    // }
    while (i >= 0){
        std :: cout << mass[i];
        i--;
    }
    std :: cout <<'\n';
}