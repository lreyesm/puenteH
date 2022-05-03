%se han hecho pruebas escalón y se ha obtenido la misma dinámica para los
%dos primeros tramos. T=0.19. Se ha estudiado el ancho de banda del
%sistema y se ha obtendo que es 0,8Hz.

clear;
T=0.1965;%constante de tiempo obtenida a partir de la respuesta escalon
ts_max=T/3;%eel número de muestras que se tendrán en T Debe ser mínimo 3
f_b_real=0.8;%ancho de banda obtenido
Tss=5*T;%tiempo de establecimiento. Comprobarlo experimentalmente
ts__fb=1/(2*f_b_real);%sabemos que fmax=fs/2 Esto nos da el ts que haria falta
%para consseguir la frecuencia que necesitamos. Hay que compararlo con
%ts_max, ya que el que eleijamos no puede superarlo.

%Jugar con S y con ts para decidir el registro nr
ts=0.05;%Elegir el ts
fs=1/ts;
m=T/ts;%número de muestras que se tendrán en T. Debe ser mínimo 3
w=Tss/ts;%numero de meustras que hacen falta par aestabilizarse
S=2;%diezmar la PRBS tomando una muestra de cada S
Tclk=S*ts;
nr_min=(1.1*Tss)/Tclk; %es el mínimo valor para nr

c=1;%número de ciclos
nr=9;%registros de PRBS. Hay que elegirlo. Maximo 20 pq sino, no funciona idinput
d1=((2^nr)-1)*c;%número de datos 

Estable_PRBS_filtrada=nr*Tclk; %el valor cte de PRBS mayor. Debe superar a Tss
w_2=Estable_PRBS_filtrada/ts;%muestras en el mayor de los estados
Estable_PRBS=nr*ts;%el valor cte de PRBS mayor

delta_f_fft=fs/d1;%resolucion de fft

f_b_teorico=2.8/(2*pi*Tclk);%ancho de banda teorico w_B=2.8/Tclk de la PRBS filtrada 


fs=1/ts;
frec_max_fft=fs/2;%frec maxima a obtener

f_valle_teorico=1/(S*ts);%los valles de la señal diezmada estan en 2pi/Tclock. Tclok=S*Ts

%rango de frecuencias
f_min=1/d1*Tclk;
f_max=f_b_teorico;

