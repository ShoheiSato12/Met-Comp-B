#include<cmath>
#include<time.h>
#include<vector>
#include<algorithm>
#include"../include/automataMoore.hpp"

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