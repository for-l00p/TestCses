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
    ull_type n;
    STREAM_IN >> n;

    if (n >= 1)
        std::cout << 0 << std::endl;

    if (n >= 2)
        std::cout << 6 << std::endl;

    if (n >= 3)
        std::cout << 28 << std::endl;

    for (ull_type k = 4; k <= n; k++)
    {
        ull_type nb = k * k;

        ull_type v = 0;
        //  4 Coins (2 attacks)
        v += 4 * 2;

        // 8 coin bord (3 attacks)
        v += 8 * 3;

        // 4 coins internes (4 attacks
        v += 4 * 4;

        ull_type l = k - 4;
        // Cases du bord (4 attacks)
        v += 4 * l * 4;

        // Cases du bord "2" (6 attacks)
        v += 4 * l * 6;

        //  cases internes (8 attacks)
        v += l * l * 8;

        std::cout << nb * (nb - 1) / 2 - v / 2 << std::endl;
    }

    return 0;
}