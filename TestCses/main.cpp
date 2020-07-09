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


void max_diff(const std::vector<ll_type> & v0)
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
int test_basic()
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

int main() {

	//return test_basic();

	OPEN_IN;

	std::size_t n;
	STREAM_IN >> n;
	
	// sommer les valeurs consecutives de meme signe
	// Sauter les 0
	
	ll_type max = VALUE_MIN;
	ll_type current_sum = 0;
	std::vector<ll_type> v;
	for (std::size_t i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		max = std::max(max, k);
		if ((k >= 0 && current_sum >= 0) || (k <= 0 && current_sum <= 0))
			current_sum += k;
		else
		{
			// Sign change, first element must be positive
			if (v.size() > 0 || current_sum > 0)
				v.push_back(current_sum);
			current_sum = k;
		}
	}
	// Last element must be positive
	if (current_sum > 0)
		v.push_back(current_sum);

	// Specifix cases: all <=0, return max of all individual elements (non empty)
	if (v.size() == 0)
	{
		std::cout << max;
		return 0;
	}

	if (v.size() <= 2)
	{
		std::cout << v[0];
		return 0;
	}

	assert(v.size() % 2 == 1);

	// Generic case: ++ -- ++ -- ... -- ++ (v.size odd)
	//                a  b  c  d  
	// Si a+b+c >= a et a+b+c >= c => (a,b,c)=> a+b+c
	// Iterer jusque plus de replace
	// Worst case ?
	
	// Une seule iteration ?
	int replaced=0;
	do
	{
		replaced = 0;
		std::vector<ll_type> new_v;
		auto current = v[0];		
		for (std::size_t i = 0; i + 2 < v.size(); i += 2)
		{
			auto s = current + v[i + 1] + v[i + 2];
			if (s >= current && s >= v[i + 2])
			{
				replaced++;
				current = s;
			}
			else
			{
				new_v.push_back(current);
				new_v.push_back(v[i + 1]);
				current = v[i + 2];
			}
		}
		new_v.push_back(current);
		std::cout << "replaced: " << replaced << std::endl;
		v = new_v;
	} while (replaced!=0);

	max_diff(v);

	// Chercher le max des indices pair
	max = VALUE_MIN;
	for (std::size_t i = 0; i < v.size(); i += 1)
		max = std::max(max, v[i]);
	std::cout << max;



	//std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();







	//std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	//std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;


	return 0;
}
