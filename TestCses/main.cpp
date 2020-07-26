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

#define MY_TEST "c:\\tmp\\my_test.txt"
#define MY_OUT "c:\\tmp\\my_out.txt"

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (18).txt"
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

// 187 405 784

//https://cses.fi/problemset/task/1636
// Coin Combinations II
int main() {
	OPEN_IN;

	// n
	ll_type n, x;
	STREAM_IN >> n >> x;

	std::set<int> c;
	for (int i = 0; i < n; i++)
	{
		int k;
		STREAM_IN >> k;
		c.insert(k);
	}

//	std::cout << solve_count(x);

	// sur chaque point map<last coin, count>
	// x = 33: (1,17) (5,6)...
	// x = 34: (1,29) (5,7)...

	std::vector<std::map<int, int>> ways(x + 1);
	ways[0][0]=1;
	for (int k = 1; k <= x; k++)
	{
		if (k % 1000 == 0)
			std::cout << k << std::endl;
		std::map<int, int> counts;
		for (auto v : c)
		{
			if (k - v >= 0)
			{
				for (const auto& w : ways[k - v])
				{
					if (w.first <= v)
						counts[v] = (counts[v] + w.second) % MODULO;
				}
			}
		}
		ways[k] = counts;
	}
	int total = 0;
	for (const auto& w : ways[x])
		total = (total + w.second) % MODULO;
	std::cout << total;

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif


#ifdef MY_INPUT
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;
#endif

	return 0;
}
