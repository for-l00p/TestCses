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
#define FILE_INPUT "c:\\tmp\\test_input_time_limit.txt"
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

//https://cses.fi/problemset/task/1620
// Factory Machines
int main() {
	OPEN_IN;

	// n machines, t products
	int n, t;
	STREAM_IN >> n >> t;

	std::vector<ll_type> times(n);
	std::map<ll_type, int> ordered_times;
	double total_performance = 0.0;
	for (int i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		times[i] = k;
		total_performance += 1.0 / (double)k;
		ordered_times[k]++;
	}

	// calculate max perf possible
	ll_type min_time = (ll_type)(t / total_performance);
	MY_DEBUG(std::cout << min_time << std::endl;)

	ll_type nb_product;
	ll_type min_complement = 1;
	ll_type min_add_time;
	min_time--;
	do
	{	
		min_time +=  min_complement;
		nb_product = 0;
		min_complement = VALUE_MAX;
		for (int i = 0; i < n; i++)
		{
			nb_product += min_time / times[i];
			auto remainder = min_time % times[i];
			auto complement = times[i] - remainder;
			min_complement = std::min(min_complement, complement);
		}
		MY_DEBUG(std::cout << " Test " << min_time << " " << nb_product << " " << min_complement << std::endl;);
		min_add_time = (ll_type)((t - nb_product) / total_performance);
		MY_DEBUG(std::cout << " Missing products " << t - nb_product << " min_add: " << min_add_time << std::endl;);
		min_complement = min_add_time;	
	} while (nb_product<t || min_add_time < 0);
	std::cout << min_time;
}
