#include<string.h>
#include"../include/plotting.hpp"

void animate(const char* name,const char* input, const char* output, int delay,int number,int size)
{
    const char *dat = "DAT/";
    FILE *gnu = popen("gnuplot -persist", "w");
    if(gnu)
    {
        fprintf(gnu,"cd \'./DAT\'\n");
        fprintf(gnu,"set terminal gif animate delay %i\n",delay);
        fprintf(gnu,"set output \'../%s/Simulations%i.gif\'\n",output,number);
        fprintf(gnu,"set palette defined (0 'white', 1 'black')\n");
        //fprintf(gnu,"set title \'%s\'\n",title );
        fprintf(gnu,"set size square\n");
        fprintf(gnu,"unset colorbox\n");
        fprintf(gnu,"set xrange [0:%i]\n",size-2);
        fprintf(gnu,"set yrange [0:%i]\n",size-2);
        fprintf(gnu,"stats \'%s/Simulations%i.dat\' name \'A\'\n",name,number);
        fprintf(gnu, "do for [i=0:int(A_blocks-2)]{\n");
        fprintf(gnu,"set title \"%s Iteration\".i\n",name);
        fprintf(gnu,"plot \'%s/Simulations%i.dat\' index i matrix w image}\n",name,number);
        /*fprintf(gnu,"    \n", );
        fprintf(gnu,"    \n", );*/
    }
}
void tofile(std::string name,std::vector<std::vector<int>> system, int number)
{
    std::ofstream out;
    name = "DAT/" + name;
    out.open(name+"/Simulations"+ std::to_string(number) + ".dat",std::ios::out|std::ios::app);
    for (int i = 1; i < system.size() - 1;i++)
    {
        for (int j = 1; j < system[0].size() - 1;j++)
        {
            out << system[i][j]<<"   ";
        }
        out << std::endl;
    }
    out << std::endl << std::endl;
}