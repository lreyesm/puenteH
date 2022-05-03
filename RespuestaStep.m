
%DAtos In y OUT

ent_b=fopen('E_0102_5.DAT');
ent_b=fread(ent_b);
ent_b=readxpcfile(ent_b);

u=ent_b.data (:,1);
Time_u=ent_b.data (:,2);
u_2020=u;


sal_b=fopen('S_0102_5.DAT');
sal_b=fread(sal_b);
sal_b=readxpcfile(sal_b);

ystep=sal_b.data (:,1);
Time_y=sal_b.data (:,2);
y_2020=ystep;

figure
plot(Time_u,u,'blue');
legend('Duty Cycle = azul');
hold on
plot(Time_y,ystep,'red');
legend('rpm carga = rojo');


%Eliminamos el offset
offset=off;
ts=T;
tstep=Time_y;

%ystep = detrend(ystep, 'constant');%elimina el offset
%u = detrend(u, 'constant');

%elimina hasta el segundo 3 pq necesita ese tiempo para estabilizarse
t_inicial=tstep(3);
eliminar=3/ts; %cuantas muestras hay que eliminar en 3 segundos
eliminar = round(eliminar);
[L_original,N] = size(u);
L_definitiva=L_original-eliminar+1;

%Quitar el offset
u=u-offset;
offset_salida=ystep(eliminar);%el valro de la salida en el segundo 3
ystep=ystep-offset_salida;


%Elimina el primer ciclo 
u_2=u(eliminar:L_original);
ystep_2=ystep(eliminar:L_original);
Time_2=tstep(eliminar:L_original);

%Dibuja In y OUT en mismo gráfico
figure
plot(Time_2,u_2,'blue');
hold on;
plot(Time_2,ystep_2,'red');
legend('Duty Cycle = azul','rpm carga = rojo');
title('Datos In y OUT')

data=iddata(ystep,u,ts);
data_buenos=data(eliminar:L_original);

%Dibuja In y OUT en gráficos diferentes
figure
plot(data_buenos);
title('Datos In y OUT')








