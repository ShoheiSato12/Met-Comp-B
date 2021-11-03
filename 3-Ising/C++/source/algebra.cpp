#pragma once
#include"../include/algebra.hpp"
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
    for (int i=0;i<(int)vector.size();i++)
    {
        result+=vector[i];
    }
    return result;
}
double internalSum(std::vector<std::vector<double>>vector)
{
    double result =0;
    for(int i=0;i<(int)vector.size();i++)
    {
        for(int j=0;j<(int)vector[i].size();j++)
        {
            result+=vector[i][j];
        }
    }

    return result;
}
int internalSum(std::vector<int>vector)
{
    int result=0;
    for (int i=0;i<(int)vector.size();i++)
    {
        result+=vector[i];
    }
    return result;
}
int internalSum(std::vector<std::vector<int>>vector)
{
    int result =0;
    for(int i=0;i<(int)vector.size();i++)
    {
        for(int j=0;j<(int)vector[i].size();j++)
        {
            result+=vector[i][j];
        }
    }

    return result;
}
std::vector<std::vector<double>>MatrixInitialization(int a, int b)
{
    std::vector<std::vector<double>> matrix (a,std::vector<double>(b,0));
    return matrix;
}
std::vector<std::vector<double>> identity(int a)
{
    std::vector<std::vector<double>> matrix(a,std::vector<double>(a, 0));
    for (uint i = 0; i < matrix.size();i++)
    {
        matrix[i][i] = 1;
    }
    return matrix;
}
void printmatrix(std::vector<double> a)
{
    std::cout << std::endl << "vector" << std::endl;
    for (uint i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl;
}
void printmatrix(std::vector<std::vector<double>> a)
{
    std::cout << std::endl<< "matrix" << std::endl;
    for (uint i = 0; i < a.size(); i++)
    {
        for (uint j = 0; j < a[i].size();j++)
        {
            std::cout << a[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}
void printmatrix(std::vector<int> a)
{
    std::cout << std::endl << "vector" << std::endl;
    for (uint i = 0; i < a.size(); i++)
    {
        std::cout << a[i] << std::endl;
    }
    std::cout << std::endl;
}
void printmatrix(std::vector<std::vector<int>> a)
{
    std::cout << std::endl<< "matrix" << std::endl;
    for (uint i = 0; i < a.size(); i++)
    {
        for (uint j = 0; j < a[i].size();j++)
        {
            std::cout << a[i][j] << "   ";
        }
        std::cout << std::endl;
    }
    std::cout << std::endl;
}