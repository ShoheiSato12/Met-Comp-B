#include<vector>
#include<iostream>
#include<fstream>
#include<cmath>
#include<thread>
#include"../include/functions.hpp"
class System
{
    private:
        int particles; //Quantity of particles of system
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
        double E;
        double K;
        double V;

    public:
        System(int exponent, double initialTemperature,
               double step, double end, double sizes[2]); //System initialization
        double getTemperature();
        std::vector<double> getX();
        std::vector<double> getY();
        std::vector<double> getVx();
        std::vector<double> getVy();
        double getTotalEnergy();
        double getKineticEnergy();
        double getPotentialEnergy();
        void setL(double L);
        void evolution();
        void reflection();
        void potentialforces(std::vector<double>&fx,std::vector<double>&fy);
        void kinetic();
        void energy();
        void tofile(std::string name, std::vector<double> xcord, std::vector<double> ycord);
        void plot();
};
