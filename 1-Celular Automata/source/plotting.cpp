#include"../include/plotting.hpp"

void animate(std::string input, std::string output, int delay,int number,int size)
{
    FILE *gnu = _popen("gnuplot -persist", "w");
    if(gnu)
    {
        fprintf(gnu,"set terminal gif animate delay %i\n",delay);
        fprintf(gnu,"set output \'animation/Simulation%i.gif\'\n",number);
        fprintf(gnu,"set palette defined (0 'white', 1 'black')\n");
        //fprintf(gnu,"set title \'%s\'\n",title );
        fprintf(gnu,"set size square\n");
        fprintf(gnu,"unset colorbox\n");
        fprintf(gnu,"set xrange [0:%i]\n",size-2);
        fprintf(gnu,"set yrange [0:%i]\n",size-2);
        fprintf(gnu,"stats \'Simulation%i.dat\' name \'A\'\n",number);
        fprintf(gnu, "do for [i=0:int(A_blocks-2)]{\n");
        fprintf(gnu,"set title \"Iteration\".i\n");
        fprintf(gnu,"plot \'Simulation%i.dat\' index i matrix w image}\n",number);
        /*fprintf(gnu,"    \n", );
        fprintf(gnu,"    \n", );*/
    }
}
void tofile(std::vector<std::vector<int>> system, int number)
{
    std::ofstream out;
    out.open("Simulation"+ std::to_string(number) + ".dat",std::ios::out|std::ios::app);
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