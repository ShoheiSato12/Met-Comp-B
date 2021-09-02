#pragma once
#include<cmath>
#include<thread>
#include"../include/System.hpp"
#include"../include/functions.hpp"
System::System(int exponent, double initialTemperature,
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
double System::getTemperature()
{
    return Temperature;
}
std::vector<double> System::getX()
{
    return x;
}
std::vector<double> System::getY()
{
    return y;
}
std::vector<double> System::getVx()
{
    return vx;
}
std::vector<double> System::getVy()
{
    return vy;
}
void System::setL(double L)
{
    l = L;
}
void System::evolution()
{

}
void System::potential()
{
    V=0;
    for(int i =0;i<particles-2;i++)
    {

    }
}
void System::reflection()
{

}
double System::getEnergy()
{
    return energy;
}