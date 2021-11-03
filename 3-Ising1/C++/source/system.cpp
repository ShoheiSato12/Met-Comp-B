#include"../include/system.hpp"
double system::getTemperature()
{
    return temperature;
}
double system::getField()
{
    return field;
}
double system::getE()
{
    return E;
}
std::vector<std::vector<double>> system::getEnergy()
{
    return energy;
}
std::vector<std::vector<double>> system::getEnergy2()
{
    return energy2;
}
std::vector<std::vector<double>> system::getSpin()
{
    return spin;
}
double system::getParameter()
{
    return parameter;
}
double system::getEspecific()
{
    return especific;
}
void system::evolve()
{
    
}
void system::status()
{

}