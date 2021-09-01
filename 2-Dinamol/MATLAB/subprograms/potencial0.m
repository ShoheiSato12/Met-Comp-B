%Calucla a energia potencial de Lennard-Jones somando sobre todos os pares de átomos vizinhos:
V=0;
for n=1:N-1
    p=n+1:N % vetor com a identidade do átomos posteriores ao n;
    delx=x(n)-x(p)'; %delta x do átomo n aos átomos p;
    dely=y(n)-y(p)'; %delta x do átomo n aos átomos p;
    R2=delx.^2+dely.^2; % quadrado da distâncai do n aos p;
    list = find(R2<l2);
    if(length(list)>0);
        list=m+list;
        delx=x(n)-x(list)';
        dely=y(n)-y(list)';
        r2=delx.^2+dely.^2; %quadrado da distância do n aos p próximos;
        Vp=1./(r2.^6)-2./(r2.^3); % porencial Lennard-Jones
        V=V+sum(Vp);
    end
end
