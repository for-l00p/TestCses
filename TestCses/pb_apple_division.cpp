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

//https://cses.fi/problemset/task/1623
// Apple division
int pb14_main() {
    OPEN_IN;
    ull_type n;
    STREAM_IN >> n;

    std::vector<ull_type> v(n);
    ull_type sum = 0;
    for (int i = 0; i < n; i++)
    {
        STREAM_IN >> v[i];
        sum += v[i];
    }
    std::sort(v.begin(), v.end());

    // Egalite des 2 groups => sum even
    // si sum odd , min possible = 1

    // Trouver subset le plus proche de sum/2
    // partie de S = 2^n: 2^20

    ull_type delta = 10000000000;
    ull_type  N = ((ull_type)1) << n;
    for (ull_type k = 0; k < N; k++)
    {
        ull_type s = 0;
        ull_type m = k;
        for (ull_type i = 0; i < n; i++)
        {
            if (m & 1)
                s += v[i];
            m >>= 1;
        }
        delta = std::min(delta, std::abs(sum - 2 * s));
    }
    std::cout << delta;

    return 0;
}
