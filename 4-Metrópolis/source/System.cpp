#include"../include/System.hpp"
System::System(double size[2], int exponent, double l, double D, double T)
{
    energy = 0;
    dimension[0] = size[0];
    dimension[1] = size[1];
    particles = pow(4, exponent);
    length = l;
    displace = D;
    temperature = T;
    xcel = ceil(dimension[0] / length);
    ycel = ceil(dimension[1] / length);
    dimension[0] = xcel * length;
    dimension[1] = ycel * length;
    int surface = dimension[0] * dimension[1];
    double parameter = sqrt(surface / particles);
    int Nx = ceil(dimension[0] / parameter);
    int Ny = ceil(dimension[1] / parameter);
    if(Nx<Ny)
    {
        parameter = Nx;
    }
    else
    {
        parameter = Ny;
    }
    std::vector<double> aux(particles, 0);
    X = aux;
    Y = aux;
    for (int i = 0; i < particles; i++)
    {
        double z = i / Nx;
        X[i] = parameter * (Nx * (z - ((int)(z))) + 0.5);
        Y[i] = parameter * std::abs((ceil(i+1 / Nx) - 0.5));
    }
    Nc = xcel * ycel;
    std::vector<std::vector<int>> auxi(ycel, std::vector<int>(xcel, 0));
    numcells = auxi;
    int m = 1;
    for (int i = 0; i < xcel; i++)
    {
        for (int j = 0; j < ycel;j++)
        {
            numcells[i][j] = m;
            m++;
        }
    }
}
double System::getEnergy() 
{
    return energy;
}
double System::getTemperature() 
{
    return temperature;
}
std::vector<std::vector<int>> System::getCells(int i) 
{
    return cells[i];
}
double System::getLength() 
{
    return length;
}
double System::getDisplace() 
{
    return displace;
}
int System::getParticles() 
{
    return particles;
}
int System::getXcel() 
{
    return xcel;
}
int System::getYcel() 
{
    return ycel;
}
void System::evolve() //Falta
{
    for (int a = 0; a < particles;a++)
    {
        int n = (int)(particles * rand() / RAND_MAX);
        int i = (int)(Y[n] / length);
        int j = (int)(X[n] / length);
        int c = numcells[i][j];

        double dx = displace * (rand() / RAND_MAX - 0.5);
        double dy = displace * (rand() / RAND_MAX - 0.5);
        double xn = X[n] + dx;
        double yn = Y[n] + dy;
        bool trans=false;
        if (xn > 0 && xn < dimension[0] && yn > 0 && yn < dimension[1])
        {
            //exetutável de potencial_gas.sce
            int nc = num[c];
        }
    }
}
void System::status() //Falta
{

}
void System::list()
{
    std::vector<int>aux(Nc+1,0);
    num = aux;
    std::vector<int> cel(particles, 0);
    for (int n = 0; n < particles;n++)
    {
        int i = (int)(ceil(Y[n] / length)) % ycel;
        int j = (int)(ceil(X[n] / length)) % xcel;
        int c = numcells[i][j];
        num[c]++;
        cel[n] = c;
    }
    int max = *max_element(num.begin(), num.end());
    lista=MatrixInitializationInt(Nc+1,max);
    std::vector<int> pos(Nc, 0);
    for (int i = 0; i < particles;i++)
    {
        int c = cel[i];
        pos[c]++;
        lista[c%(Nc+1)][pos[c]%max] = i;
    }
}
void System::entorno()
{
    std::vector<int> aux(Nc, 0);
    for (int i = 0; i < 8;i++)
    {
        v[i] = aux;
    }
    int c;
    printmatrix(numcells);
    std::cout << ycel << "   " << xcel << std::endl;
    for (int i = 1; i < ycel - 2; i++) //vizinhas do corpo principal
    {
        for (int j = 1; j < xcel-2; j++)
        {
            c = numcells[i][j] - 1;
            std::cout << c << std::endl;
            v[0][c] = numcells[i - 1][j - 1];
            v[1][c] = numcells[i - 1][j];
            v[2][c] = numcells[i - 1][j + 1];
            v[3][c] = numcells[i][j - 1];
            v[4][c] = numcells[i][j + 1];
            v[5][c] = numcells[i + 1][j - 1];
            v[6][c] = numcells[i + 1][j];
            v[7][c] = numcells[i + 1][j + 1];
        }
    }
    //vizinhas da primeira fila
    for (int j = 1; j < xcel-2; j++)
    {
        c = numcells[1][j] - 1;
        v[0][c] = Nc;
        v[1][c]=Nc;
        v[2][c]=Nc;
        v[3][c]=numcells[1][j-1];
        v[4][c]=numcells[1][j+1];
        v[5][c]=numcells[2][j-1];
        v[6][c]=numcells[2][j];
        v[7][c]=numcells[2][j+1];
    }
    for (int i = 1; i < ycel-2; i++)//vizinhas da primeira coluna
    {
        c = numcells[1][i] - 1;
        v[0][c] = Nc + 1;
        v[1][c] = numcells[i - 1][1];
        v[2][c] = numcells[i - 1][2];
        v[3][c] = Nc + 1;
        v[4][c] = numcells[i][2];
        v[5][c] = Nc + 1;
        v[6][c] = numcells[i + 1][1];
        v[7][c] = numcells[i + 1][2];
    }
    
    for (int j = 1; j < xcel-2; j++)//vizinhas da útlima fila
    {
        c = numcells[xcel - 1][j] - 1;
        v[0][c] = numcells[ycel - 2][j - 1];
        v[1][c] = numcells[ycel - 2][j];
        v[2][c] = numcells[ycel - 2][j + 1];
        v[3][c] = numcells[ycel - 1][j - 1];
        v[4][c] = numcells[ycel - 1][j + 2];
        v[5][c] = Nc + 1;
        v[6][c] = Nc + 1;
        v[7][c] = Nc + 1;
    }

    for (int i = 1; i < xcel-2; i++)//vizinhas da última coluna
    {
        c = numcells[i][xcel - 1] - 1;
        v[0][c] = numcells[i - 1][xcel - 2];
        v[1][c] = numcells[i - 1][xcel - 1] ;
        v[2][c] = Nc + 1;
        v[3][c] = numcells[i][xcel - 2];
        v[4][c] = Nc + 1;
        v[5][c] = numcells[i + 1][xcel - 2];
        v[6][c] = numcells[i + 1][xcel - 1];
        v[7][c] = Nc;
    }
    //vizinha da célula 1
    v[0][0] = Nc + 1;
    v[1][0] = Nc + 1;
    v[2][0] = Nc + 1;
    v[3][0] = Nc + 1;
    v[4][0] = 2;
    v[5][0] = Nc + 1;
    v[6][0] = xcel;
    v[7][0] = xcel + 1;
    //vizinha da célula xcel    
    v[0][xcel-1]=Nc;
    v[1][xcel-1]=Nc;
    v[2][xcel-1]=Nc;
    v[3][xcel-1]=xcel-2;
    v[4][xcel-1]=Nc;
    v[5][xcel-1]=numcells[1][xcel-2];
    v[6][xcel-1]=numcells[1][xcel-1];
    v[7][xcel-1]=Nc;
    //vizinhas da célula ycel
    c = numcells[ycel - 1][0] - 1;
    v[0][c] = Nc;
    v[1][c] = numcells[ycel - 2][0];
    v[2][c] = numcells[ycel - 2][1];
    v[3][c] = Nc;
    v[4][c] = numcells[ycel - 1][1];
    v[5][c] = Nc;
    v[6][c] = Nc;
    v[7][c] = Nc;
    //vizinhas da célula Nc    
    v[0][Nc-1]=numcells[ycel-2][xcel-2];
    v[1][Nc - 1] = numcells[ycel - 2][xcel - 1];
    v[2][Nc - 1] = Nc;
    v[3][Nc - 1] = numcells[ycel - 1][xcel - 2];
    v[4][Nc - 1] = Nc;
    v[5][Nc - 1] = Nc;
    v[6][Nc - 1] = Nc;
    v[7][Nc - 1] = Nc;
}