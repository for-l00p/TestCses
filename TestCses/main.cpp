#include <iostream>
#include <algorithm>
#include <string>
#include <fstream>
#include <vector>
#include <set>
#include <sstream>

#ifdef MY_INPUT
#define FILE_INPUT "input.txt"
#define STREAM_IN my_file
#define OPEN_IN std::fstream my_file(FILE_INPUT); if (!my_file.good()) { std::cout << "Error opening " << FILE_INPUT; return -1; }
#else
#define STREAM_IN std::cin
#define OPEN_IN
#endif

typedef long long int ull_type;

std::vector<std::string> solutions;

int pos;
char* current_path;
char* grid;

#define GRID(X,Y) (grid[(X)+8*(Y)])

void move(int x, int y)
{
	if (x == 0 && y == 6) // Target
	{
		if (pos == 48)
		{
			auto s = std::string(current_path, pos);
			solutions.push_back(s);
			std::cout << s << " " << solutions.size() << std::endl;
		}
		pos--;
		return;
	}

	GRID(x, y) = 1;
	// Left
	if (x > 0 && GRID(x-1, y) == 0)
	{
		current_path[pos++] = 'L';
		move(x-1, y);
	}

	// Up
	if (y > 0 && GRID(x, y-1) == 0)
	{
		current_path[pos++] = 'U';
		move(x, y-1);
	}

	// Right
	if (x < 6 && GRID(x+1, y) == 0)
	{
		current_path[pos++]= 'R';
		move(x+1, y);
	}

	// Down
	if (y < 6 && GRID(x, y+1) == 0)
	{
		current_path[pos++] = 'D';
		move(x, y+1);
	}

	GRID(x, y) = 0;
	pos--;
}

int main() {
	OPEN_IN;

	std::string s;
	STREAM_IN >> s;

	//std::cout << s;

	grid = new char[8 * 7];
	memset(grid, 0, 8 * 7);

	pos = 0;
	current_path = new char[48];
	
	move(0, 0);

	int count = 0;
	for (const auto& sol : solutions)
	{
		bool match = true;
		for (int i = 0; i < s.length(); i++)
			if ((s[i] != '?') && s[i] != sol[i])
				match = false;
		if (match)
			count++;
	}
	std::cout << count;

	// Generer tous les chemins upperleft to lowerleft on 7x7 grid
	// + match pattern





	return 0;
}
