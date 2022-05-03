function xcp = DeteccionNoLinealidadesConBuilderxcp

xcp.events     =  repmat(struct('id',{}, 'sampletime', {}, 'offset', {}), getNumEvents, 1 );
xcp.parameters =  repmat(struct('symbol',{}, 'size', {}, 'dtname', {}, 'baseaddr', {}), getNumParameters, 1 );
xcp.signals    =  repmat(struct('symbol',{}), getNumSignals, 1 );
xcp.models     =  cell(1,getNumModels);
    
xcp.models{1} = 'DeteccionNoLinealidadesConBuilder';
   
   
         
xcp.events(1).id         = 0;
xcp.events(1).sampletime = 0.02;
xcp.events(1).offset     = 0.0;
    
xcp.signals(1).symbol =  'DeteccionNoLinealidadesConBuilder_B.Abs';
    
xcp.signals(2).symbol =  'DeteccionNoLinealidadesConBuilder_B.SalidaDigital';
    
xcp.signals(3).symbol =  'DeteccionNoLinealidadesConBuilder_B.RPMcarga';
    
xcp.signals(4).symbol =  'DeteccionNoLinealidadesConBuilder_B.RPMmotor';
    
xcp.signals(5).symbol =  'DeteccionNoLinealidadesConBuilder_B.Memory';
    
xcp.signals(6).symbol =  'DeteccionNoLinealidadesConBuilder_B.PuntosenH';
    
xcp.signals(7).symbol =  'DeteccionNoLinealidadesConBuilder_B.Puntosporciclo';
    
xcp.signals(8).symbol =  'DeteccionNoLinealidadesConBuilder_B.PCI6221ENC';
    
xcp.signals(9).symbol =  'DeteccionNoLinealidadesConBuilder_B.Sum';
    
xcp.signals(10).symbol =  'DeteccionNoLinealidadesConBuilder_B.Sum1';
    
xcp.signals(11).symbol =  'DeteccionNoLinealidadesConBuilder_B.Compare';
    
xcp.signals(12).symbol =  'DeteccionNoLinealidadesConBuilder_B.FromWs';
    
xcp.signals(13).symbol =  'DeteccionNoLinealidadesConBuilder_B.FromWs_o';
         
xcp.parameters(1).symbol = 'DeteccionNoLinealidadesConBuilder_P.Frecdebasedetiempos_Value';
xcp.parameters(1).size   =  1;       
xcp.parameters(1).dtname = 'real_T'; 
xcp.parameters(2).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.Frecdebasedetiempos_Value';     
         
xcp.parameters(2).symbol = 'DeteccionNoLinealidadesConBuilder_P.FrecuenciaPWM_Value';
xcp.parameters(2).size   =  1;       
xcp.parameters(2).dtname = 'real_T'; 
xcp.parameters(3).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.FrecuenciaPWM_Value';     
         
xcp.parameters(3).symbol = 'DeteccionNoLinealidadesConBuilder_P.RPMcarga_Gain';
xcp.parameters(3).size   =  1;       
xcp.parameters(3).dtname = 'real_T'; 
xcp.parameters(4).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.RPMcarga_Gain';     
         
xcp.parameters(4).symbol = 'DeteccionNoLinealidadesConBuilder_P.Memory_InitialCondition';
xcp.parameters(4).size   =  1;       
xcp.parameters(4).dtname = 'real_T'; 
xcp.parameters(5).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.Memory_InitialCondition';     
         
xcp.parameters(5).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P1';
xcp.parameters(5).size   =  1;       
xcp.parameters(5).dtname = 'real_T'; 
xcp.parameters(6).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P1';     
         
xcp.parameters(6).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P2';
xcp.parameters(6).size   =  1;       
xcp.parameters(6).dtname = 'real_T'; 
xcp.parameters(7).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P2';     
         
xcp.parameters(7).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P3';
xcp.parameters(7).size   =  1;       
xcp.parameters(7).dtname = 'real_T'; 
xcp.parameters(8).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P3';     
         
xcp.parameters(8).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P4';
xcp.parameters(8).size   =  1;       
xcp.parameters(8).dtname = 'real_T'; 
xcp.parameters(9).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P4';     
         
xcp.parameters(9).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P5';
xcp.parameters(9).size   =  1;       
xcp.parameters(9).dtname = 'real_T'; 
xcp.parameters(10).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P5';     
         
xcp.parameters(10).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P6';
xcp.parameters(10).size   =  1;       
xcp.parameters(10).dtname = 'real_T'; 
xcp.parameters(11).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P6';     
         
