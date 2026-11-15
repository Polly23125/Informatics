#include <iostream>
#include <vector>
#include <chrono>
#include "container.h"

// struct S{ //всё по умолчанию публичное
// public:
//     int a;
//     int b;
//     bool method (int a){
//         return true;
//     }
// };

// class C{ //всё по умолчанию приватное
// public:
//     int a;
//     int b;
//     bool method (int a){
//         return true;
//     }
//     S convert_to_structure(){
//         S result;
//         result.a = a;
//         result.b = b;
//     }
// private:
    
// };

int main(){
    // S structure;
    // C clas;

    // clas.a = 10;
    // clas.b = 20;

    // S new_structure = clas.convert_to_structure();

    std :: vector<int> vec(1);
    Journal tetradka(1);

    std :: cout << "Vector: ";
    
    auto start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000000; i++){
        vec.push_back(1);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();

    std :: cout << seconds<< '\n';

    std :: cout << "Journal: ";

    start = std::chrono::steady_clock::now();
    for (int i = 0; i < 1000000; i++){
        tetradka.add(1);
    }
    finish = std::chrono::steady_clock::now();
    seconds = std::chrono::duration<double>(finish - start).count();

    std :: cout << seconds<< '\n';
}