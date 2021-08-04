#include<vector>
void SimpleMoore(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
void ResistanceMoore(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
std::vector<std::vector<int>> SimpleEvolveMoore(std::vector<std::vector<int>> system);
int countMooreNeighbour(std::vector<std::vector<int>> system, int i, int j);