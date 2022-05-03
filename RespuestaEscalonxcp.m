function xcp = RespuestaEscalonxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'RespuestaEscalon';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.02;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'RespuestaEscalon_B.Abs';
    
xcp.signals(2).symbol =  'RespuestaEscalon_B.SalidaDigital';
    
xcp.signals(3).symbol =  'RespuestaEscalon_B.RPMcarga';
    
xcp.signals(4).symbol =  'RespuestaEscalon_B.RPMcargaNormalizada';
    
xcp.signals(5).symbol =  'RespuestaEscalon_B.RPMmotor';
    
xcp.signals(6).symbol =  'RespuestaEscalon_B.Memory';
    
xcp.signals(7).symbol =  'RespuestaEscalon_B.PuntosenH';
    
xcp.signals(8).symbol =  'RespuestaEscalon_B.Puntosporciclo';
    
xcp.signals(9).symbol =  'RespuestaEscalon_B.PCI6221ENC';
    
xcp.signals(10).symbol =  'RespuestaEscalon_B.Sum';
    
xcp.signals(11).symbol =  'RespuestaEscalon_B.Sum1';
    
xcp.signals(12).symbol =  'RespuestaEscalon_B.Compare';
    
xcp.signals(13).symbol =  'RespuestaEscalon_B.FromWs';
         
xcp.parameters(1).symbol = 'RespuestaEscalon_P.Frecdebasedetiempos_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&RespuestaEscalon_P.Frecdebasedetiempos_Value';     
         
xcp.parameters(2).symbol = 'RespuestaEscalon_P.FrecuenciaPWM_Value';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&RespuestaEscalon_P.FrecuenciaPWM_Value';     
         
xcp.parameters(3).symbol = 'RespuestaEscalon_P.RPMcarga_Gain';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&RespuestaEscalon_P.RPMcarga_Gain';     
         
xcp.parameters(4).symbol = 'RespuestaEscalon_P.RPMcargaNormalizada_Gain';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&RespuestaEscalon_P.RPMcargaNormalizada_Gain';     
         
xcp.parameters(5).symbol = 'RespuestaEscalon_P.Memory_InitialCondition';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&RespuestaEscalon_P.Memory_InitialCondition';     
         
xcp.parameters(6).symbol = 'RespuestaEscalon_P.PCI6221ENC_P1';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P1';     
         
xcp.parameters(7).symbol = 'RespuestaEscalon_P.PCI6221ENC_P2';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P2';     
         
xcp.parameters(8).symbol = 'RespuestaEscalon_P.PCI6221ENC_P3';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P3';     
         
xcp.parameters(9).symbol = 'RespuestaEscalon_P.PCI6221ENC_P4';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P4';     
         
xcp.parameters(10).symbol = 'RespuestaEscalon_P.PCI6221ENC_P5';
xcp.parameters(10).size   =  1;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P5';     
         
xcp.parameters(11).symbol = 'RespuestaEscalon_P.PCI6221ENC_P6';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P6';     
         
xcp.parameters(12).symbol = 'RespuestaEscalon_P.PCI6221ENC_P7';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P7';     
         
xcp.parameters(13).symbol = 'RespuestaEscalon_P.PCI6221ENC_P8';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P8';     
         
xcp.parameters(14).symbol = 'RespuestaEscalon_P.PCI6221ENC_P9';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P9';     
         
xcp.parameters(15).symbol = 'RespuestaEscalon_P.PCI6221ENC_P10';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&RespuestaEscalon_P.PCI6221ENC_P10';     
         
xcp.parameters(16).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P1';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P1';     
         
xcp.parameters(17).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P2';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P2';     
         
xcp.parameters(18).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P3';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P3';     
         
xcp.parameters(19).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P4';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P4';     
         
xcp.parameters(20).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P5';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P5';     
         
xcp.parameters(21).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P6';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P6';     
         
xcp.parameters(22).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P7';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P7';     
         
xcp.parameters(23).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P8';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P8';     
         
xcp.parameters(24).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P9';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P9';     
         
xcp.parameters(25).symbol = 'RespuestaEscalon_P.PCI6221PWMGenerate_P10';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&RespuestaEscalon_P.PCI6221PWMGenerate_P10';     
         
xcp.parameters(26).symbol = 'RespuestaEscalon_P.PCI6221DO_P1';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P1';     
         
xcp.parameters(27).symbol = 'RespuestaEscalon_P.PCI6221DO_P2';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P2';     
         
xcp.parameters(28).symbol = 'RespuestaEscalon_P.PCI6221DO_P3';
xcp.parameters(28).size   =  1;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P3';     
         
xcp.parameters(29).symbol = 'RespuestaEscalon_P.PCI6221DO_P4';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P4';     
         
xcp.parameters(30).symbol = 'RespuestaEscalon_P.PCI6221DO_P5';
xcp.parameters(30).size   =  1;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P5';     
         
xcp.parameters(31).symbol = 'RespuestaEscalon_P.PCI6221DO_P6';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P6';     
         
xcp.parameters(32).symbol = 'RespuestaEscalon_P.PCI6221DO_P7';
xcp.parameters(32).size   =  1;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&RespuestaEscalon_P.PCI6221DO_P7';     
         
xcp.parameters(33).symbol = 'RespuestaEscalon_P.Constant_Value';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&RespuestaEscalon_P.Constant_Value';     
         
xcp.parameters(34).symbol = 'RespuestaEscalon_P.T';
xcp.parameters(34).size   =  1;       
xcp.parameters(34).dtname = 'real_T'; 
xcp.parameters(35).baseaddr = '&RespuestaEscalon_P.T';     

function n = getNumParameters
n = 34;

function n = getNumSignals
n = 13;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

