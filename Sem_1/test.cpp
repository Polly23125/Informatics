#include <iostream>
#include <math.h>


int main(){
    int a = 4;
    float b = 10;
    bool c = 1;
    signed int d = -15;
    std::cout <<b / a << '\n' << c;
    //выбирается самый точный
    //количество чисел конечно из-за памяти, long - увеличивает 

    unsigned int e = 3;
    signed int f = -6;
    std::cout <<f / e << '\n';
    return 0;
}