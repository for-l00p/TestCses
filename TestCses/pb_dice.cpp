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
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (15).txt"
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

#define VALUE_MIN (INT64_MIN);
#define VALUE_MAX (INT64_MAX);
#define N_MAX 200000
#define MODULO (1000000007)

// Valuesfrom n=1 up to n=6
static ll_type first_values[6] = { 1, 2, 4, 8, 16, 32 };



// n(50) = 660 641 036

//https://cses.fi/problemset/task/1633
// Dice Combinations
int pb_dice_main() {
	OPEN_IN;

	// n
	ll_type n;
	STREAM_IN >> n;

	if (n < 7)
	{
		std::cout << first_values[n - 1];
		return 0;
	}

	std::queue<ll_type> queue;
	ll_type sum_v = 0;
	for (auto x : first_values)
	{
		queue.push(x);
		sum_v += x;
	}

	for (int i = 7; i < n; i++)
	{
		auto first = queue.front();
		queue.pop();
		queue.push(sum_v);
		sum_v += -first + sum_v;
		sum_v = sum_v % MODULO;
	}
	if (sum_v >= 0)
		std::cout << sum_v;
	else
		std::cout << sum_v + MODULO;

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
