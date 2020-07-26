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

//https://cses.fi/problemset/task/1637
// Removing Digits
int pb_removing_digits_main() {
	OPEN_IN;

	// n
	ll_type n;
	STREAM_IN >> n;

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif

	std::vector<int> mins(n + 1);
	mins[0] = 0;
	for (int i = 1; i <= 9; i++)
		mins[i] = 1;

	for (int i = 10; i <= n; i++)
	{
		int min = VALUE32_MAX;
		int power10 = 1;
		while (power10 <= i)
		{
			int digit = (i / power10) % 10;
			if (digit > 0)
			{
				int test_number = i - digit;
				min = std::min(min, mins[test_number]);
			}
			power10 *= 10;
		}
		mins[i] = min + 1;
	}
	std::cout << mins[n];

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;
#endif

	return 0;
}