xcp.parameters(11).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P7';
xcp.parameters(11).size   =  1;       
xcp.parameters(11).dtname = 'real_T'; 
xcp.parameters(12).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P7';     
         
xcp.parameters(12).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P8';
xcp.parameters(12).size   =  1;       
xcp.parameters(12).dtname = 'real_T'; 
xcp.parameters(13).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P8';     
         
xcp.parameters(13).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P9';
xcp.parameters(13).size   =  1;       
xcp.parameters(13).dtname = 'real_T'; 
xcp.parameters(14).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P9';     
         
xcp.parameters(14).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P10';
xcp.parameters(14).size   =  1;       
xcp.parameters(14).dtname = 'real_T'; 
xcp.parameters(15).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P10';     
         
xcp.parameters(15).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P1';
xcp.parameters(15).size   =  1;       
xcp.parameters(15).dtname = 'real_T'; 
xcp.parameters(16).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P1';     
         
xcp.parameters(16).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P2';
xcp.parameters(16).size   =  1;       
xcp.parameters(16).dtname = 'real_T'; 
xcp.parameters(17).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P2';     
         
xcp.parameters(17).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P3';
xcp.parameters(17).size   =  1;       
xcp.parameters(17).dtname = 'real_T'; 
xcp.parameters(18).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P3';     
         
xcp.parameters(18).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P4';
xcp.parameters(18).size   =  1;       
xcp.parameters(18).dtname = 'real_T'; 
xcp.parameters(19).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P4';     
         
xcp.parameters(19).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P5';
xcp.parameters(19).size   =  1;       
xcp.parameters(19).dtname = 'real_T'; 
xcp.parameters(20).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P5';     
         
xcp.parameters(20).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P6';
xcp.parameters(20).size   =  1;       
xcp.parameters(20).dtname = 'real_T'; 
xcp.parameters(21).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P6';     
         
xcp.parameters(21).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P7';
xcp.parameters(21).size   =  1;       
xcp.parameters(21).dtname = 'real_T'; 
xcp.parameters(22).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P7';     
         
xcp.parameters(22).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P8';
xcp.parameters(22).size   =  1;       
xcp.parameters(22).dtname = 'real_T'; 
xcp.parameters(23).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P8';     
         
xcp.parameters(23).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P9';
xcp.parameters(23).size   =  1;       
xcp.parameters(23).dtname = 'real_T'; 
xcp.parameters(24).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P9';     
         
xcp.parameters(24).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P10';
xcp.parameters(24).size   =  1;       
xcp.parameters(24).dtname = 'real_T'; 
xcp.parameters(25).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P10';     
         
xcp.parameters(25).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P1';
xcp.parameters(25).size   =  1;       
xcp.parameters(25).dtname = 'real_T'; 
xcp.parameters(26).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P1';     
         
xcp.parameters(26).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P2';
xcp.parameters(26).size   =  1;       
xcp.parameters(26).dtname = 'real_T'; 
xcp.parameters(27).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P2';     
         
xcp.parameters(27).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P3';
xcp.parameters(27).size   =  1;       
xcp.parameters(27).dtname = 'real_T'; 
xcp.parameters(28).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P3';     
         
xcp.parameters(28).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P4';
xcp.parameters(28).size   =  1;       
xcp.parameters(28).dtname = 'real_T'; 
xcp.parameters(29).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P4';     
         
xcp.parameters(29).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P5';
xcp.parameters(29).size   =  1;       
xcp.parameters(29).dtname = 'real_T'; 
xcp.parameters(30).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P5';     
         
xcp.parameters(30).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P6';
xcp.parameters(30).size   =  1;       
xcp.parameters(30).dtname = 'real_T'; 
xcp.parameters(31).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P6';     
         
xcp.parameters(31).symbol = 'DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P7';
xcp.parameters(31).size   =  1;       
xcp.parameters(31).dtname = 'real_T'; 
xcp.parameters(32).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P7';     
         
xcp.parameters(32).symbol = 'DeteccionNoLinealidadesConBuilder_P.Constant_Value';
xcp.parameters(32).size   =  1;       
xcp.parameters(32).dtname = 'real_T'; 
xcp.parameters(33).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.Constant_Value';     
         
xcp.parameters(33).symbol = 'DeteccionNoLinealidadesConBuilder_P.T';
xcp.parameters(33).size   =  1;       
xcp.parameters(33).dtname = 'real_T'; 
xcp.parameters(34).baseaddr = '&DeteccionNoLinealidadesConBuilder_P.T';     

function n = getNumParameters
n = 33;

function n = getNumSignals
n = 13;

function n = getNumEvents
n = 1;

function n = getNumModels
n = 1;

