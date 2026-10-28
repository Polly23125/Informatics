#include <iostream>

#include "container.h"

void function(){
    Journal j(8);
}

int main(){
    
    Journal tetradka(10);
    //Journal tetradka2 = tetradka; плохо копировать, тк присваиваем просто ссылку из тетрадки

    for (int i = 0; i < 12; i++){
        Journal j (i);
        std :: cout << tetradka.add(i) << ' ';
    }
    std :: cout << '\n';

    function();

    std :: cout << tetradka.sum() << '\n';
    tetradka.print_data();

}