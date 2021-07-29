#include<iostream>
#include<cmath>
#include<algorithm>
#include<thread>
#include"../include/plotting.hpp"
#include"../include/automataNeuman.hpp"
void evolve(int i, int grid, int iterations, std::vector<std::vector<int>> system);
int main()
{
    int grid = 100+2;
    std::vector<std::vector<int>> system[3];
    int iterations=10;
    std::string name = "Simulation";
   
    //for (int i = 0; i < 3;i++)
    //{
        grid = pow(100, 1) + 2;
        //std::thread sys1 (
        evolve(0,grid,iterations, system[0]);
        /*grid = pow(100, 2) + 2;
        std::thread sys2 (evolve,1,grid,iterations, system[1]);
        grid = pow(100, 3) + 2;
        std::thread sys3 (evolve,2,grid,iterations, system[2]);*/
        /*
        grid = pow(100, i+1) + 2;
        system[i] = initialsystem(grid);
        doc.open("Simulation"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system[i] = SimpleEvolveNeuman(system[i]);
            tofile(system[i],i);
        }
        doc.close();
        animate("Simulation", "Simulation", "Teste",80,i,system[i].size());*/
    //}
    //sys1.join();
    std::cout << "Process 1 complete" << std::endl;
    /*sys2.join();
    std::cout << "Process 2 complete" << std::endl;
    sys3.join();
    std::cout << "Process 3 complete" << std::endl;*/
    return 0;
}
void evolve(int i,int grid, int iterations, std::vector<std::vector<int>>system)
 {
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("Simulation"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system = SimpleEvolveNeuman(system);
            tofile(system,i);
        }
        doc.close();
        animate("Simulation", "Simulation",40,i,system.size());
}