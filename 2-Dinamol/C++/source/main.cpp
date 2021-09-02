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
    
    double size[2]={2, 2};
    System sys = System(5,52,0.01,1,size);
    //sys.setL(3.0);
    //std::cout << sys.getX()[5];
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;
}