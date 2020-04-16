#pragma once

using namespace std;
using ipV4 = array<int, 4>;


bool vectorStr2ipV4(const vector<string>& vec, ipV4& ip);
ostream& operator<<(ostream& out, const ipV4& ip);
void stable_sortIpVector(vector<ipV4>& ipVector, int num, bool desc);
vector<ipV4> filterIpVector(vector<ipV4>& ipVector, bool(*filter)(ipV4 ip));

