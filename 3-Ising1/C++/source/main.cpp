#include<iostream>
#include <fstream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<thread>
#include<future>
#include<chrono>
#include"../include/algebra.hpp"
#include"../include/functions.hpp"

int main()
{
    int steps;
    int init;
    auto start = std::chrono::high_resolution_clock::now();
    


    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;
    /*std::cout << "A operação terminou, aperte \"enter\" para sair" << std::endl;
    getchar();*/
    return 0;
}