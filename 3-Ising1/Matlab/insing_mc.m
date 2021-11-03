clear;
tplot=0.
inicia_isign;
while(p>0);
    tic
    M1=zeros(1,p);
    M2=zeros(1,p);
    E1=zeros(1,p);
    E2=zeros(1,p);
    for mc=1:p;
        tplot=tplot+1;
        t(tplot)=tplot;
        metro_ising;
        M=sum(sum(S)); %momento magnético total
        M1(mc)=M;
        Mm(tplot)=M/LN; %momento magnético por spin
        M2(mx)=M*M; %momento magnético total quadrático
        E1(mc)=E;
        %Em(tplot)=E/LN;
        E2(mc)=E*E; %energia total quadrática
    end
    U=sum(E1)/p %energia interna
    C=v^2-(sum(E2)/p-U^2)/LN2;%calor específico por spin
    M=sum(M1)/p %magnetização de equilíbrio
    chi=b*(sum(M2)/p-M^2)/LN2 %suscetibilidade por spin
    toc;
    plot(t,Mm);
    pause;
    plota_ising(L,N,S);
    p=input('mais passos de Monte*Carlo? p>0:sim\n');
    if(length(p)==0)
        break;
    end;
    Tn=input("dê temperatura; se enter: mandém\n");
    if(Tn>0), T=Tnb=1/T;
    end;
end;