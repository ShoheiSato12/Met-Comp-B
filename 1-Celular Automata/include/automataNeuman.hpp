#include<vector>
#include<cmath>
#include<time.h>
#include <cstdio>
#include <algorithm>
#include <fstream>
#include<iostream>
#include"general.hpp"
#include"plotting.hpp"
void SimpleNeuman(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
void ResistanceNeuman(int i, const char *name, int grid, int iterations, std::vector<std::vector<int>> system);
std::vector<std::vector<int>> SimpleEvolveNeuman(std::vector<std::vector<int>> system);
std::vector<std::vector<int>> ResistanceEvolveNeuman(std::vector<std::vector<int>> system);
int countNeumanNeighbour(std::vector<std::vector<int>> system, int i, int j);