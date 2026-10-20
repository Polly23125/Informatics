#include <iostream>
#include <fstream>
#include <chrono>
#include "header.h"

union fu{
float f; 
unsigned int b;
};

int main(){
    unsigned int a = 89;
    fu c;
    std :: cin >> a >> c.f;
    binary(a);
    binary(c.b);
}