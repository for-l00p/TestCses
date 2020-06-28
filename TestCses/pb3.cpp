#include <iostream>
#include <algorithm>
#include <string>

int pb3_main() {
    long long int n;
    std::string s;
    std::cin >> s;

    int p = 0;
    size_t max = 1;
    for (size_t i = 0; i < s.length(); i++)
    {
        if (s[i] != s[p])
        {
            max = std::max(max, i - p);
            p = i;
        }
    }
    max = std::max(max, s.length() - p);
    std::cout << max;
    return 0;
}