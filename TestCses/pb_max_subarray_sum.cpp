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
//#define FILE_INPUT "input.txt"
#define FILE_INPUT "c:\\tmp\\test_input (2).txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef std::int64_t ll_type;

#define VALUE_MIN (INT64_MIN);
#define VALUE_MAX (INT64_MAX);
#define N_MAX 200000

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

int pb_max_sum_array_main() {

	//test_basic(); return 0;

	OPEN_IN;

	std::size_t n;
	STREAM_IN >> n;

	ll_type sum = 0;
	std::vector<ll_type> v_sum;
	for (std::size_t i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		sum += k;
		v_sum.push_back(sum);
	}

	// On cherche 2 vecteurs
	// v_min[i]=min(xk, k<=i)
	// v_max[i]=max(xk, k>=i)

	ll_type min = VALUE_MAX;
	std::vector<ll_type> v_min(n);
	for (std::size_t i = 0; i < n; i++)
	{
		min = std::min(min, v_sum[i]);
		v_min[i] = min;
	}

	ll_type max = VALUE_MIN;
	std::vector<ll_type> v_max(n);
	for (ll_type i = n - 1; i >= 0; i--)
	{
		max = std::max(max, v_sum[i]);
		v_max[i] = max;
	}

	// max of diffs
	ll_type delta_max = VALUE_MIN;
	for (ll_type i = 1; i < n; i++)
		delta_max = std::max(delta_max, v_max[i] - v_min[i - 1]);
	delta_max = std::max(delta_max, v_max[0] - 0);
	std::cout << delta_max;
}
