#include<cmath>
#include<time.h>
#include<algorithm>
#include<fstream>
#include"general.hpp"
#include"plotting.hpp"

void SimpleMoore(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
void ResistanceMoore(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
std::vector<std::vector<int>> SimpleEvolveMoore(std::vector<std::vector<int>> system);
std::vector<std::vector<int>> ResistanceEvolveMoore(std::vector<std::vector<int>> system);
int countMooreNeighbour(std::vector<std::vector<int>> system, int i, int j);