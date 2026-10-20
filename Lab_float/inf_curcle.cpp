#include <iostream>
#include "header.h"

int main(){
    std::cout << std::fixed; 
    std::cout.precision(2);
    float i = 16670000.0f;
    while (i != i + 1.0f){
        i += 1.0f;
        std::cout << i << '\n';
    }
}