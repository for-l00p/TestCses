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
#include <queue>

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

#define VALUE_MIN (INT64_MIN)
#define VALUE_MAX (INT64_MAX)
#define VALUE32_MIN (INT32_MIN)
#define VALUE32_MAX (INT32_MAX)
#define N_MAX 200000
#define MODULO (1000000007)

//https://cses.fi/problemset/task/1634
// Minimizing Coins
int pb_min_coins_main() {
	OPEN_IN;

	// n
	ll_type n, x;
	STREAM_IN >> n >> x;

	std::vector<int> c(n);
	for (int i = 0; i < n; i++)
		STREAM_IN >> c[i];
	// Les c[i] sont distincts
	std::sort(c.begin(), c.end());

	// ====
	// On cherche des ki tq sum(ki.ci) = x (ci donnes distintcs ci>0) (ki>=0)
	// tq S = sum(ki) soit minimale
	//
	// on doit avoir gcd(ci) | x,  sinon impossible
	// donc on peut tout diviser par gcd(ci)
	// on suppose gcd(ci) = 1
	// (3,5) => impossibles 4, 7 [ 8 9 10 ]
	// on doit avoir x >= min (ci)
	// (3,4) => impossible 5, [6,7,8]

	// (5,7) => imposs: 6, 8, 9, 11, 13, 17, 18,19, 22
	// (3,17), 3, 6, 9, 12, 15, (17), 18

	// Crible tableau m[0, n] init à infinity
	// on part de la plus petite piece
	// m[k.c1] = k
	// m[k.c2] = min(m[k.c2], k) etc...

	std::vector<int> mins(x + 1);
	mins[0] = 0;
	for (int i = 1; i < mins.size(); i++)
		mins[i] = VALUE32_MAX;

	std::vector<int> pos;
	pos.push_back(0);

	while (!pos.empty())
	{
		std::set<int> new_pos;
		for (int i = 0; i < pos.size(); i++)
		{
			auto min = mins[pos[i]];
			for (int j = 0; j < c.size() && pos[i] + c[j] <= x; j++)
			{
				auto prev_min = mins[pos[i] + c[j]];
				if (min + 1 < prev_min)
				{
					mins[pos[i] + c[j]] = min + 1;
					new_pos.insert(pos[i] + c[j]);
				}
			}
		}
		pos.clear();
		for (auto x : new_pos)
			pos.push_back(x);
	}
	if (mins[x] != VALUE32_MAX)
		std::cout << mins[x];
	else
		std::cout << -1;

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
