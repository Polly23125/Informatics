#ifndef HEADER_H
#define HEADER_H

union fi{
float f; 
unsigned int b;
};

void binary(unsigned int a);
float pi_leibniz (int N);
float pi_BBP(int N);
float pi_sqrt(int N);
float pi_nilakantha(int N);
float pi_wallis(int N);
float pi_error(float value);
double pi_accur (float accuracy, float (*func)(int));

#endif