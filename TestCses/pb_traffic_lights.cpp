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
//#define FILE_INPUT "c:\\tmp\\test_input (3).txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef std::int64_t ll_type;

#define VALUE_MIN (INT64_MIN);
#define VALUE_MAX (INT64_MAX);
#define N_MAX 200000

//https://cses.fi/problemset/task/1163
// Traffic Lights

int pb_traffic_lights_main() {

	OPEN_IN;

	ll_type x, n;
	STREAM_IN >> x >> n;

	std::map<ll_type, ll_type> chunks;
	std::map<ll_type, int> lengths;
	chunks.insert(std::make_pair((ll_type)0, x));
	lengths.insert(std::make_pair(x, 1));
	ll_type max = VALUE_MIN;
	for (ll_type i = 0; i < n; i++)
	{
		ll_type k;
		STREAM_IN >> k;

		auto it = chunks.upper_bound(k);
		it--;
		ll_type length = it->second - it->first;
		lengths[length]--;
		if (lengths[length] == 0)
			lengths.erase(length);
		chunks.insert(std::make_pair(k, it->second));
		lengths[it->second - k]++;
		it->second = k;
		lengths[it->second - it->first]++;
		auto it2 = lengths.end();
		it2--;
		std::cout << it2->first << " ";
	}
	return 0;
}
