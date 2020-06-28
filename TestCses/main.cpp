#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef long long int ull_type;

int main() {
    OPEN_IN;
    std::string s;
    STREAM_IN >> s;
   
    return 0;
}