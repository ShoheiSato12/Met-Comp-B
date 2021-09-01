%Átomos fora da amostra têm suas velocidades refletidas e são re-posicionados sobre as paredes:
list1=find(x<=0); %identidade dos átomos que atingiram a parede esquerda;
if(length(list1)>0);
    vx(list1)=abs(vx(list1)); %reflete as velocidades
    x(list1)=0;
end
list2=find(x>=X); %identidade dos átomos que atingiram a parede esquerda;
if(length(list2)>0);
    vx(list2)=-abs(vx(list2)); %reflete as velocidades
    x(list2)=X;
end
list3=find(y<=0); %identidade dos átomos que atingiram a parede esquerda;
if(length(list3)>0);
    vy(list3)=abs(vy(list3)); %reflete as velocidades
    y(list3)=0;
end
list4=find(y>=Y); %identidade dos átomos que atingiram a parede esquerda;
if(length(list4)>0);
    vx(list4)=-abs(vx(list4)); %reflete as velocidades
    x(list4)=Y;
end
