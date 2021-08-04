#include<cmath>
#include<time.h>
#include<vector>
#include<algorithm>
#include<fstream>
#include"../include/automataMoore.hpp"
#include"../include/automataNeuman.hpp"
#include"../include/plotting.hpp"

void SimpleMoore(int i,const char* name,int grid, int iterations, std::vector<std::vector<int>>system)
{
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("DAT/Moore/Normal/Simulations"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system = SimpleEvolveNeuman(system);
            tofile("Moore/Normal",system,i);
        }
        doc.close();
        animate("Moore/Normal",name, "animation/Moore/Normal",40,i,system.size()-2);
}
void ResistanceMoore(int i,const char* name,int grid, int iterations, std::vector<std::vector<int>>system)
{
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("DAT/Moore/Resistance/Simulations"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system = ResistanceEvolveNeuman(system);
            tofile("Moore/Resistance",system,i);
        }
        doc.close();
        animate("Moore/Resistance",name, "animation/Moore/Resistance",40,i,system.size()-2);
}
std::vector<std::vector<int>> SimpleEvolveMoore(std::vector<std::vector<int>> system)
{
    std::vector<std::vector<int>> auxsystem = system;
    int size = (int)system.size() - 2;
    for (int i = 1; i < size;i++)
    {
        for (int j = 1; j < size;j++)
        {
            int aux = countMooreNeighbour(system, i, j);
            switch (system[i][j])
            {
                case 0:
                    if(aux>6)
                    {
                        auxsystem[i][j] = 1;
                    }
                    break;
                
                case 1:
                    if(aux<5 || aux>6)
                    {
                        auxsystem[i][j] = 0;
                    }
                    break;
            }
        }
    }
    return auxsystem;
 }
 int countMooreNeighbour(std::vector<std::vector<int>> system,int i, int j)
 {    
    int result;
    std::vector<int> auxiliar;
    for (int k = i - 1; k < i + 2; k++)
    {
        for (int l = j - 1; l < j + 2;l++)
        {
            auxiliar.push_back(system[k][l]);
        }
    }
    auxiliar.erase(auxiliar.begin()+4);
    result = std::count(auxiliar.begin(),auxiliar.end(),1);
    return result;
 }