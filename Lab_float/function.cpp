#include <iostream>
#include <stdint.h>
#include "header.h"

void uns_to_binar(unsigned int a){
    int mass [32];
    for (int i = 0; i < 32; i++){
        mass[i] = ((a >> i) & 1);
    }
    int i = 31;
    while (mass[i]==0){
        i--;
    }
    while (i >= 0){
        std :: cout << mass[i];
        i--;
    }
}

typedef union {float flt; uint32_t bits;} lens_t;

uint32_t f2i(float x) {
    return ((lens_t) {.flt = x}).bits;
}

void float_to_binar(float a){
    unsigned int b = uint32_t (a);
    int mass [32];
    for (int i = 0; i < 32; i++){
        mass[i] = ((b >> i) & 1);
    }
    int i = 31;
    // while (mass[i]==0){
    //     i--;
    // }
    while (i >= 0){
        std :: cout << mass[i];
        i--;
    }
}