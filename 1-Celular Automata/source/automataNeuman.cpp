#include<cmath>
#include<time.h>
#include <cstdio>
#include <algorithm>
#include <future>
#include <thread>
//#include"../include/plotting.hpp"
#include"../include/automataNeuman.hpp"

std::vector<std::vector<int>> initialsystem(int dimension)
{
    srand(time(NULL));
    std::vector<std::vector<int>> system(dimension, std::vector<int>(dimension,0));
    int count=0;
    while (count!=(int)pow(dimension,2)/2)
    {
        int i = rand() % dimension;
        int j = rand() % dimension;
        switch (system[i][j])
        {
        case 0:
            system[i][j] = 1;
            count++;
            break;
        
        case 1:
            break;
        }
    }
    return system;
}

std::vector<std::vector<int>> SimpleEvolveNeuman(std::vector<std::vector<int>> system)
{
    std::vector<std::vector<int>> auxsystem=system;
    int iter = (int)system.size()-2;
    std::vector<std::future<void>> futures;
    for (int i = 1; i < iter; i++)
    {
        for (int j = 1; j < iter; j++)
        {
            //std::thread num1 (counting,system,auxsystem,i  ,j);
            //std::thread num2 (counting,2*i+1,2*j+1,auxsystem,system);
            //std::thread num3 (counting,3*i+2,3*j+2,auxsystem,system);
            //std::cout << "   " << auxsystem[i][j] << std::endl;
            //num1.join();
            //num2.join();
            //num3.join();
            //std::future<void> f = std::async(std::launch::async,counting,system,auxsystem,i,j);
            //f.get();
            int aux=countNeumanNeighbour(system,i,j);
            switch (system[i][j])
            {
                case 1:
                    if(aux==2)
                    {
                        //auxsystem[i][j] = 1;
                    }
                    else
                    {
                        auxsystem[i][j] = 0;
                    }
                    break;
                
                case 0:
                    if(aux==3)
                    {
                        auxsystem[i][j] = 1;
                    }
                    break;
            }
        }
    }

    return auxsystem;
}
int countNeumanNeighbour(std::vector<std::vector<int>> system,int i, int j)
{
    int neighbour = 0;
    std::vector<int> values;
    //Vertical
    values.push_back(system[i+1][j]);
    values.push_back(system[i-1][j]);
    //Horizontal
    values.push_back(system[i][j+1]);
    values.push_back(system[i][j-1]);
    neighbour = std::count(values.begin(), values.end(), 1);
    //std::cout << values[0] << "   " << values[1] << "   " << values[2] << "   " << values[3] << "   total= "<<neighbour;
    return neighbour;
}

void counting(std::vector<std::vector<int>>& sys,std::vector<std::vector<int>>& auxsys,int i, int j)
{
    int aux=countNeumanNeighbour(sys,i,j);
    switch (sys[i][j])
    {
        case 1:
            if(aux==2)
            {
                //auxsystem[i][j] = 1;
            }
            else
            {
                auxsys[i][j] = 0;
            }
            break;
        
        case 0:
            if(aux==3)
            {
                auxsys[i][j] = 1;
            }
            break;
    }
}
void example()
{

}