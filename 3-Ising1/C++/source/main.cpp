#include<iostream>
#include<fstream>
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
    int dimension[2] = {100, 100};
    bool confirmation = true;
    auto start = std::chrono::high_resolution_clock::now();
    std::ofstream point("output/dat/spin.dat");
    System sistema= System(dimension, 2, 0, 1);
    steps = 200;
    while (confirmation)
    {

        for (int i = 0; i < steps;i++)
        {
            sistema.evolve();
            tofile(sistema.getSpin());

        }
        std::cout << std::endl
                  << "Continuar mais passos?" << std::endl
                  << "Caso positivo insira o número de passos a mais" << std::endl
                  << "Caso negativo insira \"0\"" << std::endl;
        std::cin>>steps;
        switch (steps)
        {
        case 0:
            confirmation = false;
            break;

        default:
            break;
        }
        plot();
    }

    point.close();
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;
    /*std::cout << "A operação terminou, aperte \"enter\" para sair" << std::endl;
    getchar();*/
    return 0;
}