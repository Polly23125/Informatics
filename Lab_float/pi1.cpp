#include <iostream>
#include <fstream>
#include "header.h"

int main(){
    std :: ofstream f("value_of_pi.csv", std :: ios::out);
    f << "Iter" << "," << "Leibniz" << "," << "BBP" << "," << "Sqrt" << "," << "Nil" << "," << "Wallis"<< std :: endl;
    
    for (int i = 1; i < 1000; i++){
        float pi_leibniz_num = pi_leibniz(i);
        float pi_bbp_num = pi_BBP(i);
        float pi_sqrt_num = pi_sqrt(i);
        float pi_nilakantha_num = pi_nilakantha(i);
        float pi_wallis_num = pi_wallis(i);

        f << i << "," << pi_leibniz_num << "," << pi_bbp_num << "," << pi_sqrt_num << "," << pi_nilakantha_num << "," << pi_wallis_num << std::endl;
    }
}