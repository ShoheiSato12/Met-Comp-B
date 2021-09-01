#include<iostream>
#include<cmath>
#include<vector>
#include<algorithm>
#include<thread>
#include<future>

class system
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
    public:
        system(int numberofParticles, double initialTemperature,
               double step, double end, double sizes[2])
        {
            particles = numberofParticles;
            Temperature = initialTemperature;
            tau = step;
            endtime = end;
            dimension[0] = sizes[0];
            dimension[1] = sizes[1];
            std::vector<double> aux (particles,0);
            x=aux;
            y=aux;
            vy=aux;
            vx=aux;
            

            
        }
};

int main()
{
    std::cout<<"Hello";
}