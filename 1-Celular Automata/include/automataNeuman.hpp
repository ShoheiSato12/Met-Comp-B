#include<vector>
void SimpleNeuman(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
void ResistanceNeuman(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
std::vector<std::vector<int>> initialsystem(int dimension);
std::vector<std::vector<int>> SimpleEvolveNeuman(std::vector<std::vector<int>> system);
std::vector<std::vector<int>> ResistanceEvolveNeuman(std::vector<std::vector<int>> system);
int countNeumanNeighbour(std::vector<std::vector<int>> system, int i, int j);
void counting(std::vector<std::vector<int>> system, std::vector<std::vector<int>>& auxsystem,int i, int j);
void resistence(std::vector<std::vector<int>>&auxsystem,std::vector<std::vector<int>>system,int perc);