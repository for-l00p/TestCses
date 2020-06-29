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

std::vector<std::string> get_permutations(int n)
{
    if (n < 3)
        throw std::runtime_error("Invalid input");
    std::vector<std::string> ret;
    if (n == 3)
    {
        ret.push_back("123");
        ret.push_back("132");
        ret.push_back("213");
        ret.push_back("231");
        ret.push_back("312");
        ret.push_back("321");
    }
    else
    {
        auto r = get_permutations(n - 1);
        char c = '0' + n;
        std::ostringstream os;
        for (const auto& x : r)
        {
            for (int i = 0; i < n; i++)
            {
                os.str("");
                os << x.substr(0, i) << c << x.substr(i);
                ret.push_back(os.str());
            }
        }
    }
    return ret;
}

bool is_perm_ok(const std::string& s, const std::vector<std::pair<int, int>>& reserved)
{
    for (int i = 0; i < s.length(); i++)
    {
        int x1 = i;
        int y1 = s[i] - '1';
        for (const auto& r : reserved)
        {
            if (r.first == x1 && r.second == y1)
                return false;
        }
        for (int j = i + 1; j < s.length(); j++)
        {
            int x2 = j;
            int y2 = s[j] - '1';
            if ((x1 == x2) || (y1 == y2) || (std::abs(x1 - x2) == std::abs(y1 - y2)))
                return false;
        }
    }
    return true;
}

int pb15_main() {
    OPEN_IN;

    std::vector<std::pair<int, int>> reserved;
    for (int i = 0; i < 8; i++)
    {
        std::string s;
        STREAM_IN >> s;
        // std::cout << s << std::endl;
        for (int j = 0; j < s.length(); j++)
            if (s[j] == '*')
                reserved.push_back(std::pair<int, int>(i, j));
    }

    auto p = get_permutations(8);
    std::set<std::string> h;
    h.insert(p.begin(), p.end());
    //std::cout << p.size() << " " << h.size() << std::endl;

    int count = 0;
    for (const auto& x : p)
    {
        if (is_perm_ok(x, reserved))
            count++;
    }
    std::cout << count;

    // Permutation 8 + supress si (x1,y1) ~ (x2, y2)
    // ~ => x1=x2 ou y1=y2 ou abs(x1-x2)=abs(y1-y2)
    // ou (x,y) sur un slot reserve



    return 0;
}
