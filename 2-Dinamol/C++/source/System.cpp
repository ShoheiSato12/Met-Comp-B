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
    double surface =dimension[0] *dimension[1];
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
    std::thread f3(parallel, x, y, vx, vy, Temperature, initialX, particles/2, particles*3/4);
    std::thread f4(parallel, x, y, vx, vy, Temperature, initialX, particles*3/4, particles);
    f1.join();
    f2.join();
    f3.join();
    f4.join();
}
//Getters
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
double System::getTotalEnergy()
{
    return energy;
}
double System::getKineticEnergy()
{
    return kinetic;
}
double System::getPotentialEnergy()
{
    return V;
}
//Setters
void System::setL(double L)
{
    l = L;
}
//System functions
void System::evolution() //Complete evolution of system
{
    std::vector<double> fx(particles,0);
    std::vector<double> fy(particles,0);
    double mdt = 0.5 * pow(tau, 2);
    potentialforces(fx, fy);
    for (int i = 0; i < ceil(endtime / tau);i++)
    {
        std::vector<double> auxfx = fx;
        std::vector<double> auxfy = fy;
        for (int j = 0; j < particles;j++)
        {
            x[j]+=vx[j]*tau+mdt*auxfx[j];
            y[j]+=vy[j]*tau+mdt*auxfy[j];
        }
        potentialforces(fx, fy);
        for (int j = 0; j < particles; j++)
        {
            vx[j] += tau * (auxfx[j] + fx[j]) / 2;
            vy[j] += tau * (auxfy[j] + fy[j]) / 2;
        }
        reflection();
        //Initialize plotting
    }
}
void System::reflection()//Complete reflection of particle
{
    auto refl = [&](std::vector<double> coord,std::vector<double> vel, double barrier)
    {
        for (int i = 0; i < particles;i++)
        {
            if(coord[i]<=0)
            {
                coord[i] = 0;
                vel[i] = abs(vel[i]);
            }
            if(coord[i]>=barrier)
            {
                coord[i] = barrier;
                vel[i] = -abs(vel[i]);
            }
        }
    };
    std::thread hor(refl,x,vx,dimension[0]);
    std::thread ver(refl,y,vy,dimension[1]);
}
void System::potentialforces(std::vector<double>&fx,std::vector<double>&fy)
{
    std::vector<std::vector<double>>fpx=MatrixInitialization(particles,particles);
    std::vector<std::vector<double>>fpy=MatrixInitialization(particles,particles);
    std::vector<std::vector<double>>pot=MatrixInitialization(particles,particles);
    auto forcing = [&](std::vector<std::vector<double>>fpx,
                       std::vector<std::vector<double>>fpy,
                       std::vector<std::vector<double>>pot,int i, int j)
    {
        std::vector<std::vector<double>> distance2=MatrixInitialization(particles,particles);
        std::vector<std::vector<double>> deltax=MatrixInitialization(particles,particles);
        std::vector<std::vector<double>> deltay=MatrixInitialization(particles,particles);
        for (int k = i; k < j; k++)
        {
            for(int m = i; m < j; m++)
            {
                deltax[k][m] = x[k] - x[m];
                deltay[k][m] = y[k] - y[m];
                distance2[k][m] =pow(deltax[k][m],2) + pow(deltay[k][m] ,2);
                if(distance2[k][m]<pow(l,2))
                {
                    double factor = 12 * (pow(distance2[m][k], -7) - pow(distance2[m][k], -4));
                    pot[k][m] = pow(distance2[k][m], -6) - 2 * pow(distance2[k][m], -3);
                    fpx[k][m] = factor * deltax[k][m];
                    fpy[k][m] = factor * deltay[k][m];
                }
            }
        }
    };
    std::thread f1(forcing, fpx, fpy, pot, 0, particles / 4);
    std::thread f2(forcing, fpx, fpy, pot, particles / 4, particles / 2);
    std::thread f3(forcing, fpx, fpy, pot, particles / 2, particles * 3/4);
    std::thread f4(forcing, fpx, fpy, pot, particles *3/4 , particles);
    f1.join();
    f2.join();
    f3.join();
    f4.join();
    for (int i = 0; i = particles; i++)
    {
        for (int j = 0; j < particles;j++)
        {
            fx[i] += fpx[j][i];
            fy[i] += fpy[j][i];
        }
    }
    V = internalSum(pot);
    energy(); //Cálculo da energia total do sistema, junto com a energia cinética
}
void System::kinetic ()
{
    K = 0;
    for (int i = 0; i < particles;i++)
    {
        K += (pow(vx[i], 2) + pow(vy[i], 2)) / 2;
    }
}
void System::energy()
{
    kinetic();
    E = V + K;
}