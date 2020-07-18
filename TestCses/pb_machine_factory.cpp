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
#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (5).txt"
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input_time_limit.txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#define MY_DEBUG(x) x
#else
#define STREAM_IN std::cin
#define OPEN_IN
#define MY_DEBUG(x)
#endif

// 371 045 814 100

typedef std::int64_t ll_type;

#define VALUE_MIN (INT64_MIN);
#define VALUE_MAX (INT64_MAX);
#define N_MAX 200000

static std::pair<ll_type, ll_type> calculate_nb_product(ll_type time, std::vector<ll_type> times)
{
	ll_type nb_product = 0;
	ll_type min_add = VALUE_MAX;
	for (int i = 0; i < times.size(); i++)
	{
		nb_product += time / times[i];
		auto remainder = time % times[i];
		min_add = std::min(min_add, times[i] - remainder);
	}
	return std::make_pair(nb_product, min_add);
}


//https://cses.fi/problemset/task/1620
// Factory Machines
int pb_machine_factory_main() {
	OPEN_IN;

	// n machines, t products
	int n, t;
	STREAM_IN >> n >> t;

	std::vector<ll_type> times(n);
	double total_performance = 0.0;
	for (int i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		times[i] = k;
		total_performance += 1.0 / (double)k;
	}

	ll_type remaining_products = t;
	ll_type add_time = 0;
	ll_type current_time = 0;
	ll_type max_time_with_remaining_products = VALUE_MIN;
	// Surement plus elegant a trouver ....
	for (int i = 0; i < 10; i++)
	{
		add_time = (ll_type)(remaining_products / total_performance);
		current_time += add_time;
		auto nb_products = calculate_nb_product(current_time, times);
		remaining_products = t - nb_products.first;
		if (remaining_products >= 0)
			max_time_with_remaining_products = std::max(max_time_with_remaining_products, current_time);
		MY_DEBUG(std::cout << "time: " << current_time << " add:" << add_time << " rp:" << remaining_products << std::endl;);
	}

	current_time = max_time_with_remaining_products;
	do
	{
		auto nb_products = calculate_nb_product(current_time, times);
		remaining_products = t - nb_products.first;
		if (remaining_products > 0)
			current_time += nb_products.second;
	} while (remaining_products > 0);

	std::cout << current_time;
}
