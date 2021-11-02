#include<iostream>
#include <fstream>
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
    std::ofstream doc1;
    std::ofstream doc2;
    doc1.open("output/dat/points.dat");
    doc2.open("output/dat/velocity.dat");
    
    double size[2] = {2, 2}; //Dimension of system
    System sys = System(5,200,0.01,2,size);
    sys.setL(3.0);
    /*for (uint i = 0; i < sys.getX().size();i++)
    {
        std::cout << sys.getX()[i] << "   " << sys.getY()[i] << std::endl;
    }
    std::cout << std::endl
              << std::endl;
    for (uint i = 0; i < sys.getX().size(); i++)
    {
        std::cout << sys.getVx()[i] << "   " << sys.getVy()[i] << std::endl;
    }*/
    sys.evolution();
    sys.plot();
        doc1.close();
    doc2.close();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;
    return 0;
}