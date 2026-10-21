#include <iostream>
#include <string>

#include "text.h"

int main(){
    Data data_1;
    Data data_2;

    initialize (data_1, 5, 42);
    copy_data(data_1, data_2);
    print_data(data_1);
    print_data(data_2);   
}