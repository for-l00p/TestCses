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


//https://cses.fi/problemset/task/1644
// Maximum Subarray Sum II
int pb_max_subarry_sum2_main() {
	OPEN_IN;

	// n
	ll_type n, a, b;
	STREAM_IN >> n >> a >> b;
	ll_type sum = 0;
	std::vector<ll_type> v_sum;
	for (std::size_t i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		sum += k;
		v_sum.push_back(sum);
	}

	// k<i-a, k<i-b mais si a,b loins => *(a-b)

	// On cherche 2 vecteurs
	// v_min[i]=min(sum(xk), k<=i)
	// v_max[i]=max(sum(xk), k>=i)

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
