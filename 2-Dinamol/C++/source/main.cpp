#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<thread>
#include<future>
#include<chrono>
#include"../include/functions.hpp"

class System
{
    private:
        int particles;
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> vx;
        std::vector<double> vy;
        std::vector<bool> region;
        double Temperature;
        double tau;
        double endtime;
        double dimension[2];
        double l; //Distância de atuação da força, valor recomendado é 3
        double energy;
        double kinetic;
        double potential;

    public:
        System(int exponent, double initialTemperature,
               double step, double end, double sizes[2]) //System initialization
        {
            particles = pow(4,exponent);
            Temperature = initialTemperature;
            tau = step;
            endtime = end;
            dimension[0] = sizes[0];
            dimension[1] = sizes[1];
            std::vector<double> aux(particles, 0);
            x = aux;
            y = aux;
            vy = aux;
            vx = aux;
            double surface = sizes[0] * sizes[1];
            double parameter = sqrt(surface/particles);
            int initialX = ceil(sizes[0] / parameter);
            int initialY = ceil(sizes[1] / parameter);
            auto parallel = [&](std::vector<double> x, std::vector<double> y, std::vector<double> vx,
                                std::vector<double> vy, double Temperature, int initialX, int j, int k)
            {
                for (int i = j; i < k;i++)
                {
                    double z = (i) / initialX;
                    x[i] = parameter * (initialX * (z - (int)z)+ 0.5);
                    y[i] = parameter * (ceil(i / initialX) - 0.5);
                    vx[i] = sqrt(Temperature) * GaussRand();
                    vy[i] = sqrt(Temperature) * GaussRand();
                }
            };
            std::thread f1(parallel, x, y, vx, vy, Temperature, initialX, 0, particles/4);
            std::thread f2(parallel, x, y, vx, vy, Temperature, initialX, particles/4, particles/2);
            std::thread f3(parallel, x, y, vx, vy, Temperature, initialX, particles/2, particles*2/3);
            std::thread f4(parallel, x, y, vx, vy, Temperature, initialX, particles*2/3, particles);
            f1.join();
            f2.join();
            f3.join();
            f4.join();
        }
        double getTemperature()
        {
            return Temperature;
        }
        std::vector<double> getX()
        {
            return x;
        }
        std::vector<double> getY()
        {
            return y;
        }
        std::vector<double> getVx()
        {
            return vx;
        }
        std::vector<double> getVy()
        {
            return vy;
        }
        void setL(double L)
        {
            l = L;
        }
        void evolution()
        {

        }
        void energies()
        {

        }
        void reflection()
        {

        }
        double getEnergy()
        {
            return energy;
        }






};

int main()
{
    auto start = std::chrono::high_resolution_clock::now();
    double size[2]={2, 2};

    System sys (5,52,0.01,1,size);
    sys.setL(3);
    std::cout << sys.getX()[5];
    auto end = std::chrono::high_resolution_clock::now();
    auto duration = std::chrono::duration_cast<std::chrono::microseconds>(end - start);
    std::cout << std::endl << "Duration " << duration.count() << " ms" << std::endl;
}