/*
 * DAtosInOut_PRBS_capi.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DAtosInOut_PRBS".
 *
 * Model version              : 1.270
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue May  3 15:54:01 2022
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rtw_capi.h"
#ifdef HOST_CAPI_BUILD
#include "DAtosInOut_PRBS_capi_host.h"
#define sizeof(s)                      ((size_t)(0xFFFF))
#undef rt_offsetof
#define rt_offsetof(s,el)              ((uint16_T)(0xFFFF))
#define TARGET_CONST
#define TARGET_STRING(s)               (s)
#else                                  /* HOST_CAPI_BUILD */
#include "builtin_typeid_types.h"
#include "DAtosInOut_PRBS.h"
#include "DAtosInOut_PRBS_capi.h"
#include "DAtosInOut_PRBS_private.h"
#ifdef LIGHT_WEIGHT_CAPI
#define TARGET_CONST
#define TARGET_STRING(s)               (NULL)
#else
#define TARGET_CONST                   const
#define TARGET_STRING(s)               (s)
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* Block output signal information */
static const rtwCAPI_Signals rtBlockSignals[] = {
  /* addrMapIndex, sysNum, blockPath,
   * signalName, portNumber, dataTypeIndex, dimIndex, fxpIndex, sTimeIndex
   */
  { 0, 0, TARGET_STRING("Abs"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 1, 0, TARGET_STRING("Data Type Conversion"),
    TARGET_STRING("Salida Digital"), 0, 0, 0, 0, 0 },

  { 2, 0, TARGET_STRING("PRBS"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 3, 0, TARGET_STRING("RPM carga"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 4, 0, TARGET_STRING("RPM carga  Normalizada"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 5, 0, TARGET_STRING("RPM motor"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 6, 0, TARGET_STRING("Memory"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 7, 0, TARGET_STRING("Puntos en H"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 8, 0, TARGET_STRING("Puntos por ciclo"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 9, 0, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 10, 0, TARGET_STRING("Sum"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 11, 0, TARGET_STRING("Sum1"),
    TARGET_STRING(""), 0, 0, 0, 0, 0 },

  { 12, 0, TARGET_STRING("Compare To Zero/Compare"),
    TARGET_STRING(""), 0, 1, 0, 0, 0 },

  { 13, 0, TARGET_STRING("TRayectoria/FromWs"),
    TARGET_STRING(""), 0, 0, 1, 0, 1 },

  { 14, 0, TARGET_STRING("Validacion/FromWs"),
    TARGET_STRING(""), 0, 0, 1, 0, 1 },

  {
    0, 0, (NULL), (NULL), 0, 0, 0, 0, 0
  }
};

static const rtwCAPI_BlockParameters rtBlockParameters[] = {
  /* addrMapIndex, blockPath,
   * paramName, dataTypeIndex, dimIndex, fixPtIdx
   */
  { 15, TARGET_STRING("Frec de base de tiempos"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 16, TARGET_STRING("Frecuencia PWM"),
    TARGET_STRING("Value"), 0, 0, 0 },

  { 17, TARGET_STRING("RPM carga"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 18, TARGET_STRING("RPM carga  Normalizada"),
    TARGET_STRING("Gain"), 0, 0, 0 },

  { 19, TARGET_STRING("Memory"),
    TARGET_STRING("InitialCondition"), 0, 0, 0 },

  { 20, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 21, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 22, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 23, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 24, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 25, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 26, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 27, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 28, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 29, TARGET_STRING("PCI 6221 ENC "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 30, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 31, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 32, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 33, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 34, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 35, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 36, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 37, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P8"), 0, 0, 0 },

  { 38, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P9"), 0, 0, 0 },

  { 39, TARGET_STRING("PCI 6221 PWM Generate "),
    TARGET_STRING("P10"), 0, 0, 0 },

  { 40, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P1"), 0, 0, 0 },

  { 41, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P2"), 0, 0, 0 },

  { 42, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P3"), 0, 0, 0 },

  { 43, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P4"), 0, 0, 0 },

  { 44, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P5"), 0, 0, 0 },

  { 45, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P6"), 0, 0, 0 },

  { 46, TARGET_STRING("PCI-6221 DO"),
    TARGET_STRING("P7"), 0, 0, 0 },

  { 47, TARGET_STRING("Compare To Zero/Constant"),
    TARGET_STRING("Value"), 0, 0, 0 },

  {
    0, (NULL), (NULL), 0, 0, 0
  }
};

/* Tunable variable parameters */
static const rtwCAPI_ModelParameters rtModelParameters[] = {
  /* addrMapIndex, varName, dataTypeIndex, dimIndex, fixPtIndex */
  { 48, TARGET_STRING("ts"), 0, 0, 0 },

  { 0, (NULL), 0, 0, 0 }
};

#ifndef HOST_CAPI_BUILD

/* Declare Data Addresses statically */
static void* rtDataAddrMap[] = {
  &DAtosInOut_PRBS_B.Abs,              /* 0: Signal */
  &DAtosInOut_PRBS_B.SalidaDigital,    /* 1: Signal */
  &DAtosInOut_PRBS_B.PRBS,             /* 2: Signal */
  &DAtosInOut_PRBS_B.RPMcarga,         /* 3: Signal */
  &DAtosInOut_PRBS_B.RPMcargaNormalizada,/* 4: Signal */
  &DAtosInOut_PRBS_B.RPMmotor,         /* 5: Signal */
  &DAtosInOut_PRBS_B.Memory,           /* 6: Signal */
  &DAtosInOut_PRBS_B.PuntosenH,        /* 7: Signal */
  &DAtosInOut_PRBS_B.Puntosporciclo,   /* 8: Signal */
  &DAtosInOut_PRBS_B.PCI6221ENC,       /* 9: Signal */
  &DAtosInOut_PRBS_B.Sum,              /* 10: Signal */
  &DAtosInOut_PRBS_B.Sum1,             /* 11: Signal */
  &DAtosInOut_PRBS_B.Compare,          /* 12: Signal */
  &DAtosInOut_PRBS_B.FromWs[0],        /* 13: Signal */
  &DAtosInOut_PRBS_B.FromWs_l[0],      /* 14: Signal */
  &DAtosInOut_PRBS_P.Frecdebasedetiempos_Value,/* 15: Block Parameter */
  &DAtosInOut_PRBS_P.FrecuenciaPWM_Value,/* 16: Block Parameter */
  &DAtosInOut_PRBS_P.RPMcarga_Gain,    /* 17: Block Parameter */
  &DAtosInOut_PRBS_P.RPMcargaNormalizada_Gain,/* 18: Block Parameter */
  &DAtosInOut_PRBS_P.Memory_InitialCondition,/* 19: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P1,    /* 20: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P2,    /* 21: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P3,    /* 22: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P4,    /* 23: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P5,    /* 24: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P6,    /* 25: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P7,    /* 26: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P8,    /* 27: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P9,    /* 28: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221ENC_P10,   /* 29: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P1,/* 30: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P2,/* 31: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P3,/* 32: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P4,/* 33: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P5,/* 34: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P6,/* 35: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P7,/* 36: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P8,/* 37: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P9,/* 38: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221PWMGenerate_P10,/* 39: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P1,     /* 40: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P2,     /* 41: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P3,     /* 42: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P4,     /* 43: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P5,     /* 44: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P6,     /* 45: Block Parameter */
  &DAtosInOut_PRBS_P.PCI6221DO_P7,     /* 46: Block Parameter */
  &DAtosInOut_PRBS_P.Constant_Value,   /* 47: Block Parameter */
  &DAtosInOut_PRBS_P.ts,               /* 48: Model Parameter */
};

/* Declare Data Run-Time Dimension Buffer Addresses statically */
static int32_T* rtVarDimsAddrMap[] = {
  (NULL)
};

#endif

/* Data Type Map - use dataTypeMapIndex to access this structure */
static TARGET_CONST rtwCAPI_DataTypeMap rtDataTypeMap[] = {
  /* cName, mwName, numElements, elemMapIndex, dataSize, slDataId, *
   * isComplex, isPointer */
  { "double", "real_T", 0, 0, sizeof(real_T), SS_DOUBLE, 0, 0 },

  { "unsigned char", "uint8_T", 0, 0, sizeof(uint8_T), SS_UINT8, 0, 0 }
};

#ifdef HOST_CAPI_BUILD
#undef sizeof
#endif

/* Structure Element Map - use elemMapIndex to access this structure */
static TARGET_CONST rtwCAPI_ElementMap rtElementMap[] = {
  /* elementName, elementOffset, dataTypeIndex, dimIndex, fxpIndex */
  { (NULL), 0, 0, 0, 0 },
};

/* Dimension Map - use dimensionMapIndex to access elements of ths structure*/
static const rtwCAPI_DimensionMap rtDimensionMap[] = {
  /* dataOrientation, dimArrayIndex, numDims, vardimsIndex */
  { rtwCAPI_SCALAR, 0, 2, 0 },

  { rtwCAPI_VECTOR, 2, 2, 0 }
};

/* Dimension Array- use dimArrayIndex to access elements of this array */
static const uint_T rtDimensionArray[] = {
  1,                                   /* 0 */
  1,                                   /* 1 */
  2,                                   /* 2 */
  1                                    /* 3 */
};

/* C-API stores floating point values in an array. The elements of this  *
 * are unique. This ensures that values which are shared across the model*
 * are stored in the most efficient way. These values are referenced by  *
 *           - rtwCAPI_FixPtMap.fracSlopePtr,                            *
 *           - rtwCAPI_FixPtMap.biasPtr,                                 *
 *           - rtwCAPI_SampleTimeMap.samplePeriodPtr,                    *
 *           - rtwCAPI_SampleTimeMap.sampleOffsetPtr                     */
static const real_T rtcapiStoredFloats[] = {
  0.05, 0.0
};

/* Fixed Point Map */
static const rtwCAPI_FixPtMap rtFixPtMap[] = {
  /* fracSlopePtr, biasPtr, scaleType, wordLength, exponent, isSigned */
  { (NULL), (NULL), rtwCAPI_FIX_RESERVED, 0, 0, 0 },
};

/* Sample Time Map - use sTimeIndex to access elements of ths structure */
static const rtwCAPI_SampleTimeMap rtSampleTimeMap[] = {
  /* samplePeriodPtr, sampleOffsetPtr, tid, samplingMode */
  { (const void *) &rtcapiStoredFloats[0], (const void *) &rtcapiStoredFloats[1],
    1, 0 },

  { (const void *) &rtcapiStoredFloats[1], (const void *) &rtcapiStoredFloats[1],
    0, 0 }
};

static rtwCAPI_ModelMappingStaticInfo mmiStatic = {
  /* Signals:{signals, numSignals,
   *           rootInputs, numRootInputs,
   *           rootOutputs, numRootOutputs},
   * Params: {blockParameters, numBlockParameters,
   *          modelParameters, numModelParameters},
   * States: {states, numStates},
   * Maps:   {dataTypeMap, dimensionMap, fixPtMap,
   *          elementMap, sampleTimeMap, dimensionArray},
   * TargetType: targetType
   */
  { rtBlockSignals, 15,
    (NULL), 0,
    (NULL), 0 },

  { rtBlockParameters, 33,
    rtModelParameters, 1 },

  { (NULL), 0 },

  { rtDataTypeMap, rtDimensionMap, rtFixPtMap,
    rtElementMap, rtSampleTimeMap, rtDimensionArray },
  "float",

  { 181994762U,
    2487765351U,
    3962957652U,
    1049619277U },
  (NULL), 0,
  0
};

/* Function to get C API Model Mapping Static Info */
const rtwCAPI_ModelMappingStaticInfo*
  DAtosInOut_PRBS_GetCAPIStaticMap(void)
{
  return &mmiStatic;
}

/* Cache pointers into DataMapInfo substructure of RTModel */
#ifndef HOST_CAPI_BUILD

void DAtosInOut_PRBS_InitializeDataMapInfo(void)
{
  /* Set C-API version */
  rtwCAPI_SetVersion(DAtosInOut_PRBS_M->DataMapInfo.mmi, 1);

  /* Cache static C-API data into the Real-time Model Data structure */
  rtwCAPI_SetStaticMap(DAtosInOut_PRBS_M->DataMapInfo.mmi, &mmiStatic);

  /* Cache static C-API logging data into the Real-time Model Data structure */
  rtwCAPI_SetLoggingStaticMap(DAtosInOut_PRBS_M->DataMapInfo.mmi, (NULL));

  /* Cache C-API Data Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetDataAddressMap(DAtosInOut_PRBS_M->DataMapInfo.mmi, rtDataAddrMap);

  /* Cache C-API Data Run-Time Dimension Buffer Addresses into the Real-Time Model Data structure */
  rtwCAPI_SetVarDimsAddressMap(DAtosInOut_PRBS_M->DataMapInfo.mmi,
    rtVarDimsAddrMap);

  /* Cache C-API rtp Address and size  into the Real-Time Model Data structure */
  DAtosInOut_PRBS_M->DataMapInfo.mmi.InstanceMap.rtpAddress = rtmGetDefaultParam
    (DAtosInOut_PRBS_M);
  DAtosInOut_PRBS_M->DataMapInfo.mmi.staticMap->rtpSize = sizeof
    (P_DAtosInOut_PRBS_T);

  /* Cache the instance C-API logging pointer */
  rtwCAPI_SetInstanceLoggingInfo(DAtosInOut_PRBS_M->DataMapInfo.mmi, (NULL));

  /* Set reference to submodels */
  rtwCAPI_SetChildMMIArray(DAtosInOut_PRBS_M->DataMapInfo.mmi, (NULL));
  rtwCAPI_SetChildMMIArrayLen(DAtosInOut_PRBS_M->DataMapInfo.mmi, 0);
}

#else                                  /* HOST_CAPI_BUILD */
#ifdef __cplusplus

extern "C" {

#endif

  void DAtosInOut_PRBS_host_InitializeDataMapInfo
    (DAtosInOut_PRBS_host_DataMapInfo_T *dataMap, const char *path)
  {
    /* Set C-API version */
    rtwCAPI_SetVersion(dataMap->mmi, 1);

    /* Cache static C-API data into the Real-time Model Data structure */
    rtwCAPI_SetStaticMap(dataMap->mmi, &mmiStatic);

    /* host data address map is NULL */
    rtwCAPI_SetDataAddressMap(dataMap->mmi, NULL);

    /* host vardims address map is NULL */
    rtwCAPI_SetVarDimsAddressMap(dataMap->mmi, NULL);

    /* Set Instance specific path */
    rtwCAPI_SetPath(dataMap->mmi, path);
    rtwCAPI_SetFullPath(dataMap->mmi, NULL);

    /* Set reference to submodels */
    rtwCAPI_SetChildMMIArray(dataMap->mmi, (NULL));
    rtwCAPI_SetChildMMIArrayLen(dataMap->mmi, 0);
  }

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */

/* EOF: DAtosInOut_PRBS_capi.c */
