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

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (5).txt"
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input_time_limit.txt"
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

//https://cses.fi/problemset/task/1641
// Sum of Three Values
int main() {
	OPEN_IN;

	// n + target value
	ll_type n, x;
	STREAM_IN >> n >> x;

	std::vector<ll_type> values(n);
	for (int i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		values[i] = k;
	}

}
