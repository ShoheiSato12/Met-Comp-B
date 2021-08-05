#include<iostream>
#include<cmath>
#include<algorithm>
#include<thread>
#include<future>
#include"../include/plotting.hpp"
#include"../include/automataNeuman.hpp"
#include"../include/automataMoore.hpp"


int main()
{
    int grid = 100+2;
    std::vector<std::vector<int>> system;
    int iterations=15;
    char* name = "Simulations";
    std::ofstream doc;
    for (int i = 3; i < 4;i++)
    {
        grid = pow(10, i) + 2;
        SimpleNeuman(i,name,grid,iterations, system);
        SimpleMoore(i,name,grid,iterations, system);
        ResistanceNeuman(i,name,grid,iterations, system);
        ResistanceMoore(i,name,grid,iterations, system);
    }
    return 0;
}

