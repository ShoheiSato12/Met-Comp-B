#include"../include/general.hpp"

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
std::vector<std::vector<int>> resistance(std::vector<std::vector<int>>&auxsystem,std::vector<std::vector<int>>system,double perc)
{
    int aux = 0;
    while (aux!=(int)perc*system.size())
    {
        int i = rand()%system.size();
        int j = rand()%system.size();
        switch (system[i][j])
        {
            case 0:
                break;

            case 1:
                auxsystem[i][j] = 1;
                aux++;
                break;
        }
    }
    return auxsystem;
}