#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<thread>
#include<future>
#include<chrono>
#include"../include/functions.hpp"
#include"../include/System.hpp"

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream file;
    file.open("output/txt/points.txt");//Colocar mais elementos de inicialização do arquivo
    
    double size[2] = {2, 2}; //Dimension of system
    System sys = System(5,52,0.01,1,size);
    sys.setL(3.0);
    sys.evolution();
    
    std::cout << sys.getX()[10];

    file.close();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;

}