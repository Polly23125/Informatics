#include <iostream>

int main(){
    int a;
    std :: cin >> a;
    for (int i = 0; i < 32; i++){
        std :: cout << ((a >> i) & 1) << ' ';
    }

}