#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>

#ifdef MY_INPUT
#define FILE_INPUT "c:\\tmp\\input.txt"
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

    for (int i = 0; i < n; i++)
    {
        // y = row, x = column
        ull_type y, x;
        STREAM_IN >> y >> x;
        //std::cout << y << " " << x << std::endl;

        // Valeur diag = k*(k+1)+1

        ull_type v;
        if (y > x)
        {
            v = (y-1) * y + 1;
            if (y % 2 == 0)
                v += (y - x);
            else
                v -= (y - x);
        }
        else
        {
            v = (x-1) * x + 1;
            if (x % 2 == 0)
                v -= (x - y);
            else
                v += (x - y);
        }
        std::cout << v << std::endl;
    }

    return 0;
}