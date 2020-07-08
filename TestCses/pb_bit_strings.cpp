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

#define MODULO 1000000007

//https://cses.fi/problemset/task/1617
// Bit strings
int pb9_main() {
    OPEN_IN;
    ull_type n;
    STREAM_IN >> n;

    ull_type m = 1;
    for (int i = 0; i < n; i++)
        m = (2 * m) % MODULO;
    std::cout << m;

    return 0;
}