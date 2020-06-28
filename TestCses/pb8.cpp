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

int pb8_main() {
    OPEN_IN;
    ull_type n;
    STREAM_IN >> n;

    // Sum 1, n = n*(n+1)/2 qui doit etre pair
    // => n*(n+1) = 0 [4]
    // => n = 0 [4] ou n = -1 = 3 [4]

    ull_type r = n % 4;
    if (r == 0)
    {
        std::cout << "YES" << std::endl;
        // 4 parties egales (1)/(2)/(3)/(4)
        // (1)+(4) et (2)+(3)
        ull_type k = n / 4;
        std::cout << 2 * k << std::endl;
        for (ull_type i = 0; i < k; i++)
            std::cout << i + 1 << " " << n - i << " ";
        std::cout << std::endl;
        std::cout << 2 * k << std::endl;
        for (ull_type i = k; i < 2 * k; i++)
            std::cout << i + 1 << " " << n - i << " ";
    }
    else if (r == 3)
    {
        std::cout << "YES" << std::endl;
        std::cout << 2 + (n - 3) / 2 << std::endl;
        std::cout << "1 2 ";
        for (ull_type i = 0; i < (n - 3) / 4; i++)
            std::cout << 4 * (i + 1) << " " << 4 * (i + 1) + 3 << " ";
        std::cout << std::endl;
        std::cout << 1 + (n - 3) / 2 << std::endl;
        std::cout << "3 ";
        for (ull_type i = 0; i < (n - 3) / 4; i++)
            std::cout << 4 * (i + 1) + 1 << " " << 4 * (i + 1) + 2 << " ";
    }
    else
    {
        std::cout << "NO";
    }

    return 0;
}