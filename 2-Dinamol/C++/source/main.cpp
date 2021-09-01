#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<thread>
#include<future>
#include"../include/functions.hpp"

class System
{
    private:
        int particles;
        std::vector<double> x;
        std::vector<double> y;
        std::vector<double> vx;
        std::vector<double> vy;
        double Temperature;
        double tau;
        double endtime;
        double dimension[2];
        double l; //Distância de atuação da força, valor recomendado é 3
        double energy;
        double kinetic;
        double potential;

    public:
        System(int numParticles, double initialTemperature,
               double step, double end, double sizes[2]) //System initialization
        {
            particles = numParticles;
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
            for (int i = 0; i < particles;i++)
            {
                double z = (i) / initialX;
                x[i] = parameter * (initialX * (z - (int)z)+ 0.5);
                y[i] = parameter * (ceil(i / initialX) - 0.5);
                vx[i] = sqrt(Temperature) * GaussRand();
                vy[i] = sqrt(Temperature) * GaussRand();
            }

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

        }






};

int main()
{
    double size[2]={2, 2};
    System aux1 (1e4,52,0.01,1,size);
    double z = 2.56;
    std::cout << z - (int)z;
}