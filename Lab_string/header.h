#ifndef HEADER_H
#define HEADER_H
#include <cstddef>

struct Text {
    const char* data = nullptr;
    std::size_t size = 0;
};

struct Stats {
    std::size_t words = 0;
    unsigned long long checksum = 0;
};

struct Block_16 {
    char data[16]; 
};

struct Block_1024 {
    char data[1024]; 
};

struct Block_16384 {
    char data[16384]; 
};

unsigned char text_short(const Text text);
unsigned char text_short_link(const Text& text);
unsigned char text_short_pointer(const Text* text);

unsigned char block_16_short(const Block_16 text);
unsigned char block_16_short_link(const Block_16& text);
unsigned char block_16_short_pointer(const Block_16* text);

unsigned char block_1024_short(const Block_1024 text);
unsigned char block_1024_short_link(const Block_1024& text);
unsigned char block_1024_short_pointer(const Block_1024* text);

unsigned char block_16384_short(const Block_16384 text);
unsigned char block_16384_short_link(const Block_16384& text);
unsigned char block_16384_short_pointer(const Block_16384* text);

Stats analyze(Text text);

Stats text_full (const Text text);
Stats text_full_link (const Text& text);
Stats text_full_pointer (const Text* text);

Stats block_16_full (const Block_16 text);
Stats block_16_full_link (const Block_16& text);
Stats block_16_full_pointer (const Block_16* text);

Stats block_1024_full (const Block_1024 text);
Stats block_1024_full_link (const Block_1024& text);
Stats block_1024_full_pointer (const Block_1024* text);

Stats block_16384_full (const Block_16384 text);
Stats block_16384_full_link (const Block_16384& text);
Stats block_16384_full_pointer (const Block_16384* text);

unsigned int number(const int a);
unsigned int number_link(const int& a);
unsigned int number_pointer(const int* a);

char* clone_text(const Text text);

int read_from_file (const std :: string filename, std :: string& all_text);

double pass_number(int a, int repeats);
double pass_number_link(int a, int repeats);
double pass_number_pointer(int a, int repeats);

double pass_block_16_short(const Block_16 text, int repeats);
double pass_block_16_short_link(const Block_16 text, int repeats);
double pass_block_16_short_pointer(const Block_16 text, int repeats);

double pass_block_1024_short(const Block_1024 text, int repeats);
double pass_block_1024_short_link(const Block_1024 text, int repeats);
double pass_block_1024_short_pointer(const Block_1024 text, int repeats);

double pass_block_16384_short(const Block_16384 text, int repeats);
double pass_block_16384_short_link(const Block_16384 text, int repeats);
double pass_block_16384_short_pointer(const Block_16384 text, int repeats);

double pass_text_short(const Text text, int repeats);
double pass_text_short_link(const Text text, int repeats);
double pass_text_short_pointer(const Text text, int repeats);

double pass_block_16_full(const Block_16 text, int repeats);
double pass_block_16_full_link(const Block_16 text, int repeats);
double pass_block_16_full_pointer(const Block_16 text, int repeats);

double pass_block_1024_full(const Block_1024 text, int repeats);
double pass_block_1024_full_link(const Block_1024 text, int repeats);
double pass_block_1024_full_pointer(const Block_1024 text, int repeats);

double pass_block_16384_full(const Block_16384 text, int repeats);
double pass_block_16384_full_link(const Block_16384 text, int repeats);
double pass_block_16384_full_pointer(const Block_16384 text, int repeats);

double pass_text_full(const Text text, int repeats);
double pass_text_full_link(const Text text, int repeats);
double pass_text_full_pointer(const Text text, int repeats);


#endif