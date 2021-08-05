#include"../include/automataNeuman.hpp"

void SimpleNeuman(int i,const char* name,int grid, int iterations, std::vector<std::vector<int>>system)
{
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("DAT/Neuman/Normal/Simulations"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system = SimpleEvolveNeuman(system);
            tofile("Neuman/Normal",system,i);
        }
        doc.close();
        //animate("Neuman/Normal",name, "animation/Neuman/Normal",40,i,system.size()-2);
}
void ResistanceNeuman(int i,const char* name,int grid, int iterations, std::vector<std::vector<int>>system)
{
        std::ofstream doc;
        system = initialsystem(grid);
        doc.open("DAT/Neuman/Resistance/Simulations"+std::to_string(i)+".dat",std::ios::out|std::ios::trunc);
        for (int j = 0; j < iterations;j++)
        {
            system = ResistanceEvolveNeuman(system);
            tofile("Neuman/Resistance",system,i);
        }
        doc.close();
        animate("Neuman/Resistance",name, "animation/Neuman/Resistance",40,i,system.size()-2);
}
std::vector<std::vector<int>> SimpleEvolveNeuman(std::vector<std::vector<int>> system)
{
    std::vector<std::vector<int>> auxsystem=system;
    int iter = (int)system.size()-2;
    for (int i = 1; i < iter; i++)
    {
        for (int j = 1; j < iter; j++)
        {
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
std::vector<std::vector<int>> ResistanceEvolveNeuman(std::vector<std::vector<int>> system)
{
    std::vector<std::vector<int>> auxsystem;
    int iter = (int)system.size()-2;
    auxsystem = SimpleEvolveNeuman(system);
    auxsystem = resistance(auxsystem, system, 0.7);
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
