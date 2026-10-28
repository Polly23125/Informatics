#include <iostream>
#include <fstream>
#include "header.h"

int main(){
    std :: ofstream f("accure_of_pi.csv", std :: ios::out);
    f << "Accuracy" << "," << "BBP" << "," << "Sqrt" << "," << "Wallis"<< std :: endl;
    
    int si = 1;
    for (float a = 0.1; a > 1.0e-7; a = a/10){
        //float pi_leibniz_time = pi_accur(a, pi_leibniz);
        float pi_bbp_time = pi_accur(a, pi_BBP);
        //float pi_nilakantha_time = pi_accur(a, pi_nilakantha);
        float pi_wallis_time = pi_accur(a, pi_wallis);

        f << si << "," << pi_bbp_time << "," << pi_wallis_time << std::endl;
        si++;
    }
}