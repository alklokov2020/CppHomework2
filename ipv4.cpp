#include <array>
#include <vector>
#include <algorithm>
#include <iostream>

#include "ipv4.h"
#include "string_operations.h"



bool vectorStr2ipV4(const vector<string>& vec, ipV4& ip) 
{
    if (vec.size() != 4)
        return false;
    for (int i = 0; i < 4; i++)
    {
        if (!str2byte(vec[i], ip[i]))
            return false;
    }
    return true;
}

ostream& operator<<(ostream& out, const ipV4& ip)
{
    out << ip[0] << '.' << ip[1] << '.' << ip[2] << '.' << ip[3];
    return out;
}

void stable_sortIpVector(vector<ipV4>& ipVector, int num, bool desc = false)
{
    if (num >= 0 && num <= 3)
        stable_sort(ipVector.begin(), ipVector.end(), [n = num, dsc = desc](ipV4 ip1, ipV4 ip2)
            { return (dsc ? ip1[n] > ip2[n] : ip1[n] < ip2[n]); });
}

vector<ipV4> filterIpVector(vector<ipV4>& ipVector, bool(*filter)(ipV4 ip))
{
    int resLength = count_if(ipVector.begin(), ipVector.end(), filter);
    vector<ipV4> res(resLength);
    copy_if(ipVector.begin(), ipVector.end(), res.begin(), filter);
    return res;
}
