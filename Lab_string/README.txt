Формат ввода - чтение файлов:
1 - 15 символа
2 - 1023 символа
3 - 16383 символа

Сборка:
    std :: string str1;
    std :: string str2;
    std :: string str3;
    read_from_file("1.txt", str1);
    read_from_file("2.txt", str2);
    read_from_file("3.txt", str3);
    int a = 28;
    Block_16 b16;
    Block_1024 b1024;
    Block_16384 b163;
    Text t1;
    Text t2;
    Text t3;

    for (int i = 0; i < 16; i++){
        b16.data[i] = str1[i];
    }
    for (int i = 0; i < 1024; i++){
        b1024.data[i] = str2[i];
    }
    for (int i = 0; i < 16384; i++){
        b163.data[i] = str3[i];
    }

    b16.data[15] = '\0';
    b1024.data[1023] = '\0';
    b163.data[16383] = '\0';

    t1.data = (const char*)&str1;
    t1.size = 16;
    t2.data = (const char*)&str2;
    t2.size = 1024;
    t3.data = (const char*)&str3;
    t3.size = 16384;

Запуск:
    for (int p = 0; p < 3; p++){
        time [0 + p*9] = repeat(t1, ks[p], borrow, G, repeats);
        time [1 + p*9] = repeat(t2, ks[p], borrow, G, repeats);
        time [2 + p*9] = repeat(t3, ks[p], borrow, G, repeats);

        time [3 + p*9] = repeat(t1, ks[p], copy_each, G, repeats);
        time [4 + p*9] = repeat(t2, ks[p], copy_each, G, repeats);
        time [5 + p*9] = repeat(t3, ks[p], copy_each, G, repeats);

        time [6 + p*9] = repeat(t1, ks[p], copy_once, G, repeats);
        time [7 + p*9] = repeat(t2, ks[p], copy_once, G, repeats);
        time [8 + p*9] = repeat(t3, ks[p], copy_once, G, repeats);
    }

Характеристики компьютера:

компилятор msys,g++
ОС Windows 11
Процессор AMD Ryzen 5, 5600H, (6*3.3 ГГц)

оптимизации:
Опыт А: две оптимизации О0 и О2
Опыт В: О2
Работа с памятью: О2

исходные данные из файлов
число повторений 1000, 100 и 100