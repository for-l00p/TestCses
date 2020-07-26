#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <chrono>
#include <cassert>
#include <stack>
#include <cstdlib>
#include <random>
#include <functional>
#include <queue>
#include <cstring>

#define MY_TEST "c:\\tmp\\my_test.txt"
#define MY_OUT "c:\\tmp\\my_out.txt"

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (19).txt"
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input_time_limit.txt"
//#define FILE_INPUT MY_TEST
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#define MY_DEBUG(x) x
#else
#define STREAM_IN std::cin
#define OPEN_IN
#define MY_DEBUG(x)
#endif

typedef std::int64_t ll_type;

#define VALUE_MIN (INT64_MIN)
#define VALUE_MAX (INT64_MAX)
#define VALUE32_MIN (INT32_MIN)
#define VALUE32_MAX (INT32_MAX)
#define N_MAX 200000
#define MODULO (1000000007)

//https://cses.fi/problemset/task/1638
// Grid Paths
int pb_grid_paths_main() {
	OPEN_IN;

	// n
	ll_type n;
	STREAM_IN >> n;

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif

	auto g = new ll_type[n * n];
	std::memset(g, 0, n * n * sizeof(ll_type));
	for (ll_type i = 0; i < n; i++)
	{
		std::string s;
		STREAM_IN >> s;
		for (int j = 0; j < n; j++)
		{
			if (s[j] == '*')
				g[i * n + j] = -1;
		}
	}
	if (g[0 * n + 0] == -1 || g[(n - 1) * n + (n - 1)] == -1)
	{
		std::cout << "0";
		return 0;
	}

	g[0 * n + 0] = 1;


	for (ll_type k = 1; k <= 2 * n - 2; k++)
	{
		for (ll_type i = 0; i < n; i++)
		{
			ll_type j = k - i;
			if (j >= 0 && j < n)
			{
				switch (g[i * n + j])
				{
				case 0:
				{
					ll_type sum = 0;
					if (j - 1 >= 0)
					{
						auto v = g[i * n + (j - 1)];
						if (v > 0)
							sum = (sum + v) % MODULO;
					}
					if (i - 1 >= 0)
					{
						auto v = g[(i - 1) * n + j];
						if (v > 0)
							sum = (sum + v) % MODULO;
					}
					g[i * n + j] = sum;
				}
				break;

				case -1:
					break;

				default:
					throw std::runtime_error("Invalid case?");
				}
			}
		}
	}
	std::cout << g[(n - 1) * n + (n - 1)];


#ifdef MY_INPUT
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;
#endif

	return 0;
}
