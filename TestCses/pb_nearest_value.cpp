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
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (5).txt"
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

//https://cses.fi/problemset/task/1645
// Nearest Smaller Values

// Test naive
static std::string naive(const std::vector<ll_type>& v)
{
	std::ostringstream os;
	for (auto i = 0; i < v.size(); i++)
	{
		bool found = false;
		for (auto j = i - 1; !found && j >= 0; j--)
		{
			if (v[j] < v[i])
			{
				os << j + 1 << " ";
				found = true;
			}
		}
		if (!found)
			os << "0 ";
	}
	return os.str();
}

static void generate_test_case(int size)
{
	std::default_random_engine generator;
	std::uniform_int_distribution<int> distribution(1, 1000000000);
	auto my_generator = std::bind(distribution, generator);


	std::ofstream myfile;
	myfile.open(MY_TEST);
	myfile << size << std::endl;
	for (int i = 0; i < size; i++)
	{
		//myfile << my_generator() << " ";
		myfile << size - i << " ";
	}
	myfile.close();
}

static std::string with_record(const std::vector<ll_type>& v)
{
	std::ostringstream os;
	std::vector<int> v_min(v.size());
	v_min[0] = -1;
	os << "0 ";
	for (auto i = 1; i < v.size(); i++)
	{
		bool found = false;
		auto pos = i - 1;
		while (!found && pos >= 0)
		{
			if (v[pos] < v[i])
			{
				os << pos + 1 << " ";
				found = true;
				v_min[i] = pos;
			}
			else
				pos = v_min[pos];
		}
		if (!found)
			os << "0 ";
	}
	return os.str();
}



int pb_nearest_value_main() {

	//	generate_test_case(200000);

	OPEN_IN;

	// n
	ll_type n;
	STREAM_IN >> n;

	std::vector<ll_type> v(n);
	for (int i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		v[i] = k;
	}

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
#endif

	auto ret = with_record(v);
	std::cout << ret;

#ifdef MY_INPUT
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;

	std::ofstream myfile;
	myfile.open(MY_OUT);
	myfile << ret;
	myfile.close();
#endif

}
