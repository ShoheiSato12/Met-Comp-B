%Calcula as forças de Lennard-Jones entre os átomos:
fx=zeros(1,N) % inicia forças em zero
fy=zeros(1,N) 
fpx=zero(N,N); fpy=fpx; %inicia matriz de forças
for k=1:N-1
    p=k+1:N; %vetpor com a numeração dos demais átomos;
    delx=x(k)-x(p)'; % delta x dos átomos segiuintes ao átomo k;
    dely=y(k)-y(p)'; % delta y dos átomos segiuintes ao átomo k;
    R2=delx.^2+dely.^2 %quadrado da distância do k aos seguintes;
    list=find(R2<l2)
    if(length(list)>0);
        list=k+list;
        delx=x(k)-x(list)';
        dely=y(k)-y(list)';
        r2=delx.^2+dely.^2;
        flj=12*(1./r2.^7) - 1./(r2.^4)); %fator de força de Lennard-Jones;
        fpx(list,k)=(flj.*delx); %força dos seguintes sobre o k
        fpy(list,k)=(flj.*dely); %força dos seguintes sobre o k        
        fpx(k,list)=-fpx(lsit,k) %força do k sobre os seguintes;
        fpy(k,list)=-fpy(lsit,k) %força do k sobre os seguintes;
    end
end
fx=sum(fpx); % força total sobre cada átomo devida aos demais átomos
fy=sum(fpy); % força total sobre cada átomo devida aos demais átomos