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

static std::set<std::string> get_distinct_perm(const std::string& s)
{
    std::ostringstream os;
    std::set<std::string> ret;
    if (s.length() == 1)
    {
        ret.insert(s);
        return ret;
    }
    else if (s.length() == 2)
    {
        os.str("");
        os << s[0] << s[1];
        ret.insert(os.str());
        os.str("");
        os << s[1] << s[0];
        ret.insert(os.str());
        return ret;
    }
    else
    {
        auto s2 = s.substr(1);
        auto r = get_distinct_perm(s2);
        for (const auto& x : r)
        {
            for (size_t j = 0; j <= x.length(); j++)
            {
                auto s3 = x.substr(0, j) + s[0] + x.substr(j);
                ret.insert(s3);
            }
        }
    }
    return ret;
}

//https://cses.fi/problemset/task/1622
// Create string I
int pb13_main() {
    OPEN_IN;
    std::string s;
    STREAM_IN >> s;

    auto ret = get_distinct_perm(s);
    std::cout << ret.size() << std::endl;
    for (const auto& x : ret)
        std::cout << x << std::endl;
    return 0;
}
