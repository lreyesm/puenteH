/*
 * RespuestaEscalon.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "RespuestaEscalon".
 *
 * Model version              : 1.275
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue May  3 18:31:25 2022
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "RespuestaEscalon_capi.h"
#include "RespuestaEscalon.h"
#include "RespuestaEscalon_private.h"

/* Block signals (auto storage) */
B_RespuestaEscalon_T RespuestaEscalon_B;

/* Block states (auto storage) */
DW_RespuestaEscalon_T RespuestaEscalon_DW;

/* Real-time model */
RT_MODEL_RespuestaEscalon_T RespuestaEscalon_M_;
RT_MODEL_RespuestaEscalon_T *const RespuestaEscalon_M = &RespuestaEscalon_M_;

/* Model output function */
static void RespuestaEscalon_output(void)
{
  real_T B;

  /* Product: '<Root>/Puntos por ciclo' incorporates:
   *  Constant: '<Root>/Frec de base de tiempos'
   *  Constant: '<Root>/Frecuencia PWM'
   */
  RespuestaEscalon_B.Puntosporciclo =
    RespuestaEscalon_P.Frecdebasedetiempos_Value /
    RespuestaEscalon_P.FrecuenciaPWM_Value;

  /* FromWorkspace: '<S2>/FromWs' */
  {
    real_T *pDataValues = (real_T *) RespuestaEscalon_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) RespuestaEscalon_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = RespuestaEscalon_DW.FromWs_IWORK.PrevIndex;
    real_T t = RespuestaEscalon_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[5]) {
      currTimeIndex = 4;
    } else {
      if (t < pTimeValues[currTimeIndex]) {
        while (t < pTimeValues[currTimeIndex]) {
          currTimeIndex--;
        }
      } else {
        while (t >= pTimeValues[currTimeIndex + 1]) {
          currTimeIndex++;
        }
      }
    }

    RespuestaEscalon_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&RespuestaEscalon_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 6;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&RespuestaEscalon_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex
                + 1];
              pDataValues += 6;
            }
          }
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;

        {
          int_T elIdx;
          for (elIdx = 0; elIdx < 2; ++elIdx) {
            d1 = pDataValues[TimeIndex];
            d2 = pDataValues[TimeIndex + 1];
            (&RespuestaEscalon_B.FromWs[0])[elIdx] = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 6;
          }
        }
      }
    }
  }

  /* Abs: '<Root>/Abs' */
  RespuestaEscalon_B.Abs = fabs(RespuestaEscalon_B.FromWs[0]);

  /* Product: '<Root>/Puntos en H' */
  RespuestaEscalon_B.PuntosenH = RespuestaEscalon_B.Puntosporciclo *
    RespuestaEscalon_B.Abs;

  /* Sum: '<Root>/Sum1' */
  RespuestaEscalon_B.Sum1 = RespuestaEscalon_B.Puntosporciclo -
    RespuestaEscalon_B.PuntosenH;

  /* S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */

  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  RespuestaEscalon_B.Compare = (uint8_T)(RespuestaEscalon_B.FromWs[0] >
    RespuestaEscalon_P.Constant_Value);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  RespuestaEscalon_B.SalidaDigital = RespuestaEscalon_B.Compare;

  /* S-Function (donipcim): '<Root>/PCI-6221 DO' */

  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* S-Function (scblock): '<S3>/S-Function' */
  /* ok to acquire for <S3>/S-Function */
  RespuestaEscalon_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S4>/S-Function' */
  /* ok to acquire for <S4>/S-Function */
  RespuestaEscalon_DW.SFunction_IWORK_f.AcquireOK = 1;

  /* S-Function (scblock): '<S5>/S-Function' */
  /* ok to acquire for <S5>/S-Function */
  RespuestaEscalon_DW.SFunction_IWORK_g.AcquireOK = 1;

  /* Memory: '<Root>/Memory' */
  RespuestaEscalon_B.Memory = RespuestaEscalon_DW.Memory_PreviousInput;

  /* S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */

  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[2];
    sfcnOutputs(rts,1);
  }

  /* Sum: '<Root>/Sum' */
  RespuestaEscalon_B.Sum = RespuestaEscalon_B.PCI6221ENC -
    RespuestaEscalon_B.Memory;

  /* Gain: '<Root>/RPM motor' */
  B = 64.0 * RespuestaEscalon_P.T;
  B = 60.0 / B;
  RespuestaEscalon_B.RPMmotor = B * RespuestaEscalon_B.Sum;

  /* Gain: '<Root>/RPM carga' */
  RespuestaEscalon_B.RPMcarga = RespuestaEscalon_P.RPMcarga_Gain *
    RespuestaEscalon_B.RPMmotor;

  /* Gain: '<Root>/RPM carga  Normalizada' */
  RespuestaEscalon_B.RPMcargaNormalizada =
    RespuestaEscalon_P.RPMcargaNormalizada_Gain * RespuestaEscalon_B.RPMcarga;
}

