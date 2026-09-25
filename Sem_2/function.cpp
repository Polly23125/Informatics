#include <iostream>

int sum(int a, int b){// int - функция возвращает int
    return a + b;
}

void print_number (int n){ //сигнатура = тип вывода + название + тип данных.
    //меняем одно из трёх - другая функция. это перегрузка функции
    std::cout << n << '\n';
}

void print_number (float n){
    std::cout << n << '\n';
}

void print_number (double n){
    std::cout << n << '\n';
}


void print_int_number (int n){// void - функция ничего не возвращает, нет return
    std::cout << n << '\n';
}

void print_float_number (float n){
    std::cout << n << '\n';
}

double power(double number, int degree){ //если перед number добавить &,
    //то передадим ссылку и глобальная переменная будет меняться
    double result = 1;
    for (int i=0; i < degree; i++){
        result *= number;
    }
    return result;
}

struct MyType{
    int a = 1;
    int b = 0;
    double d = 0.0;
};

MyType function(MyType m){
    MyType result {m.a, m.b, m.d};
    result.a = 1;
    result.b = 3;
    result.d = 0.9;
    return result;
}
int main(){
    int a;
    double d;
    std::cin >> a >> d;

    // float res = (7 * float (sum (a, d)))/4;

    // //std::cout << sum (d, a) << ' ' << res;

    // print_int_number(sum(d,a));
    // print_float_number(res);
    print_number(power(d,a));
    print_number(d);
}