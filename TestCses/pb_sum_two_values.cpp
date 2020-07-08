#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <chrono>

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef long long int ull_type;

//https://cses.fi/problemset/task/1640
//Sum of Two Values

int pb_sum_two_values() {
	OPEN_IN;

	ull_type n, x;
	STREAM_IN >> n >> x;

	std::vector<int> a;
	std::set<int> searcher;
	for (int i = 0; i < n; i++)
	{
		int v;
		STREAM_IN >> v;
		a.push_back(v);
		searcher.insert(v);
	}


	for (int i = 0; i < a.size(); i++)
	{
		int target = x - a[i];
		if (searcher.find(target) != searcher.end())
		{
			// Search position in a
			for (int j = 0; j < a.size(); j++)
				if (a[j] == target && i != j)
				{
					std::cout << i + 1 << " " << j + 1;
					return 0;
				}
		}
	}
	std::cout << "IMPOSSIBLE";

	return 0;
}