/* Model update function */
static void RespuestaEscalon_update(void)
{
  /* Update for Memory: '<Root>/Memory' */
  RespuestaEscalon_DW.Memory_PreviousInput = RespuestaEscalon_B.PCI6221ENC;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++RespuestaEscalon_M->Timing.clockTick0)) {
    ++RespuestaEscalon_M->Timing.clockTickH0;
  }

  RespuestaEscalon_M->Timing.t[0] = RespuestaEscalon_M->Timing.clockTick0 *
    RespuestaEscalon_M->Timing.stepSize0 +
    RespuestaEscalon_M->Timing.clockTickH0 *
    RespuestaEscalon_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.02s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++RespuestaEscalon_M->Timing.clockTick1)) {
      ++RespuestaEscalon_M->Timing.clockTickH1;
    }

    RespuestaEscalon_M->Timing.t[1] = RespuestaEscalon_M->Timing.clockTick1 *
      RespuestaEscalon_M->Timing.stepSize1 +
      RespuestaEscalon_M->Timing.clockTickH1 *
      RespuestaEscalon_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void RespuestaEscalon_initialize(void)
{
  /* Start for FromWorkspace: '<S2>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.01, 1.01, 2.0, 2.0, 5.0 } ;

    static real_T pDataValues0[] = { 0.1, 0.1, 0.1, 0.1, 0.16, 0.16, -0.1, -0.1,
      -0.198, -0.198, -0.198, -0.198 } ;

    RespuestaEscalon_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    RespuestaEscalon_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    RespuestaEscalon_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (donipcim): '<Root>/PCI-6221 DO' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S3>/S-Function' */

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,3)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("RPM carga  Normalizada"));
        rl32eSetScope(1, 4, 11999);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        xpceFSScopeSet(1, "salida.dat", 0, 512, 0, 536870912);
        rl32eSetScope (1, 10, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("RPM carga  Normalizada"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1, &RespuestaEscalon_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (scblock): '<S4>/S-Function' */

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,3)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("PRBS/FromWs/s1"));
        rl32eSetScope(2, 4, 11999);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        xpceFSScopeSet(2, "entrada.dat", 0, 512, 0, 536870912);
        rl32eSetScope (2, 10, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("PRBS/FromWs/s1"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        xpceScopeAcqOK(2, &RespuestaEscalon_DW.SFunction_IWORK_f.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S5>/S-Function' */

  /* S-Function Block: <S5>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("PRBS/FromWs/s1"));
        rl32eAddSignal(3, rl32eGetSignalNo("RPM carga  Normalizada"));
        rl32eSetScope(3, 4, 11999);
        rl32eSetScope(3, 5, 1);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("PRBS/FromWs/s1"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3, &RespuestaEscalon_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  RespuestaEscalon_DW.Memory_PreviousInput =
    RespuestaEscalon_P.Memory_InitialCondition;
}

/* Model terminate function */
static void RespuestaEscalon_terminate(void)
{
  /* Terminate for S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (donipcim): '<Root>/PCI-6221 DO' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = RespuestaEscalon_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  RespuestaEscalon_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  RespuestaEscalon_update();
  UNUSED_PARAMETER(tid);
}

void MdlInitializeSizes(void)
{
}

void MdlInitializeSampleTimes(void)
{
}

void MdlInitialize(void)
{
}

void MdlStart(void)
{
  RespuestaEscalon_initialize();
}

void MdlTerminate(void)
{
  RespuestaEscalon_terminate();
}

/* Registration function */
RT_MODEL_RespuestaEscalon_T *RespuestaEscalon(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)RespuestaEscalon_M, 0,
                sizeof(RT_MODEL_RespuestaEscalon_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&RespuestaEscalon_M->solverInfo,
                          &RespuestaEscalon_M->Timing.simTimeStep);
    rtsiSetTPtr(&RespuestaEscalon_M->solverInfo, &rtmGetTPtr(RespuestaEscalon_M));
    rtsiSetStepSizePtr(&RespuestaEscalon_M->solverInfo,
                       &RespuestaEscalon_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&RespuestaEscalon_M->solverInfo, (&rtmGetErrorStatus
      (RespuestaEscalon_M)));
    rtsiSetRTModelPtr(&RespuestaEscalon_M->solverInfo, RespuestaEscalon_M);
  }

  rtsiSetSimTimeStep(&RespuestaEscalon_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&RespuestaEscalon_M->solverInfo,"FixedStepDiscrete");
  RespuestaEscalon_M->solverInfoPtr = (&RespuestaEscalon_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = RespuestaEscalon_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    RespuestaEscalon_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    RespuestaEscalon_M->Timing.sampleTimes =
      (&RespuestaEscalon_M->Timing.sampleTimesArray[0]);
    RespuestaEscalon_M->Timing.offsetTimes =
      (&RespuestaEscalon_M->Timing.offsetTimesArray[0]);

    /* task periods */
    RespuestaEscalon_M->Timing.sampleTimes[0] = (0.0);
    RespuestaEscalon_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    RespuestaEscalon_M->Timing.offsetTimes[0] = (0.0);
    RespuestaEscalon_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(RespuestaEscalon_M, &RespuestaEscalon_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = RespuestaEscalon_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    RespuestaEscalon_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(RespuestaEscalon_M, 240.0);
  RespuestaEscalon_M->Timing.stepSize0 = 0.02;
  RespuestaEscalon_M->Timing.stepSize1 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    RespuestaEscalon_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(RespuestaEscalon_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(RespuestaEscalon_M->rtwLogInfo, (NULL));
    rtliSetLogT(RespuestaEscalon_M->rtwLogInfo, "tout");
    rtliSetLogX(RespuestaEscalon_M->rtwLogInfo, "");
    rtliSetLogXFinal(RespuestaEscalon_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(RespuestaEscalon_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(RespuestaEscalon_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(RespuestaEscalon_M->rtwLogInfo, 12000);
    rtliSetLogDecimation(RespuestaEscalon_M->rtwLogInfo, 1);
    rtliSetLogY(RespuestaEscalon_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(RespuestaEscalon_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(RespuestaEscalon_M->rtwLogInfo, (NULL));
  }

  RespuestaEscalon_M->solverInfoPtr = (&RespuestaEscalon_M->solverInfo);
  RespuestaEscalon_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&RespuestaEscalon_M->solverInfo, 0.02);
  rtsiSetSolverMode(&RespuestaEscalon_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  RespuestaEscalon_M->blockIO = ((void *) &RespuestaEscalon_B);
  (void) memset(((void *) &RespuestaEscalon_B), 0,
                sizeof(B_RespuestaEscalon_T));

  {
    RespuestaEscalon_B.Puntosporciclo = 0.0;
    RespuestaEscalon_B.FromWs[0] = 0.0;
    RespuestaEscalon_B.FromWs[1] = 0.0;
    RespuestaEscalon_B.Abs = 0.0;
    RespuestaEscalon_B.PuntosenH = 0.0;
    RespuestaEscalon_B.Sum1 = 0.0;
    RespuestaEscalon_B.SalidaDigital = 0.0;
    RespuestaEscalon_B.Memory = 0.0;
    RespuestaEscalon_B.PCI6221ENC = 0.0;
    RespuestaEscalon_B.Sum = 0.0;
    RespuestaEscalon_B.RPMmotor = 0.0;
    RespuestaEscalon_B.RPMcarga = 0.0;
    RespuestaEscalon_B.RPMcargaNormalizada = 0.0;
  }

  /* parameters */
  RespuestaEscalon_M->defaultParam = ((real_T *)&RespuestaEscalon_P);

  /* states (dwork) */
  RespuestaEscalon_M->dwork = ((void *) &RespuestaEscalon_DW);
  (void) memset((void *)&RespuestaEscalon_DW, 0,
                sizeof(DW_RespuestaEscalon_T));
  RespuestaEscalon_DW.Memory_PreviousInput = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  RespuestaEscalon_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &RespuestaEscalon_M->NonInlinedSFcns.sfcnInfo;
    RespuestaEscalon_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(RespuestaEscalon_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &RespuestaEscalon_M->Sizes.numSampTimes);
    RespuestaEscalon_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (RespuestaEscalon_M)[0]);
    RespuestaEscalon_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (RespuestaEscalon_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,RespuestaEscalon_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(RespuestaEscalon_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(RespuestaEscalon_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (RespuestaEscalon_M));
    rtssSetStepSizePtr(sfcnInfo, &RespuestaEscalon_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(RespuestaEscalon_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &RespuestaEscalon_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &RespuestaEscalon_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &RespuestaEscalon_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &RespuestaEscalon_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &RespuestaEscalon_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &RespuestaEscalon_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &RespuestaEscalon_M->solverInfoPtr);
  }

  RespuestaEscalon_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&RespuestaEscalon_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  3*sizeof(SimStruct));
    RespuestaEscalon_M->childSfunctions =
      (&RespuestaEscalon_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    RespuestaEscalon_M->childSfunctions[0] =
      (&RespuestaEscalon_M->NonInlinedSFcns.childSFunctions[0]);
    RespuestaEscalon_M->childSfunctions[1] =
      (&RespuestaEscalon_M->NonInlinedSFcns.childSFunctions[1]);
    RespuestaEscalon_M->childSfunctions[2] =
      (&RespuestaEscalon_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: RespuestaEscalon/<Root>/PCI 6221 PWM Generate  (pwmoutnipcim) */
    {
      SimStruct *rts = RespuestaEscalon_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RespuestaEscalon_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RespuestaEscalon_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RespuestaEscalon_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RespuestaEscalon_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &RespuestaEscalon_B.PuntosenH);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &RespuestaEscalon_B.Sum1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 PWM Generate ");
      ssSetPath(rts, "RespuestaEscalon/PCI 6221 PWM Generate ");
      ssSetRTModel(rts,RespuestaEscalon_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       RespuestaEscalon_P.PCI6221PWMGenerate_P10_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RespuestaEscalon_DW.PCI6221PWMGenerate_IWORK[0]);
      ssSetPWork(rts, (void **) &RespuestaEscalon_DW.PCI6221PWMGenerate_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RespuestaEscalon_DW.PCI6221PWMGenerate_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &RespuestaEscalon_DW.PCI6221PWMGenerate_PWORK);
      }

      /* registration */
      pwmoutnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);
      _ssSetInputPortConnected(rts, 1, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
      ssSetInputPortBufferDstPort(rts, 1, -1);
    }

    /* Level2 S-Function Block: RespuestaEscalon/<Root>/PCI-6221 DO (donipcim) */
    {
      SimStruct *rts = RespuestaEscalon_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RespuestaEscalon_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RespuestaEscalon_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RespuestaEscalon_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RespuestaEscalon_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &RespuestaEscalon_B.SalidaDigital;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6221 DO");
      ssSetPath(rts, "RespuestaEscalon/PCI-6221 DO");
      ssSetRTModel(rts,RespuestaEscalon_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RespuestaEscalon_P.PCI6221DO_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RespuestaEscalon_P.PCI6221DO_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RespuestaEscalon_P.PCI6221DO_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RespuestaEscalon_P.PCI6221DO_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RespuestaEscalon_P.PCI6221DO_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RespuestaEscalon_P.PCI6221DO_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)RespuestaEscalon_P.PCI6221DO_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &RespuestaEscalon_DW.PCI6221DO_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RespuestaEscalon_DW.PCI6221DO_IWORK);
      }

      /* registration */
      donipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: RespuestaEscalon/<Root>/PCI 6221 ENC  (encnipcim) */
    {
      SimStruct *rts = RespuestaEscalon_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &RespuestaEscalon_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &RespuestaEscalon_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, RespuestaEscalon_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &RespuestaEscalon_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &RespuestaEscalon_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &RespuestaEscalon_B.PCI6221ENC));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 ENC ");
      ssSetPath(rts, "RespuestaEscalon/PCI 6221 ENC ");
      ssSetRTModel(rts,RespuestaEscalon_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)RespuestaEscalon_P.PCI6221ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &RespuestaEscalon_DW.PCI6221ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &RespuestaEscalon_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &RespuestaEscalon_DW.PCI6221ENC_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.02);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetOutputPortConnected(rts, 0, 1);
      _ssSetOutputPortBeingMerged(rts, 0, 0);

      /* Update the BufferDstPort flags for each input port */
    }
  }

  /* Initialize Sizes */
  RespuestaEscalon_M->Sizes.numContStates = (0);/* Number of continuous states */
  RespuestaEscalon_M->Sizes.numY = (0);/* Number of model outputs */
  RespuestaEscalon_M->Sizes.numU = (0);/* Number of model inputs */
  RespuestaEscalon_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  RespuestaEscalon_M->Sizes.numSampTimes = (2);/* Number of sample times */
  RespuestaEscalon_M->Sizes.numBlocks = (21);/* Number of blocks */
  RespuestaEscalon_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  RespuestaEscalon_M->Sizes.numBlockPrms = (88);/* Sum of parameter "widths" */
  return RespuestaEscalon_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
