#include <iostream>
#include <fstream>
#include "header.h"

int main(){
    std :: ofstream f("4.csv", std :: ios::out); 
    f << "length" << "," << "mode" << "," << "repeats" << "," << "uses"<< "," << "allocations" << "," << "copied_bytes" << "," << "peak_extra_bytes" << std :: endl;

    std :: string str1;
    std :: string str2;
    std :: string str3;
    read_from_file("1.txt", str1);
    read_from_file("2.txt", str2);
    read_from_file("3.txt", str3);

    Text t1;
    Text t2;
    Text t3;

    t1.data = str1.data();
    t1.size = 16;
    t2.data = str2.data();
    t2.size = 1024;
    t3.data = str3.data();
    t3.size = 16384;

    int ks[] = {1, 10, 100};
    int G = 100;

    mem result [30];

    for (int p = 0; p < 3; p++){
        result [0 + p*9] = repeat_mem(t1, ks[p], borrow_mem, G);
        result [1 + p*9] = repeat_mem(t2, ks[p], borrow_mem, G);
        result [2 + p*9] = repeat_mem(t3, ks[p], borrow_mem, G);

        result [3 + p*9] = repeat_mem(t1, ks[p], copy_each_mem, G);
        result [4 + p*9] = repeat_mem(t2, ks[p], copy_each_mem, G);
        result [5 + p*9] = repeat_mem(t3, ks[p], copy_each_mem, G);

        result [6 + p*9] = repeat_mem(t1, ks[p], copy_once_mem, G);
        result [7 + p*9] = repeat_mem(t2, ks[p], copy_once_mem, G);
        result [8 + p*9] = repeat_mem(t3, ks[p], copy_once_mem, G);
    }

    f << "15" << "," << "borrow" << "," << "1_100"  << "," << "1" << "," << result[0].counter << "," << result[0].copys << "," << result[0].elem << std :: endl;
    f << "1023" << "," << "borrow" << "," << "1_100" << "," << "1" << "," << result[1].counter << "," << result[1].copys << "," << result[1].elem << std :: endl;
    f << "16383" << "," << "borrow" << "," << "1_100" << "," << "1" << "," << result[2].counter << "," << result[2].copys << "," << result[2].elem << std :: endl;

    f << "15" << "," << "copy_each" << "," << "1_100"  << "," << "1" << "," << result[3].counter << "," << result[3].copys << "," << result[3].elem << std :: endl;
    f << "1023" << "," << "copy_each" << "," << "1_100" << "," << "1" << "," << result[4].counter << "," << result[4].copys << "," << result[4].elem << std :: endl;
    f << "16383" << "," << "copy_each" << "," << "1_100" << "," << "1" << "," << result[5].counter << "," << result[5].copys << "," << result[5].elem << std :: endl;

    f << "15" << "," << "copy_once" << "," << "1_100"  << "," << "1" << "," << result[6].counter << "," << result[6].copys << "," << result[6].elem << std :: endl;
    f << "1023" << "," << "copy_once" << "," << "1_100" << "," << "1" << "," << result[7].counter << "," << result[7].copys << "," << result[7].elem << std :: endl;
    f << "16383" << "," << "copy_once" << "," << "1_100" << "," << "1" << "," << result[8].counter << "," << result[8].copys << "," << result[8].elem << std :: endl;

    f << "15" << "," << "borrow" << "," << "10_100"  << "," << "10" << "," << result[9].counter << "," << result[9].copys << "," << result[9].elem << std :: endl;
    f << "1023" << "," << "borrow" << "," << "10_100" << "," << "10" << "," << result[10].counter << "," << result[10].copys << "," << result[10].elem << std :: endl;
    f << "16383" << "," << "borrow" << "," << "10_100" << "," << "10" << "," << result[11].counter << "," << result[11].copys << "," << result[11].elem << std :: endl;

    f << "15" << "," << "copy_each" << "," << "10_100"  << "," << "10" << "," << result[12].counter << "," << result[12].copys << "," << result[12].elem << std :: endl;
    f << "1023" << "," << "copy_each" << "," << "10_100" << "," << "10" << "," << result[13].counter << "," << result[13].copys << "," << result[13].elem << std :: endl;
    f << "16383" << "," << "copy_each" << "," << "10_100" << "," << "10" << "," << result[14].counter << "," << result[14].copys << "," << result[14].elem << std :: endl;

    f << "15" << "," << "copy_once" << "," << "10_100"  << "," << "10" << "," << result[15].counter << "," << result[15].copys << "," << result[15].elem << std :: endl;
    f << "1023" << "," << "copy_once" << "," << "10_100" << "," << "10" << "," << result[16].counter << "," << result[16].copys << "," << result[16].elem << std :: endl;
    f << "16383" << "," << "copy_once" << "," << "10_100" << "," << "10" << "," << result[17].counter << "," << result[17].copys << "," << result[17].elem << std :: endl;

    f << "15" << "," << "borrow" << "," << "100_100"  << "," << "100" << "," << result[18].counter << "," << result[18].copys << "," << result[18].elem << std :: endl;
    f << "1023" << "," << "borrow" << "," << "100_100" << "," << "100" << "," << result[19].counter << "," << result[19].copys << "," << result[19].elem << std :: endl;
    f << "16383" << "," << "borrow" << "," << "100_100" << "," << "100" << "," << result[20].counter << "," << result[20].copys << "," << result[20].elem << std :: endl;

    f << "15" << "," << "copy_each" << "," << "100_100"  << "," << "100" << "," << result[21].counter << "," << result[21].copys << "," << result[21].elem << std :: endl;
    f << "1023" << "," << "copy_each" << "," << "100_100" << "," << "100" << "," << result[22].counter << "," << result[22].copys << "," << result[22].elem << std :: endl;
    f << "16383" << "," << "copy_each" << "," << "100_100" << "," << "100" << "," << result[23].counter << "," << result[23].copys << "," << result[23].elem << std :: endl;

    f << "15" << "," << "copy_once" << "," << "100_100_20"  << "," << "100" << "," << result[24].counter << "," << result[24].copys << "," << result[24].elem << std :: endl;
    f << "1023" << "," << "copy_once" << "," << "100_100_20" << "," << "100" << "," << result[25].counter << "," << result[25].copys << "," << result[25].elem << std :: endl;
    f << "16383" << "," << "copy_once" << "," << "100_100_20" << "," << "100" << "," << result[26].counter << "," << result[26].copys << "," << result[26].elem << std :: endl;
    f.close();
}