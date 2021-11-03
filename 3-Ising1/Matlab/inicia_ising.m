%Inicialização do ising_mc; rede
%retangular LxN, com opção de estado inicial ordenado
%(T0=0) ou estado inicial totalmente desordenado
%(T0>0); calcula energia inicial;
%Exemplos de dados [L=25,N=30,To=1,T=2,H=0,p=10]
%L é uma dimensão do problema
%N é uma dimensão do proble     ma
%T0 é a sobre os spins, 0 significa todos alinhados, maior que 0 é o valor de correlação
%T é a temperatura
%H é o valor do hamiltoniano
%p é o número de passos necesários para realizar uma medição
par=input('dê[L,N,T0,T,H,p]\n');
L=par(1);N=par(2);T0=par(3);T=par(4);
H=par(5);p=par(6);
b=1/T; % parâmetro beta. com k_B=1;
LN=L*N;
LN2=LN*LN; %LN é o número de spins;
if(T0==0)
    S=ones(L,N);
    E=-2*LN;%escolhemos J=+1 e usaremos condições de contorno periódicas;
    %cada spin tem 4 vizinhos, por isso 2*LN pares;
else
    E=0;
    S=sign(rand(L,N)-0.5);
    for i=1:L-1
        E=E-S(i,:)*S(i+1,:)'; %interação entre a fila i e seguinte
    end
    E=E-S(1,:)*S(L,:)'; %interação entre a primeira e última fila
    for j=1:N-1;
        E=E-S(:,j)'*S(:,j+1); %interação entre coluna j e seguinte
    end
    E=E-S(:,1)'*S(:,N); %interação entre primeira e última coluna
end
