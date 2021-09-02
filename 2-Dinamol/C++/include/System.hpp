#include<vector>
#include<iostream>
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
        double V;

    public:
        System(int exponent, double initialTemperature,
               double step, double end, double sizes[2]); //System initialization
        double getTemperature();
        std::vector<double> getX();
        std::vector<double> getY();
        std::vector<double> getVx();
        std::vector<double> getVy();
        void setL(double L);
        void evolution();
        void potential();
        void reflection();
        double getEnergy();
};
