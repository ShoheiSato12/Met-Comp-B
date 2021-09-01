#pragma once
#include<cmath>
#include<ctime>
#include<random>
#include<chrono>
double GaussRand(double T)
{
    unsigned rd = std::chrono::steady_clock::now().time_since_epoch().count();
    //std::random_device rd;
    std::default_random_engine generator (rd);
    std::normal_distribution<double> nd(0, sqrt(T));
    double aux = nd(generator);
    return aux;
}