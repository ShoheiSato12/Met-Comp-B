help dinamol0; clear;
inicia0;
while (length(tmax)>0) %calcula enquanto o operador fornecer tempo para continuar
    integra0;
    Ec=(sum(vx.^2)+sum(vy^2))/2; %Energia cinética total
    potencial0; %Energiapotencial total
    Energia=V+Ec;
    ECEPE=[Ec,V,Energia] % apresenta Ec,V,E na tela
    T = Ec/N %Temperatura = energia cinética média
    tmax=input('novo mtamx? se "enter, encerra:\n');
    if(length(tmax)>0);
        Tnova=input ('dê novo T; se "enter", mantém; \n');
    if(length(Tnova)>0);
        renorm=sqrt(Tnova/T); %renormalização das velocidades conforme nova temperatura
        vx = vx*renorm;
        vx = vy*renorm;
        T = Tnova;
    end;
end
end