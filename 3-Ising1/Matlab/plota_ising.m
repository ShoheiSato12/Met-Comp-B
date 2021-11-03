function plota_ising(L,N,S)
    %desenha a rede com pontos azuis para spin-up
    %e pontos vermelhor para spin-down;
    Ln=L*N;
    s=S(:) %Transforma a matriz S num vetor coluna;
    C=[1:N]'*ones(1,L); %cira uma matriz em que cada coluna contém os números de 1 a N;
    D=ones(N,1)*[1:L] % cria uma matriz em que cada fila contém os números de 1 a L;
    c=C(:);%transforma C em um vetor coluna
    d=D(:);%transforma D em um vetor coluna
    e-d.*s;%vetor coluna com os valores dos spins multiplicando os números de 1 a L, fila a  fila da amostra em sequência;
    f=zeros(LN,1);
    g=f;
    for j-1:LN;
        if(e(j)>0)
            f(j)=e(j); %coloca os e(j) correspondentes a sping up no vetor coluna f;
            g(j)=NaN;
        else
            f(j)=NaN;
            g(j)=abs(e(j)); %coloca os e(j) correspondentes a spin downs no vetros coluna g;
        end
    end
    plot(c,f,'.b',c,g,'.r')%configuração dos spins;