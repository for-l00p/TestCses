#define  _CRT_SECURE_NO_WARNINGS 1

#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <map>
#include <sstream>
#include <chrono>



static int i, j;

static char grid[9*16];
static char filter[64];

static char moves[64];
static int pos = 0;
static int counter = 0;

#define GRID(i,j) (grid[(j)+((i)<<4)])

void display_grid()
{
	for (int i = 0; i < 9; i++)
	{
		for (int j = 0; j < 9; j++)
		{
			if (GRID(i,j)==1)
			{
				if (i==0 || i==8 || j==0 || j==8)
					std::cout << "#";
				else
					std::cout << "*";
			}
			else
				std::cout << " ";
		}
		std::cout << std::endl;		
	}
	std::cout << moves << "(" << std::strlen(moves) << ")" << " " << pos << std::endl;
}

void init_grid()
{
	for (int k = 0; k < 9; k++)
	{
		GRID(0,k) = 1;
		GRID(8,k) = 1;
		GRID(k,0) = 1;
		GRID(k,8) = 1;
	}
}

void try_move_left();
void try_move_up();
void try_move_right();
void try_move_down();
void forced_move();

void try_move_left()
{
	if (GRID(i,--j) == 1)
	{
		j++;
		return;
	}
	GRID(i,j) = 1;
	moves[pos++] = 'L';
	//display_grid();
	if (pos == 49)
	{
		if (i == 7 && j == 1)
		{
			std::cout << "Reached end " << i << " " << j << std::endl;
			std::cout << moves << " " << ++counter << std::endl;
		}
	}
	else
	{
		if (filter[pos] == '?')
		{
			try_move_left();
			try_move_up();
			//try_move_right();
			try_move_down();
		}
		else
			forced_move();
	}
	GRID(i,j++) = 0;
	--pos;
}


void try_move_right()
{
	if (GRID(i,++j) == 1)
	{
		j--;
		return;
	}
	GRID(i,j) = 1;
	moves[pos++] = 'R';
	//display_grid();
	if (pos == 49)
	{
		if (i == 7 && j == 1)
		{
			std::cout << "Reached end " << i << " " << j << std::endl;
			std::cout << moves << " " << ++counter << std::endl;
		}
	}
	else
	{
		if (filter[pos] == '?')
		{
			//try_move_left();
			try_move_up();
			try_move_right();
			try_move_down();
		}
		else
			forced_move();
	}
	GRID(i,j--) = 0;
	--pos;
}

void try_move_up()
{
	if (GRID(--i,j) == 1)
	{
		i++;
		return;
	}
	GRID(i,j) = 1;
	moves[pos++] = 'U';
	//display_grid();
	if (pos == 49)
	{
		if (i == 7 && j == 1)
		{
			std::cout << "Reached end " << i << " " << j << std::endl;
			std::cout << moves << " " << ++counter << std::endl;

		}
	}
	else
	{
		if (filter[pos] == '?')
		{
			try_move_left();
			try_move_up();
			try_move_right();
			//try_move_down();
		}
		else
			forced_move();
	}
	GRID(i++,j) = 0;
	--pos;
}

void try_move_down()
{
	if (GRID(++i,j) == 1)
	{
		i--;
		return;
	}
	GRID(i,j) = 1;	
	moves[pos++] = 'D';
	//display_grid();
	if (pos == 49)
	{
		if (i == 7 && j == 1)
		{
			std::cout << "Reached end " << i << " " << j << std::endl;
			std::cout << moves << " " << ++counter << std::endl;
		}
	}
	else
	{
		if (filter[pos] == '?')
		{
			try_move_left();
			//try_move_up();
			try_move_right();
			try_move_down();
		}
		else
			forced_move();
	}
	GRID(i--,j) = 0;
	--pos;
}

void forced_move()
{
	switch (filter[pos])
	{
	case 'L':
		try_move_left();
		break;
	case 'U':
		try_move_up();
		break;
	case 'R':
		try_move_right();
		break;
	case 'D':
		try_move_down();
		break;
	default:
		throw std::runtime_error("Invalid");
		break;
	}
}

int test_main() {
	
	std::string s = "??????R??????U??????????????????????????LD????D?";
	            s = "??????L??????U??????????????????????????RD????D?";
				s = "????????????????????????????????????????????????";
	std::cout << s.size() << std::endl;
	std::reverse(s.begin(), s.end());
	s = "#" + s;
	std::cout << s << " " << s.size() << std::endl;

	std::strcpy(filter, s.c_str());
	memset(moves, 0, sizeof(moves));

	init_grid();
	display_grid();
	
	i = 1;
	j = 0;
	counter = 0;


	std::chrono::steady_clock::time_point begin = std::chrono::steady_clock::now();
	try_move_right();
	std::chrono::steady_clock::time_point end = std::chrono::steady_clock::now();
	//std::cout << "Time difference = " << std::chrono::duration_cast<std::chrono::microseconds>(end - begin).count() << "[µs]" << std::endl;
	std::cout << std::endl << "Time difference = " << std::chrono::duration_cast<std::chrono::seconds> (end - begin).count() << " s" << std::endl;


	




	return 0;
}
