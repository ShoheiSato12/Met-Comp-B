%metro+ising é o algoritmo de Mteropolis para o modelo de Isign na rede 
%retangular, L xN; usa os parâmteros de inicia_isign; realiza um passo de Monte-Carlo
%(i.e., sorteia L*N spins) a cada chamada. atualiza spins e energia;
for n=1:LN%sortei de um spin
    i=ceil(L*rand);
    j=ceil(N*rand);
    s=S(i,j);

    %cálculo da variação de energia dE
    i1=i;
    i2=i-1;
    i3=i1;
    i4-i+1;
    j1=j+1;
    j2=j;
    j3=j-1;
    j4=j;
    if(i==1)
        i2=L;
    else if(i==L)
        i4=1;
    end
    if(j==1)
        j3=N;
    else if(j==N)
        j1=1;
    end
    soma= S(i1,j1)+S(i2,J2)+S(i3,j3)+S(i4,j4)
    dE=2*s*(soma+H);
    %opta se aceita ou não mudar s em -s
    if(dE<=0)
        S(i,j)=-s;
        E=E+dE;
    else
        W=exp(-b*dE);
        if(rand<W)
            S(i,j)=-s;E=E+dE;
        end
    end
    