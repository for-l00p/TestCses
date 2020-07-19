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

// 371 045 814 100

typedef std::int64_t ll_type;

#define VALUE_MIN (INT64_MIN);
#define VALUE_MAX (INT64_MAX);
#define N_MAX 200000

static ll_type get_reward2(const std::vector<std::pair<ll_type, ll_type>>& tasks, const std::vector<int>& perm)
{
	int sum_deadline = 0;
	for (int i = 0; i < tasks.size(); i++)
		sum_deadline += tasks[i].second;


	ll_type current_sum = 0;
	ll_type total_sum = 0;
	for (int i = 0; i < perm.size(); i++)
	{
		int task_index = perm[i];
		current_sum += tasks[task_index].first;
		total_sum += current_sum;

	}
	return sum_deadline - total_sum;
}

static ll_type get_reward(const std::vector<std::pair<ll_type, ll_type>>& tasks, const std::vector<int>& perm)
{
	ll_type time = 0;
	ll_type reward = 0;
	for (int i = 0; i < perm.size(); i++)
	{
		int task_index = perm[i];
		std::cout << tasks[task_index].first << " ";
		time += tasks[task_index].first;
		reward += tasks[task_index].second - time;
	}
	return reward;
}


//https://cses.fi/problemset/task/1630
// Tasks and Deadlines
int pb_tasks_and_deadline_main() {
	OPEN_IN;

	// n tasks
	ll_type n;
	STREAM_IN >> n;

	ll_type total_dealine = 0;
	std::vector<ll_type> durations(n);
	for (int i = 0; i < n; i++)
	{
		//  (first) a = duration, (second) d = deadline of task
		ll_type a, d;
		STREAM_IN >> a >> d;
		//std::cout << a << " " << d << std::endl;
		durations[i] = a;
		total_dealine += d;
	}
	std::sort(durations.begin(), durations.end());
	ll_type current_sum = 0;
	ll_type current_total_sum = 0;
	for (auto v : durations)
	{
		current_sum += v;
		current_total_sum += current_sum;
	}
	std::cout << total_dealine - current_total_sum;
}
