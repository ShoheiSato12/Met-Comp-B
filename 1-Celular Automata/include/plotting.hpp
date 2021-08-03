#include<fstream>
#include<iostream>
#include<string>
#include<vector>

void animate(const char* name,const char* input, const char* output, int delay, int number, int size);
void tofile(std::string name,std::vector<std::vector<int>> system, int number);