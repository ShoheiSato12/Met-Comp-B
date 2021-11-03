#include"algebra.hpp"
class system
{
private:
    int dimension[2];
    double temperature;
    double field;
    double E;
    std::vector<std::vector<double>> energy;
    std::vector<std::vector<double>> energy2;
    std::vector<std::vector<double>> magnetic;
    std::vector<std::vector<double>> spin;
    double parameter;
    double especific;


public:
   double getTemperature()
   {
       return temperature;
   }
   double getField()
   {
       return field;
   }
   double getE()
   {
       return E;
   }
   std::vector<std::vector<double>> getEnergy()
   {
       return energy;
   }
   std::vector<std::vector<double>> getEnergy2()
   {
       return energy2;
   }
   std::vector<std::vector<double>> getSpin()
   {
       return spin;
   }
   double getParameter()
   {
       return parameter;
   }
   double getEspecific()
   {
       return especific;
   }
    void evolve()
    {
        
    }
    void status()
    {

    }
};