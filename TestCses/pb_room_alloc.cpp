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

struct event
{
	std::vector<int> client_ids;
};

int pb_room_alloc_main() {
	OPEN_IN;

	int n;
	STREAM_IN >> n;

	// The events, (arrival on even day + departure on odd day)
	std::map<ll_type, event> events;
	for (int i = 0; i < n; i++)
	{
		ll_type a, b;
		STREAM_IN >> a >> b;
		events[2 * a].client_ids.push_back(i);
		events[2 * b + 1].client_ids.push_back(i);
	}

	std::stack<int> free_rooms;
	int max_room = 0;
	//std::map<int, int> occupancy;
	std::vector<int> client_room(n); // client_id are 0,n-1
	for (auto event : events)
	{
		for (auto client_id : event.second.client_ids)
		{
			if (event.first % 2 == 0)
			{
				// an arrival
				if (free_rooms.empty())
					free_rooms.push(++max_room);
				int room_id = free_rooms.top();
				free_rooms.pop();
				client_room[client_id] = room_id;
			}
			else
			{
				// a departure
				int room_id = client_room[client_id];
				free_rooms.push(room_id);
			}
		}
	}
	std::cout << max_room << std::endl;
	for (int i = 0; i < client_room.size(); i++)
		std::cout << client_room[i] << " ";
}
