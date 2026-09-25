#include <iostream>
#include <math.h>


// int main(){
//     int a;
//     std::cin >> a;

//     if (a % 2 == 0){
//         std::cout <<"Even";
//     }

//     else{
//         std::cout <<"not Even";
//     }

//     //& - and, | - or
// }

int main(){
    for (unsigned i = 0; i < 10; std::cout << ++i <<' ')
    {
        //std::cout << i <<' ';
    }

    std::cout << std::endl;

    unsigned i = 0;
    while (i < 10)
    {
        std::cout << i <<' ';
        i+=1;
    }
    i = 0;

    std::cout << std::endl;

    do
    {
        std::cout << i <<' ';
        i++;
    } while (i < 10);
    
}