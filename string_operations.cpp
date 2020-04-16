#include <string>
#include <vector>
#include "string_operations.h"



vector<string> split(const string& str, char d)
{
    vector<string> r;

    string::size_type start = 0;
    auto stop = str.find_first_of(d);
    while (stop != string::npos)
    {
        r.push_back(str.substr(start, stop - start));
        start = stop + 1;
        stop = str.find_first_of(d, start);
    }

    r.push_back(str.substr(start));
    return r;
}

bool str2byte(const string& str, int& byte) 
{
    if (str.size() == 0 || str.size() > 3)
        return false;

    int res = 0;
    for (auto d : str)
    {
        if (d >= '0' && d <= '9')
        {
            res = res * 10 + d - '0';
            if (res > 255) return false;
        }
        else
            return false;
    }
    byte = res;
    return true;
}
