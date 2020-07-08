#include <iostream>

// https://cses.fi/problemset/task/1068
// Weird algorithm
int pb1_main() {
    long long int n;
    std::cin >> n;
    std::cout << n;
    while (n != 1)
    {
        if (n % 2 == 0)
            n = n / 2;
        else
            n = 3 * n + 1;
        std::cout << " " << n;
    }
    return 0;
}