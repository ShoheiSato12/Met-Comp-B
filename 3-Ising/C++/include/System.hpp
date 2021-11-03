#include"algebra.hpp"
#include"functions.hpp"
class System
{
private:
    int dimension[2];
    double temperature;
    double field;
    double E; //Energia escalar
    double M; //momento magnético escalar
    double Mperspin; //momento magnético por spin
    std::vector<double> energy;
    std::vector<double> energy2;
    std::vector<double> magnetic;
    std::vector<double> magnetic2;
    std::vector<std::vector<int>> spin;
    double parameter;
    double especific;
    double chi;

public:
    System(int sizes[2],double T, double H,int arr);
    double getTemperature();
    double getField();
    double getE();
    std::vector<double> getEnergy();
    std::vector<double> getEnergy2();
    std::vector<std::vector<int>> getSpin();
    double getParameter();
    double getEspecific();
    void evolve();
    void status(int steps);
};