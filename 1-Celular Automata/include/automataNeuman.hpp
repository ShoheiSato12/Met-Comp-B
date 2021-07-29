#include<vector>
std::vector<std::vector<int>> initialsystem(int dimension);
std::vector<std::vector<int>> SimpleEvolveNeuman(std::vector<std::vector<int>> system);
int countNeumanNeighbour(std::vector<std::vector<int>> system, int i, int j);
void counting(std::vector<std::vector<int>> sys, std::vector<std::vector<int>>& auxsys,int i, int j);
void example();