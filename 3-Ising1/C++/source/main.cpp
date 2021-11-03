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
#include"../include/System.hpp"

int main()
{
    int steps;
    int init;
    auto start = std::chrono::high_resolution_clock::now();
    int dimension[2] = {5, 5};
    System sistema = System(dimension,2,0,1);
    std::cout << sistema.getE() << std::endl;
    sistema.evolve();
    //sistema.plot();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;
    /*std::cout << "A operação terminou, aperte \"enter\" para sair" << std::endl;
    getchar();*/
    return 0;
}