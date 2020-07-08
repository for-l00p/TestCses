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

//https://cses.fi/problemset/task/1754
// coin piles
int pb11_main() {
    OPEN_IN;
    ull_type n;
    STREAM_IN >> n;

    for (int i = 0; i < n; i++)
    {
        ull_type a, b;
        STREAM_IN >> a >> b;
        //std::cout << a << " " << b << std::endl;

        // On enleve -2, -1 ou -1, -2 => (a+b)-3
        // on doit avoir a+b = 0 [3]
        // on doit aussi avoir max <= 2*min
        ull_type r = (a + b) % 3;
        if (r == 0)
        {
            ull_type min = std::min(a, b);
            ull_type max = std::max(a, b);
            if (max <= 2 * min)
            {
                std::cout << "YES" << std::endl;
            }
            else
                std::cout << "NO" << std::endl;
        }
        else
        {
            std::cout << "NO" << std::endl;
        }
    }

    return 0;
}