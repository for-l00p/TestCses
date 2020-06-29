#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>

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
    std::string s;
    STREAM_IN >> s;
   
    std::vector<int> v(26);
    // only zero or one letter with count odd
    for (int i = 0; i < s.length(); i++)
    {
        int k = s[i] - 'A';
        v[k]++;
    }

    std::string left;
    std::string center;
    std::string right;
    int count_odd = 0;
    for (int i = 0; i < v.size(); i++)
    {
        auto chunk = std::string(v[i] / 2, 'A' + i);
        if (v[i] % 2 == 1)
        {
            if (center.length() > 0)
            {
                std::cout << "NO SOLUTION";
                return 1;
            }
            center = 'A' + i;
        }
        left = chunk + left;
        right = right + chunk;
    }
    std::cout << left << center << right;
    return 0;
}