#include <iostream>
#include <fstream>
#include <chrono>
#include <cstddef>
#include "header.h"

int main(){
    std :: ofstream f("1.csv", std :: ios::out); 
    f << "experiment" << "," << "length" << "," << "mode" << "," << "work" << "," << "repeats" << "opt" << "," << "result" << std :: endl;

    std :: string str1;
    std :: string str2;
    std :: string str3;
    read_from_file("1.txt", str1);
    read_from_file("2.txt", str2);
    read_from_file("3.txt", str3);

    int r = 1000;
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

    double time[50];

    time [0] = pass_number(a,r);
    time [1] = pass_number_link(a,r);
    time [2] = pass_number_pointer(a,r);
    
    time [3] = pass_block_16_short(b16,r);
    time [4] = pass_block_16_short_link(b16,r);
    time [5] = pass_block_16_short_pointer(b16,r);

    time [6] = pass_block_1024_short(b1024,r);
    time [7] = pass_block_1024_short_link(b1024,r);
    time [8] = pass_block_1024_short_pointer(b1024,r);

    time [9] = pass_block_16384_short(b163,r);
    time [10] = pass_block_16384_short_link(b163,r);
    time [11] = pass_block_16384_short_pointer(b163,r);

    time [12] = pass_block_16_full(b16,r);
    time [13] = pass_block_16_full_link(b16,r);
    time [14] = pass_block_16_full_pointer(b16,r);

    time [15] = pass_block_1024_full(b1024,r);
    time [16] = pass_block_1024_full_link(b1024,r);
    time [17] = pass_block_1024_full_pointer(b1024,r);

    time [18] = pass_block_16384_full(b163,r);
    time [19] = pass_block_16384_full_link(b163,r);
    time [20] = pass_block_16384_full_pointer(b163,r);

    time [21] = pass_text_short(t1,r);
    time [22] = pass_text_short_link(t1,r);
    time [23] = pass_text_short_pointer(t1,r);

    time [24] = pass_text_short(t2,r);
    time [25] = pass_text_short_link(t2,r);
    time [26] = pass_text_short_pointer(t2,r);

    time [27] = pass_text_short(t3,r);
    time [28] = pass_text_short_link(t3,r);
    time [29] = pass_text_short_pointer(t3,r);

    time [30] = pass_text_full(t1,r);
    time [31] = pass_text_full_link(t1,r);
    time [32] = pass_text_full_pointer(t1,r);

    time [33] = pass_text_full(t1,r);
    time [34] = pass_text_full_link(t1,r);
    time [35] = pass_text_full_pointer(t1,r);

    time [36] = pass_text_full(t1,r);
    time [37] = pass_text_full_link(t1,r);
    time [38] = pass_text_full_pointer(t1,r);

    f << "scalar" << "," << "0" << "," << "value" << "," << "-" << "," << "1000" << "O0" << "," << time[0] << std :: endl;
    f << "scalar" << "," << "0" << "," << "link" << "," << "-" << "," << "1000" << "O0" << "," << time[1] << std :: endl;
    f << "scalar" << "," << "0" << "," << "pointer" << "," << "-" << "," << "1000" << "O0" << "," << time[2] << std :: endl;

    f << "block16" << "," << "15" << "," << "value" << "," << "short" << "," << "1000" << "O0" << "," << time[3] << std :: endl;
    f << "block16" << "," << "15" << "," << "link" << "," << "short" << "," << "1000" << "O0" << "," << time[4] << std :: endl;
    f << "block16" << "," << "15" << "," << "pointer" << "," << "short" << "," << "1000" << "O0" << "," << time[5] << std :: endl;

    
    f << "block1024" << "," << "1023" << "," << "value" << "," << "short" << "," << "1000" << "O0" << "," << time[6] << std :: endl;
    f << "block1024" << "," << "1023" << "," << "link" << "," << "short" << "," << "1000" << "O0" << "," << time[7] << std :: endl;
    f << "block1024" << "," << "1023" << "," << "pointer" << "," << "short" << "," << "1000" << "O0" << "," << time[8] << std :: endl;

    
    f << "block16384" << "," << "16383" << "," << "value" << "," << "short" << "," << "1000" << "O0" << "," << time[9] << std :: endl;
    f << "block16384" << "," << "16383" << "," << "link" << "," << "short" << "," << "1000" << "O0" << "," << time[10] << std :: endl;
    f << "block16384" << "," << "16383" << "," << "pointer" << "," << "short" << "," << "1000" << "O0" << "," << time[11] << std :: endl;
    
    f << "block16" << "," << "15" << "," << "value" << "," << "full" << "," << "1000" << "O0" << "," << time[12] << std :: endl;
    f << "block16" << "," << "15" << "," << "link" << "," << "full" << "," << "1000" << "O0" << "," << time[13] << std :: endl;
    f << "block16" << "," << "15" << "," << "pointer" << "," << "full" << "," << "1000" << "O0" << "," << time[14] << std :: endl;

    
    f << "block1024" << "," << "1023" << "," << "value" << "," << "full" << "," << "1000" << "O0" << "," << time[15] << std :: endl;
    f << "block1024" << "," << "1023" << "," << "link" << "," << "full" << "," << "1000" << "O0" << "," << time[16] << std :: endl;
    f << "block1024" << "," << "1023" << "," << "pointer" << "," << "full" << "," << "1000" << "O0" << "," << time[17] << std :: endl;

    
    f << "block16384" << "," << "16383" << "," << "value" << "," << "full" << "," << "1000" << "O0" << "," << time[18] << std :: endl;
    f << "block16384" << "," << "16383" << "," << "link" << "," << "full" << "," << "1000" << "O0" << "," << time[19] << std :: endl;
    f << "block16384" << "," << "16383" << "," << "pointer" << "," << "full" << "," << "1000" << "O0" << "," << time[20] << std :: endl;
    
    f << "text" << "," << "15" << "," << "value" << "," << "short" << "," << "1000" << "O0" << "," << time[21] << std :: endl;
    f << "text" << "," << "15" << "," << "link" << "," << "short" << "," << "1000" << "O0" << "," << time[22] << std :: endl;
    f << "text" << "," << "15" << "," << "pointer" << "," << "short" << "," << "1000" << "O0" << "," << time[23] << std :: endl;

    
    f << "text" << "," << "1023" << "," << "value" << "," << "short" << "," << "1000" << "O0" << "," << time[24] << std :: endl;
    f << "text" << "," << "1023" << "," << "link" << "," << "short" << "," << "1000" << "O0" << "," << time[25] << std :: endl;
    f << "text" << "," << "1023" << "," << "pointer" << "," << "short" << "," << "1000" << "O0" << "," << time[26] << std :: endl;

    
    f << "text" << "," << "16383" << "," << "value" << "," << "short" << "," << "1000" << "O0" << "," << time[27] << std :: endl;
    f << "text" << "," << "16383" << "," << "link" << "," << "short" << "," << "1000" << "O0" << "," << time[28] << std :: endl;
    f << "text" << "," << "16383" << "," << "pointer" << "," << "short" << "," << "1000" << "O0" << "," << time[29] << std :: endl;
    
    f << "text" << "," << "15" << "," << "value" << "," << "full" << "," << "1000" << "O0" << "," << time[30] << std :: endl;
    f << "text" << "," << "15" << "," << "link" << "," << "full" << "," << "1000" << "O0" << "," << time[31] << std :: endl;
    f << "text" << "," << "15" << "," << "pointer" << "," << "full" << "," << "1000" << "O0" << "," << time[32] << std :: endl;

    
    f << "text" << "," << "1023" << "," << "value" << "," << "full" << "," << "1000" << "O0" << "," << time[33] << std :: endl;
    f << "text" << "," << "1023" << "," << "link" << "," << "full" << "," << "1000" << "O0" << "," << time[34] << std :: endl;
    f << "text" << "," << "1023" << "," << "pointer" << "," << "full" << "," << "1000" << "O0" << "," << time[35] << std :: endl;

    
    f << "text" << "," << "16383" << "," << "value" << "," << "full" << "," << "1000" << "O0" << "," << time[36] << std :: endl;
    f << "text" << "," << "16383" << "," << "link" << "," << "full" << "," << "1000" << "O0" << "," << time[37] << std :: endl;
    f << "text" << "," << "16383" << "," << "pointer" << "," << "full" << "," << "1000" << "O0" << "," << time[38] << std :: endl;
}