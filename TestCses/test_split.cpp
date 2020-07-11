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

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define FILE_INPUT "c:\\tmp\\test_input (1).txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

#define VALUE_MIN -2000000000;
#define VALUE_MAX +2000000000;
#define N_MAX 200000

typedef std::int64_t ll_type;

//https://cses.fi/problemset/task/1643
// Maximum Subarray Sum


static void max_diff(const std::vector<ll_type>& v0)
{
	std::cout << "vector size: " << v0.size() << std::endl;

	ll_type s = 0;
	std::vector<ll_type> sum;
	sum.push_back(0);
	for (std::size_t i = 0; i < v0.size(); i++)
	{
		s += v0[i];
		sum.push_back(s);
	}

	ll_type max = VALUE_MIN;
	ll_type pos_i = -1;
	ll_type pos_j = -1;
	for (std::size_t i = 0; i < sum.size(); i++)
		for (std::size_t j = i + 1; j < sum.size(); j++)
		{
			auto delta = sum[j] - sum[i];
			if (delta > max)
			{
				max = delta;
				pos_i = i;
				pos_j = j;
			}
		}
	std::cout << max << std::endl;
	std::cout << pos_i << " " << pos_j << std::endl;
}

// 231 210 956 017
// 29815 99839
static int test_basic()
{
	OPEN_IN;

	std::size_t n;
	STREAM_IN >> n;

	ll_type k;
	std::vector<ll_type> v;
	for (std::size_t i = 0; i < n; i++)
	{
		STREAM_IN >> k;
		v.push_back(k);
	}
	max_diff(v);

	return 0;
}


std::pair<int, int> get_max_array(const std::vector<ll_type>& sum, std::size_t start, std::size_t end)
{
	if (end <= start)
		throw std::runtime_error("Invalid case");
	else if (end == start + 1)
		return std::make_pair(start, end);
	else if (end == start + 2)
	{
		auto a = sum[start + 1] - sum[start];
		auto b = sum[end] - sum[start + 1];
		if (a+b>=a && a+b>=b)
			return std::make_pair(start, end);
		if (a >= a+b && a >= b)
			return std::make_pair(start, start+1);
		if (b >= a + b && b >= a)
			return std::make_pair(start+1, start + 2);
		throw std::runtime_error("Invalid case 2");
	}
	else
	{
		auto mid = (start + end) / 2;
		auto left = get_max_array(sum, start, mid);
		auto rigth = get_max_array(sum, mid, end);

	}
}

int test_split_main() {
	OPEN_IN;

	std::size_t n;
	STREAM_IN >> n;

	ll_type current_sum = 0;
	std::vector<ll_type> sum;
	sum.push_back(0);
	for (std::size_t i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		current_sum += k;
		sum.push_back(current_sum);
	}

	auto res = get_max_array(sum, 0, sum.size() - 1);




	return 0;
}
