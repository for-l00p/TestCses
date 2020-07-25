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

static bool erase_element(std::multiset<ll_type>& m, ll_type value)
{
	auto it = m.find(value);
	if (it != m.end())
	{
		m.erase(it);
		return true;
	}
	else
		return false;
}

//https://cses.fi/problemset/task/1077
// Sliding Cost

// Probablement une meilleure façon de gérer les 2 arbres de gauche/droite

int pb_sliding_cost_main() {
	OPEN_IN;

	// n
	ll_type n, k;
	STREAM_IN >> n >> k;
	std::vector<ll_type> v0(n);
	for (int i = 0; i < n; i++)
	{
		ll_type x;
		STREAM_IN >> x;
		v0[i] = x;
	}

	// Init start
	std::vector<ll_type> v_sorted(v0.begin(), v0.begin() + k);
	std::sort(v_sorted.begin(), v_sorted.begin() + k);
	std::multiset<ll_type> left;
	std::multiset<ll_type> right;

	left.insert(v_sorted.begin(), v_sorted.begin() + v_sorted.size() / 2);
	right.insert(v_sorted.begin() + v_sorted.size() / 2, v_sorted.begin() + v_sorted.size());

	ll_type sum_left = 0;
	for (auto v : left)
		sum_left += v;

	ll_type sum_right = 0;
	for (auto v : right)
		sum_right += v;

	// on doit avoir left.size <= right.size <= left.size + 1
	for (int i = k; i < n; i++)
	{
		ll_type median;
		if (right.size() > left.size())
			median = *(right.begin());
		else
			median = *(--left.end());
		std::cout << left.size() * median - sum_left + sum_right - right.size() * median << " ";

		// on enleve v[i-k], on ajoute v[i]
		if (erase_element(left, v0[i - k]))
			sum_left -= v0[i - k];
		else if (erase_element(right, v0[i - k]))
			sum_right -= v0[i - k];
		else
			throw std::runtime_error("Missing element");

		if (v0[i] <= median)
		{
			left.insert(v0[i]);
			sum_left += v0[i];
		}
		else
		{
			right.insert(v0[i]);
			sum_right += v0[i];
		}

		// Rebalance left & right 
		while (right.size() < left.size())
		{
			auto it = --left.end();
			auto v = *it;
			left.erase(it);
			right.insert(v);
			sum_left -= v;
			sum_right += v;
		}

		// Here right.size>= left.size
		while (right.size() > left.size() + 1)
		{
			auto it = right.begin();
			auto v = *it;
			right.erase(it);
			left.insert(v);
			sum_left += v;
			sum_right -= v;
		}
	}
	ll_type median;
	if (right.size() > left.size())
		median = *(right.begin());
	else
		median = *(--left.end());
	std::cout << left.size() * median - sum_left + sum_right - right.size() * median << " ";


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
