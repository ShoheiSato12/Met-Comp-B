#include"../include/System.hpp"
System::System(int sizes[2],double T, double H,int arr)
{
    dimension[0] = sizes[0];
    dimension[1] = sizes[1];
    temperature = T;
    field = H;
    parameter = 1 / temperature;
    if(arr==0)
    {
        spin = std::vector<std::vector<int>>(dimension[0], std::vector<int>(dimension[1], 1));
        E = -2 * dimension[0] * dimension[1];
    }
    else
    {
        E = 0;
        spin = randspin(dimension);
        for (int i = 0; i < dimension[0]-1;i++)
        {
            for (int j = 0; j < dimension[1];j++)
            {
                E -= spin[i][j] * spin[i + 1][j];
            }
        }

        for (int i = 0; i < dimension[1];i++)
        {
            E -= spin[0][i] * spin[dimension[0]-1][i];
        }

        for (int i = 0; i < dimension[1]-1;i++)
        {
            for (int j = 0; j < dimension[0];j++)
            {
                E -= spin[j][i] * spin[j][i+1];
            }
        }

        for (int i = 0; i < dimension[0];i++)
        {
            E -= spin[i][0] * spin[i][dimension[1]-1];
        }

    }
}
double System::getTemperature()
{
    return temperature;
}
double System::getField()
{
    return field;
}
double System::getE()
{
    return E;
}
std::vector<double> System::getEnergy()
{
    return energy;
}
std::vector<double> System::getEnergy2()
{
    return energy2;
}
std::vector<std::vector<int>> System::getSpin()
{
    return spin;
}
double System::getParameter()
{
    return parameter;
}
double System::getEspecific()
{
    return especific;
}
void System::evolve()
{
    for (int i = 0; i < dimension[0] * dimension[1];i++)
    {
        int a = (int)dimension[0] * (double)rand() / RAND_MAX;
        int b = (int)dimension[1] * (double)rand() / RAND_MAX;
        int auxspin = spin[a][b];
        int  i1,  i2,  i3,  i4;
        int  j1,  j2,  j3,  j4;
        i1 = a;
        i2 = a - 1;
        i3 = i1;
        i4 = a + 1;
        j1 = b + 1;
        j2 = b;
        j3 = b - 1;
        j4 = b;
        if(a==1)
        {
            i2 = dimension[0];
        }
        else if(a==dimension[0])
        {
            i4 = 1;
        }
        if(b==1)
        {
            j3 = dimension[1];
        }
        else if(b=dimension[1])
        {
            j1 = 1;
        }
        int sum = spin[i1][j1]+spin[i2][j2]+spin[i3][j3]+spin[i4][j4];
        double dE = 2 * auxspin * (sum + field);

        if(dE<=0)
        {
            spin[a][b] = -auxspin;
            E += dE;
        }
        else
        {
            double work = exp(-parameter * dE);
            if((double)rand()/RAND_MAX < work)
            {
                spin[a][b] = -auxspin;
                E += dE;
            }
        }
    }
    M = internalSum(spin);
    Mperspin = M / (dimension[0] * dimension[1]);
    magnetic.push_back(M);
    magnetic2.push_back(M*M);
    energy.push_back(E);
    energy2.push_back(E*E);
    //tofile();
}
void System::status(int steps)
{
    double U = internalSum(energy)/steps;
    double mag = internalSum(magnetic) / steps;
    especific = pow(parameter, 2) - (internalSum(energy2) / steps - pow(U, 2)) / pow(dimension[0] * dimension[1], 2);
    chi = parameter * (internalSum(energy2) / steps - pow(mag, 2)) / pow(dimension[0] * dimension[1], 2);

}