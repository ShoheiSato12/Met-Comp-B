#include<iostream>
#include<cmath>
#include<algorithm>
#include<thread>
#include<future>
#include"../include/plotting.hpp"
#include"../include/automataNeuman.hpp"
#include"../include/automataMoore.hpp"

static std::mutex locking;
void Neuman(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
void Moore(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
int main()
{
    int grid = 100+2;
    std::vector<std::vector<int>> system;
    int iterations=10;
    char* name = "Simulation";
    std::ofstream doc;
   
    for (int i = 0; i < 3;i++)
    
        {
            grid = pow(10, i) + 2;
            Neuman(i,name,grid,iterations, system);
            Moore(i,name,grid,iterations, system);
        }
    //std::async (Neuman,0,name,grid,iterations, system);
    //std::async(Moore,0,name,grid,iterations, system);
        /*grid = pow(100, 2) + 2;
        std::thread sys2 (evolve,1,grid,iterations, system[1]);
        grid = pow(100, 3) + 2;
        std::thread sys3 (evolve,2,grid,iterations, system[2]);*/

    /*grid = pow(100, 1) + 2;
        system = initialsystem(grid);
        doc.open("Simulation"+std::to_string(1)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system = SimpleEvolveNeuman(system);
            tofile(system,1);
        }
        doc.close();
        animate("Neuman","animation/Neuman".name, name,80,1,system.size()-2);
    //}*/
    //sys1.join();
    //std::cout << "Process 1 complete" << std::endl;
    //sys2.join();
    /*std::cout << "Process 2 complete" << std::endl;
    sys3.join();
    std::cout << "Process 3 complete" << std::endl;*/


    /*grid = pow(100, 1) + 2;
    system = initialsystem(grid);
    doc.open(name+std::to_string(1)+".dat",std::ios::out|std::ios::trunc);
    for (int j = 0; j < iterations;j++)
    {
        system = SimpleEvolveMoore(system);
        tofile(system,1);
    }
    doc.close();
    animate("Moore",name, "animation/Moore",20,1,system.size()-2);
    */

    return 0;
}
void Neuman(int i,const char* name,int grid, int iterations, std::vector<std::vector<int>>system)
{
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("DAT/Neuman/Simulation"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        std::lock_guard<std::mutex> lock(locking);
        for (int j = 0; j < iterations;j++)
        {
            system = SimpleEvolveNeuman(system);
            tofile("Neuman",system,i);
        }
        doc.close();
        animate("Neuman",name, "animation/Neuman",20,i,system.size()-2);
}
void Moore(int i,const char* name,int grid, int iterations, std::vector<std::vector<int>>system)
{
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("DAT/Moore/Simulation"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        std::lock_guard<std::mutex> lock(locking);
        for (int j = 0; j < iterations;j++)
        {
            system = SimpleEvolveNeuman(system);
            tofile("Moore",system,i);
        }
        doc.close();
        animate("Moore",name, "animation/Moore",20,i,system.size()-2);
}