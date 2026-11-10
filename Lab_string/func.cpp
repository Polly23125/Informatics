#include <iostream>
#include <fstream>
#include <chrono>
#include <cstddef>
#include "header.h"

unsigned char text_short(const Text text){
    if (text.data == nullptr || text.size == 0){
        return 0;
    }
    unsigned char c = text.data[0];
    return c;
}
unsigned char text_short_link(const Text& text){
    return text_short (text);
}
unsigned char text_short_pointer(const Text* text){
    return text_short (*text);
}

unsigned char block_16_short(const Block_16 text){
    unsigned char c = text.data[0];
    return c;
}
unsigned char block_16_short_link(const Block_16& text){
    return block_16_short (text);
}
unsigned char block_16_short_pointer(const Block_16* text){
    return block_16_short (*text);
}

unsigned char block_1024_short(const Block_1024 text){
    unsigned char c = text.data[0];
    return c;
}
unsigned char block_1024_short_link(const Block_1024& text){
    return block_1024_short (text);
}
unsigned char block_1024_short_pointer(const Block_1024* text){
    return block_1024_short (*text);
}

unsigned char block_16384_short(const Block_16384 text){
    unsigned char c = text.data[0];
    return c;
}
unsigned char block_16384_short_link(const Block_16384& text){
    return block_16384_short (text);
}
unsigned char block_16384_short_pointer(const Block_16384* text){
    return block_16384_short (*text);
}

Stats analyze(const Text text) {
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

Stats text_full (const Text text){
    return analyze(text);
}
Stats text_full_link (const Text& text){
    return analyze(text);
}
Stats text_full_pointer (const Text* text){
    return analyze(*text);
}

Stats block_16_full (const Block_16 text){
    return analyze({text.data, 15});
}
Stats block_16_full_link (const Block_16& text){
    return analyze({text.data, 15});
}
Stats block_16_full_pointer (const Block_16* text){
    return analyze({(*text).data, 15});
}

Stats block_1024_full (const Block_1024 text){
    return analyze({text.data, 1023});
}
Stats block_1024_full_link (const Block_1024& text){
    return analyze({text.data, 1023});
}
Stats block_1024_full_pointer (const Block_1024* text){
    return analyze({(*text).data, 1023});
}

Stats block_16384_full (const Block_16384 text){
    return analyze({text.data, 16383});
}
Stats block_16384_full_link (const Block_16384& text){
    return analyze({text.data, 16383});
}
Stats block_16384_full_pointer (const Block_16384* text){
    return analyze({(*text).data, 16383});
}

char* clone_text(const Text text){
    char* cur =  new char[text.size +1];
    int size = text.size;
    for (int i; i < size; i++){
        cur[i] = text.data[i];
    }
    cur[size] = '\0';
    return cur;
}

unsigned int number(const int a){
    return(a+1);
}
unsigned int number_link(const int& a){
    return(a+1);
}
unsigned int number_pointer(const int* a){
    return(*a+1);
}

int read_from_file (const std :: string filename, std :: string& all_text){
    std::ifstream input(filename, std::ios::binary);
    if (!input) {
        return 1;
    }
    std::string line;
    while (std::getline(input, line)) {
        if (!line.empty() && line.back() == '\r') {
            line.pop_back();
        }
        line += '\n';
        all_text += line;
        Stats row = analyze({line.c_str(), line.size()});
        std::cout << row.words << ' ' << row.checksum << '\n';
    }
    return input.bad() ? 1 : 0;
}

double pass_number(int a, int repeats){
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += number(a);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_number_link(int a, int repeats){
    int& link_a = a;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += number_link(link_a);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_number_pointer(int a, int repeats){
    int* pointer_a = &a;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += number_pointer(pointer_a);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16_short(const Block_16 text, int repeats){
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16_short(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16_short_link(const Block_16 text, int repeats){
    const Block_16& link_text = text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16_short_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16_short_pointer(const Block_16 text, int repeats){
    const Block_16* pointer_text = &text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16_short_pointer(pointer_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_1024_short(const Block_1024 text, int repeats){
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += block_1024_short(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_1024_short_link(const Block_1024 text, int repeats){
    const Block_1024& link_text = text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += block_1024_short_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_1024_short_pointer(const Block_1024 text, int repeats){
    const Block_1024* link_text = &text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += block_1024_short_pointer(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16384_short(const Block_16384 text, int repeats){
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += block_16384_short(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16384_short_link(const Block_16384 text, int repeats){
    const Block_16384& link_text = text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += block_16384_short_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16384_short_pointer(const Block_16384 text, int repeats){
    const Block_16384* link_text = &text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        guard += block_16384_short_pointer(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16_full(const Block_16 text, int repeats){
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16_full(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16_full_link(const Block_16 text, int repeats){
    const Block_16& link_text = text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16_full_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16_full_pointer(const Block_16 text, int repeats){
    const Block_16* link_text = &text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16_full_pointer(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_1024_full(const Block_1024 text, int repeats){
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_1024_full(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_1024_full_link(const Block_1024 text, int repeats){
    const Block_1024& link_text = text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_1024_full_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_1024_full_pointer(const Block_1024 text, int repeats){
    const Block_1024* link_text = &text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_1024_full_pointer(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16384_full(const Block_16384 text, int repeats){
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16384_full(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16384_full_link(const Block_16384 text, int repeats){
    const Block_16384& link_text = text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16384_full_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_block_16384_full_pointer(const Block_16384 text, int repeats){
    const Block_16384* link_text = &text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        block_16384_full_pointer(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_text_short(const Text text, int repeats){
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        text_short(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_text_short_link(const Text text, int repeats){
    const Text& link_text = text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        text_short_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_text_short_pointer(const Text text, int repeats){
    const Text* pointer_text = &text;
    unsigned long long guard = 0;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        text_short_pointer(pointer_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_text_full(const Text text, int repeats){
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        text_full(text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_text_full_link(const Text text, int repeats){
    const Text& link_text = text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        text_full_link(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}

double pass_text_full_pointer(const Text text, int repeats){
    const Text* link_text = &text;
    auto start = std::chrono::steady_clock::now();
    for (std::size_t r = 0; r < repeats; ++r) {
        text_full_pointer(link_text);
    }
    auto finish = std::chrono::steady_clock::now();
    double seconds = std::chrono::duration<double>(finish - start).count();
    return seconds;
}





