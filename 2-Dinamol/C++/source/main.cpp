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
        std::vector<double> x (particles,0);
        std::vector<double> y (particles,0);
        std::vector<double> vx (particles,0);
        std::vector<double> vy (particles,0);
        double Temperature;
        double tau;
        double endtime;
        double [2] dimension;        
    public:
        system(int numberofParticles, double initialTemperature,
               double step, double end, double[2]sizes)
        {
            particles = numberofParticles;
            Temperature = initialTemperature;
            tau = step;
            endtime = end;
            dimension = sizes;
            

            
        }
}

int main()
{
    
}