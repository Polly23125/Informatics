#ifndef HEADER_H
#define HEADER_H
//#include <cstddef>

struct Text {
    const char* data = nullptr;
    std::size_t size = 0;
};
struct Stats {
    std::size_t words = 0;
    unsigned long long checksum = 0;
};

struct Block {
    char data[1024]; 
};

Stats analyze(Text text);
int read_from_file (std :: string filename);


#endif