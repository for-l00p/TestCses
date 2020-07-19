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
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (12).txt"
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

static ll_type naive(const std::vector<ll_type>& sums, ll_type n)
{
	int count = 0;
	for (int i = 0; i < sums.size(); i++)
		for (int j = i+1; j < sums.size(); j++)
	{
			if (sums[i] == sums[j])
				count++;
	}
	return count;
}

ll_type positive_remainder(ll_type v, ll_type n)
{
	auto r = v % n;
	if (r < 0)
		r += n;
	return r;
}

//https://cses.fi/problemset/task/1085
// Array Division
int main() {
	OPEN_IN;

	// n
	ll_type n, k;
	STREAM_IN >> n >> k;

	std::vector<ll_type> v(n);
	ll_type sum = 0;
	for (int i = 0; i < n; i++)
	{
		ll_type x;
		STREAM_IN >> x;
		v[i] = x;
		sum += x;
	}
	double target = (double)sum / (double)k;



	// sum
	// sum/k
	// sum1 + sum2 + ... sumk = sum
	// k * max(sum_i) >= sum
	// max(sum_i) >= sum/k
	// Ideal: tous les morceaux = sum/k (entier)

	// voisinage de sum/k inf ou sup ?





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
