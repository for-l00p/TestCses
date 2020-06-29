#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

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
    ull_type n;
    STREAM_IN >> n;


    return 0;
}
