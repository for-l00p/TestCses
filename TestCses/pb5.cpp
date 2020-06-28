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

int pb5_main() {
    OPEN_IN;
    ull_type n;
    STREAM_IN >> n;

    switch (n)
    {
    case 2:
    case 3:
        std::cout << "NO SOLUTION";
        break;

    default:
        for (ull_type i = 1; i <= n; i++)
            if (i % 2 == 0)
                std::cout << i << " ";
        for (ull_type i = 1; i <= n; i++)
            if (i % 2 == 1)
                std::cout << i << " ";
    }

    return 0;
}