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

ull_type get_exponent(int n, int p)
{
    ull_type res = 0;
    ull_type div = p;
    do
    {
        res += n / div;
        div *= p;
    } while (div < n);
    return res;
}

int pb10_main() {
    OPEN_IN;
    ull_type n;
    STREAM_IN >> n;

    // trailing zeros of n!
    // n! = 2^A.5^B.Q
    // min(A,B)

    // n!= 2*3*4*5*6
    //     1   2   1
    // v2 = [n/2] + [n/4]+ [n/8] + ...
    // v5 = [n/5] + [n/25]+ [n/125] + ...

    //auto v2 = get_exponent(n, 2);
    auto v5 = get_exponent(n, 5);

    std::cout << v5;

    return 0;
}