#include<vector>
#include"functions.hpp"
#include"algebra.hpp"
class System
{
private:
    int dimension[2];
    double energy;
    double temperature;
    std::vector<std::vector<double>> cells[2];
    double length;
    double displace;
    int particles;


public:
    System(int size[2], int exponent, double l, double D, double T);
    double getEnergy();
    double getTemperature();
    std::vector<std::vector<double>> getCells(int i);
    double getLength();
    double getDisplace();
    int getParticles();
    void evolve();
    void status();

};