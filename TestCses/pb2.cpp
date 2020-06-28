#include <iostream>

int pb2_main() {
    long long int n;
    std::cin >> n;
    int v;
    long long sum = 0;
    for (int i = 1; i < n; i++)
    {
        std::cin >> v;
        sum += v;
    }
    std::cout << n * (n + 1) / 2 - sum;
    return 0;
}