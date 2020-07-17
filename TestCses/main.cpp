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

//https://cses.fi/problemset/task/1164
// Room Allocation

int main() {
	OPEN_IN;



	ll_type n;
	STREAM_IN >> n;

	// The events, (arrival + departure)
	std::map<ll_type, ll_type> events;
	for (ll_type i = 0; i < n; i++)
	{
		ll_type a, b;
		STREAM_IN >> a >> b;
		events[2 * a]++; // Arrival on even
		events[2 * b + 1]--; // Departure on odd
	}

	// Etat des chambres ?
	ll_type max = VALUE_MIN;
	ll_type sum = 0;
	for (auto event : events)
	{
		sum += event.second;
		max = std::max(max, sum);
	}
	std::cout << max;

}
