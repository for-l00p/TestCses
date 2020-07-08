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

//https://cses.fi/problemset/task/1643
// Maximum Subarray Sum

int main() {
	OPEN_IN;

	ull_type n;
	STREAM_IN >> n;
	
	std::vector<int> x;	
	for (int i = 0; i < n; i++)
	{
		int v;
		STREAM_IN >> v;
		x.push_back(v);
	}

	return 0;
}
