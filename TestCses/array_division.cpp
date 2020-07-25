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
#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (15).txt"
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

//https://cses.fi/problemset/task/1085
// Array Division
int pb_array_division_main() {
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
		std::cout << x << std::endl;
	}
	auto k0 = k;
	double target = (double)sum / (double)k;

	// sum
	// sum/k
	// sum1 + sum2 + ... sumk = sum
	// k * max(sum_i) >= sum
	// max(sum_i) >= sum/k
	// Ideal: tous les morceaux = sum/k (entier)

	// voisinage de sum/k inf ou sup ?
	// Tester les 2 cas inf, sup

	// 1344893167

	// Recalculer la target apres chaque coupe ?

	// Attention au nombre de coupes
	int nb_coupes = 0;
	ll_type sub_sum = 0;
	ll_type max_sub_sum = VALUE_MIN;
	ll_type current_sub_sum = 0;
	for (int i = 0; i < n; i++)
	{
		sub_sum += v[i];
		current_sub_sum += v[i];
		if (sub_sum >= target)
		{
			if (i > 0)
			{
				// sub_sum(i-1) .... target .... sub_sum(i)
				double d1 = target - (sub_sum - v[i]);
				double d2 = sub_sum - target;
				if (d1 <= d2)
				{
					std::cout << "Coupe at (i-1) " << i - 1 << " somme: " << sub_sum - v[i] << std::endl;
					// Coupe a i-1
					max_sub_sum = std::max(max_sub_sum, sub_sum - v[i]);
					sub_sum = v[i];
					k--;
					if (k > 0)
					{
						target = (double)(sum - (current_sub_sum - v[i])) / (double)(k);
					}

				}
				else
				{
					std::cout << "Coupe at  i " << i << " somme: " << sub_sum << std::endl;
					// Coupe a i
					max_sub_sum = std::max(max_sub_sum, sub_sum);
					sub_sum = 0;
					k--;
					if (k > 0)
					{
						target = (double)(sum - current_sub_sum) / (double)(k);
					}
				}
				nb_coupes++;
			}
		}
	}
	if (sub_sum > 0)
		nb_coupes++;
	MY_DEBUG(std::cout << nb_coupes << " expected:" << k0 << " " << k << std::endl;);
	max_sub_sum = std::max(max_sub_sum, sub_sum);
	std::cout << max_sub_sum;

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
