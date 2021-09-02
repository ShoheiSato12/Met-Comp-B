#pragma once
#include"../include/functions.hpp"
double GaussRand()
{
    unsigned rd = std::chrono::steady_clock::now().time_since_epoch().count();
    //std::random_device rd;
    std::default_random_engine generator (rd);
    std::normal_distribution<double> nd(0, 1);
    double aux = nd(generator);
    return aux;
}
double internalSum(std::vector<double>vector)
{
    double result=0;
    for (uint i=0;i<vector.size();i++)
    {
        result+=vector[i];
    }
    return result;
}
double internalSum(std::vector<std::vector<double>>vector)
{
    double result =0;
    for(uint i=0;i<vector.size();i++)
    {
        for(uint j=0;j<vector[i].size();j++)
        {
            result+=vector[i][j];
        }
    }

    return result;
}
void plot()
{
    
}