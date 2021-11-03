#include<iostream>
#include<cmath>
#include<ctime>
#include<random>
#include<chrono>
#include<vector>
double GaussRand();
double internalSum(std::vector<double>vector);
double internalSum(std::vector<std::vector<double>>vector);
int internalSum(std::vector<int>vector);
int internalSum(std::vector<std::vector<int>>vector);
std::vector<std::vector<double>>MatrixInitialization(int a, int b);
std::vector<std::vector<double>> identity(int a);
void printmatrix(std::vector<double> a);
void printmatrix(std::vector<std::vector<double>> a);
void printmatrix(std::vector<int> a);
void printmatrix(std::vector<std::vector<int>> a);
