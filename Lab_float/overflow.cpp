#include <iostream>
#include "header.h"

int main(){
    std::cout << std::fixed; 
    std::cout.precision(2);
    int N = 100;
    float i = 1.0;
    for (int n = 0 ; n < 39; n++ ){
        i *= 10.0f;
        fi c;
        c.f = i;
        std::cout << "Float: "<< c.f << " Binary float: ";
        binary(c.b);
    }
}
