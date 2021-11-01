%integra a equação de movimento de dinâmica molecular por velocity-verlet
dt2=dt*dt; mdt2=0.5*dt2; h=dt/2
itmax=ceil(tmax/dt);
forcas0; % calcula as froças entre o átomos
for it=1:itmax;
    fxi=fx; fyi=fy;
    x=x+vx*dt+mdt2*fxi;
    y=y+vy*dt+mdt2*fyi;
    forcas0;
    vx=vx+h*(fy+fyi); %Velocidade no fim do intervalo
    vy=vy+h*(fy+fyi); %Velocidade no fim do intervalo
    reflete0;
    plot(x,y,'o')
    %pause(0.01) % em MATLAB é necessário esse "pause"
end
