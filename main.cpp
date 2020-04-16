#include <iostream>
#include <fstream>
#include <string>
#include <cassert>
#include <cstdlib>
#include <vector>
#include <array>

#include "string_operations.h"
#include "ipv4.h"

using namespace std;

void readIpPool(vector<ipV4>& ipPool)
{
    for (string line; std::getline(cin, line);)
    {
        if (line.size() == 0) break;            //считаем пустую строку условием выхода
        auto vecLine = split(line, '\t');
        auto vecIp = split(vecLine[0], '.');
        ipV4 ip{ 0, 0, 0, 0 };
        if (vectorStr2ipV4(vecIp, ip))
            ipPool.push_back(ip);
    }
}

template <typename T>
void printVector(const vector<T>& vec) 
{
    for (const auto& item : vec)
        cout << item << '\n';
}

int main()
{
    try
    {
        vector<ipV4> ipPool;
        readIpPool(ipPool);
        if (ipPool.size() == 0) return 0;     //Пустые исходные данные
        
        //Сортировка по убыванию
        stable_sortIpVector(ipPool, 3, true);
        stable_sortIpVector(ipPool, 2, true);
        stable_sortIpVector(ipPool, 1, true);
        stable_sortIpVector(ipPool, 0, true);
        printVector(ipPool);

        //Упражняемся с фильтрами
        auto filtered1 = filterIpVector(ipPool, [](ipV4 ip) {return ip[0] == 1; });
        printVector(filtered1);
        auto filtered2 = filterIpVector(ipPool, [](ipV4 ip) {return ip[0] == 46 && ip[1] == 70; });
        printVector(filtered2);
        auto filtered3 = filterIpVector(ipPool, [](ipV4 ip) {return ip[0] == 46 || ip[1] == 46 ||
                                                                     ip[2] == 46 || ip[3] == 46; });
        printVector(filtered3);
    }

    catch (const std::exception& e)
    {
        cerr << e.what() << endl;
    }

    return 0;
}
