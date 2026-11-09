#include <iostream>
#include <fstream>
#include <chrono>
#include <cstddef>
#include "header.h"

Stats analyze(Text text) {
    Stats result;
    bool inside_word = false;
    for (std::size_t i = 0; i < text.size; ++i) {
        char c = text.data[i];
        result.checksum += (unsigned char)c;
        if (c == ' ' || c == '\t') {
            inside_word = false;
        } else if (!inside_word) {
            ++result.words;
            inside_word = true;
        }
    }
    return result;
}

int read_from_file (std :: string filename){
    std::ifstream input(filename, std::ios::binary);
    if (!input) {
        return 1;
    }
    std::string line, all_text;
    while (std::getline(input, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        Stats row = analyze({line.c_str(), line.size()});
        std::cout << row.words << ' ' << row.checksum << '\n';
    }
    return input.bad() ? 1 : 0;
}


