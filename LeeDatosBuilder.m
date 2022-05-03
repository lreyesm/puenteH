ent_b=fopen('ENTRADA_STEP.DAT');
ent_b=fread(ent_b);
ent_b=readxpcfile(ent_b);

Entrada_b=ent_b.data (:,1);
TimeEn_b=ent_b.data (:,2);


sal_b=fopen('SALIDA_STEP.DAT');
sal_b=fread(sal_b);
%sal_b = uint8(sal_b');
sal_b=readxpcfile(sal_b);

figure (10); clf()
plot(ent_b.data(:,2),ent_b.data(:,1),'blue');
legend('Duty Cycle = azul');
xlabel('t')
ylabel('uk')


figure (11); clf()
plot(sal_b.data(:,2),sal_b.data(:,1),'red');
legend('rpm carga = rojo');
xlabel('t')
ylabel('yk')

data=iddata(sal_b.data(:,1),ent_b.data(:,1),T);


%Dibuja In y OUT en gráficos diferentes
figure (12); clf()
plot(data);
title('Datos In y OUT')


TimeSal_b=sal_b.data (:,2);
RPM=sal_b.data(:,1);
RPM_max= max(RPM);%Calcula el valor maximo obtenido
RPM_min= min(RPM);
RPM_max_man= RPM_max;%observando las gráficas el maximo es **

RPM_normalizada=RPM/RPM_max_man;

figure (13); clf()
plot(TimeSal_b,ent_b.data(:,1),'blue');
hold on;
plot(TimeSal_b,RPM_normalizada,'red');
legend('Duty Cycle = azul','rpm carga = rojo');
xlabel('t')
ylabel('yk/uk')


figure (14); clf()
plot(ent_b.data(:,1),sal_b.data(:,1), 'green');




