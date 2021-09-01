%inicia programa de Dinâmica Molecular;
par=input('dê [X,Y,l,N,dt,tmax,T]\n');
X=par(1); Y=par(2); l=par(3); N=par(4);
dt=par(5); tmax=par(6); T=par(7); l2=l^2;
S=X*Y; % área de amostra;
a=sqrt(S/N); % parâmetro de rede para encher o espaço com N pontos;
Nx=ceil(X/a); % númerp de sítios iniciais ao longo de x
Ny=ceil(Y/a); % mesmo para o eixo y 
a=min(x/Nx,Y/Ny)/; %se necessário, diminui "a" para caberem Nx átomos em X e Ny em Y
x=zeros(1,N); y=zeros(1,N);
for n=1:n
    z=(n-z)/Nx;
    x(n)=a*(Nx*(z-floor(z)+0.5); %define coord x inicial
    y(n)=a*(ceil(n/Nx)-0.5); %define coordenada y inicial;
end
%velocidades iniciais sorteadas à temperatura Y:
vx=sqrt(T)*randn(1,N);
vy=sqrt(T)*randn(1,N);