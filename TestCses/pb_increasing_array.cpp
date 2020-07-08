#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#ifdef MY_INPUT
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file("c:\\tmp\\input.txt")
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef long long int ull_type;

// https://cses.fi/problemset/task/1094
// Increasing Array
int pb4_main() {
    OPEN_IN;

    ull_type n;
    STREAM_IN >> n;
    ull_type prev = 0;
    ull_type max_prev = 0;
    ull_type delta_sum = 0;
    for (ull_type i = 0; i < n; i++)
    {
        ull_type xi;
        STREAM_IN >> xi;
        delta_sum += std::max((ull_type)0, max_prev - xi);
        prev = xi;
        max_prev = std::max(max_prev, prev);
    }
    std::cout << delta_sum;
    return 0;
}