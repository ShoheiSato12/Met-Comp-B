#include<vector>
#include<algorithm>
#include"functions.hpp"
#include"algebra.hpp"
class System
{
private:
    double dimension[2];
    double energy;
    double dE;
    double potential;
    double temperature;
    std::vector<std::vector<int>> cells[2];
    std::vector<std::vector<int>> numcells;
    std::vector<double> X;
    std::vector<double> Y;
    double length;
    double displace; //Between -0.5 and 0.5 for optimal performance
    int particles;
    int xcel;
    int ycel;
    int Nc;
    std::vector<int> neighbor[8];
    std::vector<int> num;
    std::vector<std::vector<int>> lista;
    std::vector<int> v[8];

public:
    System(double size[2], int exponent, double l, double D, double T);
    double getEnergy();
    double getTemperature();
    std::vector<std::vector<int>> getCells(int i);
    double getLength();
    double getDisplace();
    int getParticles();
    int getXcel();
    int getYcel();
    void evolve();
    void status();
    void list();
    void entorno();
};