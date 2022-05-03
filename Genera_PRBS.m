%Ajsute de amplitud y offset de la señal 
Zona_muerta=0.5;%valor mínimo de la señal de entrada
Amplitud= 0.3/2;
Offset=Zona_muerta+Amplitud;

%Genera y grafica las PRBSs sin offset
puntos=d1/c;%puntos de un ciclo de PRBS
PRBS1=idinput([puntos,1,c], 'PRBS', [0,1],[-Amplitud, Amplitud]);
PRBS2_2=idinput([puntos,1,1], 'PRBS', [0,1/S],[-Amplitud, Amplitud]);%PAra más de un ciclo, Esto
%sólo funciona bien si puntos es multiplo de S. Como en general no lo va a
%ser, generamos la PRBS filtrada y la concatenamos.


PRBS2=PRBS2_2;
for i=1:c-1
PRBS2=cat(1,PRBS2, PRBS2_2);
end


figure (70);clf()
plot(PRBS1)
title('PRBS1 maxima longitud')
%hold on
%plot(PRBS11)

figure (71);clf()
plot(PRBS2)
title('PRBS2 filtrada')

%Para graficar la FFT de la señal.The complex magnitude squared of Y is 
%called the power, and a plot of power versus frequency is a "periodogram".
NFFT_1 = 2^nextpow2(d1); % Next power of 2 from length of y
Y_1 = fft(PRBS1,d1)/d1;
f_1 = fs/2*linspace(0,1,d1/2+1);
g_1=2*abs(Y_1(1:d1/2+1));


% Plot single-sided amplitude spectrum.
figure (72);clf()
plot(f_1,g_1,'bo'); 
title('Espectro de PRBS1 maxima longitud)')
xlabel('Frequency (Hz)')
ylabel('|Y(f)|')

%Para graficar la FFT de la señal diezmada PRBS2
NFFT = 2^nextpow2(d1); % Next power of 2 from length of y
Y = fft(PRBS2,d1)/d1;
f = fs/2*linspace(0,1,d1/2+1);%fs/2 es la máxima frecuencia a conseguir. 
%la máxima resolucion de frecuencia es 1/(N*ts)Crea un array cone sas
%caracteristicas
g=2*abs(Y(1:d1/2+1));



% Plot single-sided amplitude spectrum.
figure(73);clf()
plot(f,g); 
title('Espectro de PRBS2. La filtrada)')
xlabel('Frequency (Hz)')
ylabel('|Y(f)|')

%a partir de ahora trabajamos con la señal filtrada: PRBS2

%len=length(PRBS2);
t_muestras=d1*ts;
t=0:ts:t_muestras-ts;
t_ejec=t_muestras-ts;
t=t';



%añadimos el offset y la amplitud a la señal filtrada

PRBS_offset=PRBS2+Offset;
u=PRBS_offset;
figure(74);clf()
plot(t, u);
title('Señal de excitación con offset')
xlabel('t (seg)')
ylabel('DC')

%para sacar el vector de tiempo con añadido
%cuantos puntos son XX segundos
h=250;%muestras a añadir
segundos_anadir=h*ts;
t_anadir=[0:ts:segundos_anadir-ts]';%array de tiempo
valor=Offset;%u(1)
P_anadir=segundos_anadir/ts;



%añadimos XX segundos de valor constante al principio

for i=1:1:P_anadir
    data_anadir(i)=valor;
end
data_anadir=data_anadir';
Puntos_anadido=i;

figure(75);clf()
plot(t_anadir, data_anadir);
title('Señal de inicio')
xlabel('t (seg)')
ylabel('DC')


%todo junto

u_anadido=vertcat(data_anadir,u);
time_max_anadido=ts*(d1+P_anadir)-ts;
t_anadido=[0:ts:time_max_anadido]';%array de tiempo
%%t=t_anadido;

figure(76);clf()
plot(t_anadido, u_anadido);
title('Señal de excitación con offset y t añadido')
xlabel('t (seg)')
ylabel('DC')

P_anadido=length(u_anadido)-1;%PAra los scopes 
t_ejec_anadido=t_ejec+segundos_anadir+ts;
t=t';

P=d1-1;
D=1;%señal a pasar