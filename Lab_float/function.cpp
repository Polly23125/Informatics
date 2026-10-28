#include <iostream>
#include <stdint.h>
#include <cmath>
#include <chrono>
#include "header.h"

void binary(unsigned int a){
    int mass [32];
    for (int i = 0; i < 32; i++){
        mass[i] = ((a >> i) & 1);
    }
    int i = 31;
    while (i >= 0){
        std :: cout << mass[i];
        i--;
    }
    std :: cout <<'\n';
}

void binary_part(unsigned int a){
    int mass [32];
    for (int i = 1; i < 32; i++){
        mass[i] = ((a >> i) & 1);
    }
    int i = 31;
    while (i >= 0){
        if (i == 31){
            std::cout << "(Sign: ";
        }
        if (i == 30){
            std::cout << " Exponent: ";
        }
        if (i == 22){
            std::cout << " Mantissa: ";
        }
        std :: cout << mass[i];
        i--;
    }
    std :: cout << ")" <<'\n';
}


float pi_leibniz (int N){
    float pi = 0.0f;
    int sign = 1;
    for (int n = 0; n < N; n++){
        pi += sign/(2.0 * n + 1.0);
        sign = -sign;
    }
    return pi * 4.0f;
}

float pi_BBP(int N){
    float pi = 0.0f;
    float multiplier = 1.0;
    for (int n = 0; n < N; n++){
        pi = pi + 1.0/multiplier*(4.0/(8.0*n+1.0) - 2.0/(8.0*n+4.0) - 1.0/(8.0*n+5.0) - 1.0/(8.0*n+6.0));
        multiplier = multiplier * 16.0;
    }
    return pi;
}

float pi_sqrt(int N){
    int number = 5;
    float pi = sqrt(5);
    for (int n = 0; n < N; n++){
        number ++;
        pi = sqrt(number + pi);
    }
    return pi;
}

float pi_nilakantha(int N) {
    float pi = 3.0;
    int sign = 1;

    for (int n = 1; n <= N; ++n) {
        float summand = (2.0*n) * (2.0*n+1.0) * (2.0*n+2.0);
        pi += sign * 4.0 / summand;
        sign = -sign;
    }
    return pi;
}

float pi_wallis(int N) {
    float pi = 1.0;

    for (int n = 1; n <= N; ++n) {
        float p = 2.0 * n;
        pi *= (p * p) / ((p - 1.0) * (p + 1.0));
    }
    return 2.0 * pi;
}

float pi_error(float value){
    float error = std::abs(value - 3.141592653589793);
    return error;
}

double pi_accur (float accuracy, float (*func)(int)){
    float error = 1.0;
    int n = 0;
    double result_time;

    while (error > accuracy){
        n++;
        float pi = func(n);
        error = pi_error(pi);
    }
    auto t1 = std::chrono::steady_clock::now();
        for (int i = 0; i < 100; i++){
            func(n);
        }
    auto t2 = std::chrono::steady_clock::now();
    result_time = std::chrono::duration<double>(t2-t1).count();
    return result_time;
}