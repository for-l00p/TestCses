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
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input (5).txt"
//#define FILE_INPUT "C:\\Users\\lione\\Downloads\\test_input_time_limit.txt"
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

//https://cses.fi/problemset/task/1641
// Sum of Three Values
int pb_three_values_main() {
	OPEN_IN;

	// n + target value
	ll_type n, x;
	STREAM_IN >> n >> x;

	std::map<ll_type, std::vector<int>> sub_targets;
	std::vector<ll_type> v(n);
	for (int i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;
		v[i] = k;
		sub_targets[x - k].push_back(i);
	}

	for (int i = 0; i < n; i++)
	{
		for (int j = i + 1; j < n; j++)
		{
			auto it = sub_targets.find(v[i] + v[j]);
			if (it != sub_targets.end())
			{
				// Check if solution found (distinct indexes)
				for (auto index : it->second)
				{
					if (index != i && index != j)
					{
						std::cout << i + 1 << " " << j + 1 << " " << index + 1;
						return 0;
					}
				}
			}
		}
	}
	std::cout << "IMPOSSIBLE";
}
