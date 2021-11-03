#pragma once
#include"../include/functions.hpp"
std::vector<std::vector<int>> randspin(int size[2])
{
    std::vector<std::vector<int>> a(size[0], std::vector<int>(size[1], 0));
    //srand(time(NULL));
    for (uint i = 0; i < a.size();i++)
    {
        for (uint j = 0; j < a[i].size();j++)
        {
            int b = rand()%2;
            switch (b)
            {
            case 0:
                a[i][j] = -1;
                break;
            
            case 1:
                a[i][j] = 1;
                break;
            }
        }
    }
    return a;
}