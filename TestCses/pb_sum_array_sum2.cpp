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

#define MY_TEST "c:\\tmp\\my_test.txt"
#define MY_OUT "c:\\tmp\\my_out.txt"

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (11).txt"
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

// count couple (x,y) avec x<y
static ll_type count_couples(const std::vector<int>& v1, const std::vector<int>& v2)
{
	ll_type count = 0;
	for (const auto x1 : v1)
	{
		auto lower = std::upper_bound(v2.begin(), v2.end(), x1);
		count += std::distance(lower, v2.end());
	}
	return count;
}

static ll_type count_couples0(const std::vector<int>& v1, const std::vector<int>& v2)
{
	ll_type count = 0;
	for (const auto x1 : v1)
	{
		for (const auto x2 : v2)
		{
			if (x1 < x2)
				count++;
		}
	}
	return count;
}

//https://cses.fi/problemset/task/1661
// Subarray Sums II
int pb_sub_array_sum2_main() {
	OPEN_IN;

	// n
	ll_type n, x;
	STREAM_IN >> n >> x;

	// Attention au cas du zero !!!

	std::map<ll_type, std::vector<int>> sums;
	sums[0].push_back(-1);
	ll_type current_sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		current_sum += k;
		sums[current_sum].push_back(i);
	}

	ll_type count = 0;
	for (auto s : sums)
	{
		// sj - si = x => sj = si + x et i<j !!
		auto it = sums.find(s.first + x);
		if (it != sums.end())
		{
			//int c1 = count_couples0(s.second, it->second);
			//int c2 = count_couples(s.second, it->second);
			//if (c1 != c2)
			//{
			//	int c3 = count_couples(s.second, it->second);
			//}
			count += count_couples(s.second, it->second);
		}
	}
	std::cout << count;

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif


#ifdef MY_INPUT
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[�s]" << std::endl;
	std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;
#endif

	return 0;
}
