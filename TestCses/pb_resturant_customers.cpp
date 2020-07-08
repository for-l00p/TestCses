#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <chrono>

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef long long int ull_type;

// https://cses.fi/problemset/task/1619
// Restaurant Customers
int pb17_main() {
	OPEN_IN;

	ull_type n;
	STREAM_IN >> n;

	// Decrire fonction par escalier (x,y)
	// Start = (-1,0)
	// => (-1,0), (a0,1), (b0,0) on doit avoir -1 < a0 < b0
	// List (xi,yi), rajouter (a,b)
	// Function (k) => trouver xi tq xi <= k < xi+1 , dichotomie ln(n)

	std::map<int, int> m;
	for (int i = 0; i < n; i++)
	{
		int a, b;
		STREAM_IN >> a >> b;
		m[a]++;
		m[b]--;
	}

	int max = -100;
	int h = 0;
	for (const auto& x : m)
	{
		h += x.second;
		max = std::max(max, h);
	}
	std::cout << max;

	return 0;
}
