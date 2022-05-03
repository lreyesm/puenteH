/*
 * DeteccionNoLinealidadesConBuilder.c
 *
 * Academic License - for use in teaching, academic research, and meeting
 * course requirements at degree granting institutions only.  Not for
 * government, commercial, or other organizational use.
 *
 * Code generation for model "DeteccionNoLinealidadesConBuilder".
 *
 * Model version              : 1.200
 * Simulink Coder version : 8.13 (R2017b) 24-Jul-2017
 * C source code generated on : Tue May  3 16:49:20 2022
 *
 * Target selection: slrt.tlc
 * Note: GRT includes extra infrastructure and instrumentation for prototyping
 * Embedded hardware selection: Generic->32-bit x86 compatible
 * Code generation objectives: Unspecified
 * Validation result: Not run
 */

#include "rt_logging_mmi.h"
#include "DeteccionNoLinealidadesConBuilder_capi.h"
#include "DeteccionNoLinealidadesConBuilder.h"
#include "DeteccionNoLinealidadesConBuilder_private.h"

/* Block signals (auto storage) */
B_DeteccionNoLinealidadesConBuilder_T DeteccionNoLinealidadesConBuilder_B;

/* Block states (auto storage) */
DW_DeteccionNoLinealidadesConBuilder_T DeteccionNoLinealidadesConBuilder_DW;

/* Real-time model */
RT_MODEL_DeteccionNoLinealidadesConBuilder_T
  DeteccionNoLinealidadesConBuilder_M_;
RT_MODEL_DeteccionNoLinealidadesConBuilder_T *const
  DeteccionNoLinealidadesConBuilder_M = &DeteccionNoLinealidadesConBuilder_M_;

/* Model output function */
static void DeteccionNoLinealidadesConBuilder_output(void)
{
  real_T B;

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S3>/S-Function' */
  /* ok to acquire for <S3>/S-Function */
  DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK_g.AcquireOK = 1;

  /* Product: '<Root>/Puntos por ciclo' incorporates:
   *  Constant: '<Root>/Frec de base de tiempos'
   *  Constant: '<Root>/Frecuencia PWM'
   */
  DeteccionNoLinealidadesConBuilder_B.Puntosporciclo =
    DeteccionNoLinealidadesConBuilder_P.Frecdebasedetiempos_Value /
    DeteccionNoLinealidadesConBuilder_P.FrecuenciaPWM_Value;

  /* FromWorkspace: '<S5>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *)
      DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex =
      DeteccionNoLinealidadesConBuilder_DW.FromWs_IWORK.PrevIndex;
    real_T t = DeteccionNoLinealidadesConBuilder_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[11]) {
      currTimeIndex = 10;
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

    DeteccionNoLinealidadesConBuilder_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          DeteccionNoLinealidadesConBuilder_B.FromWs = pDataValues[currTimeIndex];
        } else {
          DeteccionNoLinealidadesConBuilder_B.FromWs = pDataValues[currTimeIndex
            + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        DeteccionNoLinealidadesConBuilder_B.FromWs = (real_T) rtInterpolate(d1,
          d2, f1, f2);
        pDataValues += 12;
      }
    }
  }

  /* Abs: '<Root>/Abs' */
  DeteccionNoLinealidadesConBuilder_B.Abs = fabs
    (DeteccionNoLinealidadesConBuilder_B.FromWs);

  /* Product: '<Root>/Puntos en H' */
  DeteccionNoLinealidadesConBuilder_B.PuntosenH =
    DeteccionNoLinealidadesConBuilder_B.Puntosporciclo *
    DeteccionNoLinealidadesConBuilder_B.Abs;

  /* Sum: '<Root>/Sum1' */
  DeteccionNoLinealidadesConBuilder_B.Sum1 =
    DeteccionNoLinealidadesConBuilder_B.Puntosporciclo -
    DeteccionNoLinealidadesConBuilder_B.PuntosenH;

  /* S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */

  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  DeteccionNoLinealidadesConBuilder_B.Compare = (uint8_T)
    (DeteccionNoLinealidadesConBuilder_B.FromWs >
     DeteccionNoLinealidadesConBuilder_P.Constant_Value);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  DeteccionNoLinealidadesConBuilder_B.SalidaDigital =
    DeteccionNoLinealidadesConBuilder_B.Compare;

  /* S-Function (donipcim): '<Root>/PCI-6221 DO' */

  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* S-Function (scblock): '<S4>/S-Function' */
  /* ok to acquire for <S4>/S-Function */
  DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK_n.AcquireOK = 1;

  /* S-Function (scblock): '<S7>/S-Function' */
  /* ok to acquire for <S7>/S-Function */
  DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK_gh.AcquireOK = 1;

  /* Memory: '<Root>/Memory' */
  DeteccionNoLinealidadesConBuilder_B.Memory =
    DeteccionNoLinealidadesConBuilder_DW.Memory_PreviousInput;

  /* S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */

  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[2];
    sfcnOutputs(rts,1);
  }

  /* Sum: '<Root>/Sum' */
  DeteccionNoLinealidadesConBuilder_B.Sum =
    DeteccionNoLinealidadesConBuilder_B.PCI6221ENC -
    DeteccionNoLinealidadesConBuilder_B.Memory;

  /* Gain: '<Root>/RPM motor' */
  B = 64.0 * DeteccionNoLinealidadesConBuilder_P.T;
  B = 60.0 / B;
  DeteccionNoLinealidadesConBuilder_B.RPMmotor = B *
    DeteccionNoLinealidadesConBuilder_B.Sum;

  /* Gain: '<Root>/RPM carga' */
  DeteccionNoLinealidadesConBuilder_B.RPMcarga =
    DeteccionNoLinealidadesConBuilder_P.RPMcarga_Gain *
    DeteccionNoLinealidadesConBuilder_B.RPMmotor;

  /* FromWorkspace: '<S6>/FromWs' */
  {
    real_T *pDataValues = (real_T *)
      DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK_l.DataPtr;
    real_T *pTimeValues = (real_T *)
      DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK_l.TimePtr;
    int_T currTimeIndex =
      DeteccionNoLinealidadesConBuilder_DW.FromWs_IWORK_e.PrevIndex;
    real_T t = DeteccionNoLinealidadesConBuilder_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[8]) {
      currTimeIndex = 7;
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

    DeteccionNoLinealidadesConBuilder_DW.FromWs_IWORK_e.PrevIndex =
      currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          DeteccionNoLinealidadesConBuilder_B.FromWs_o =
            pDataValues[currTimeIndex];
        } else {
          DeteccionNoLinealidadesConBuilder_B.FromWs_o =
            pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        DeteccionNoLinealidadesConBuilder_B.FromWs_o = (real_T) rtInterpolate(d1,
          d2, f1, f2);
        pDataValues += 9;
      }
    }
  }
}

/* Model update function */
static void DeteccionNoLinealidadesConBuilder_update(void)
{
  /* Update for Memory: '<Root>/Memory' */
  DeteccionNoLinealidadesConBuilder_DW.Memory_PreviousInput =
    DeteccionNoLinealidadesConBuilder_B.PCI6221ENC;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DeteccionNoLinealidadesConBuilder_M->Timing.clockTick0)) {
    ++DeteccionNoLinealidadesConBuilder_M->Timing.clockTickH0;
  }

  DeteccionNoLinealidadesConBuilder_M->Timing.t[0] =
    DeteccionNoLinealidadesConBuilder_M->Timing.clockTick0 *
    DeteccionNoLinealidadesConBuilder_M->Timing.stepSize0 +
    DeteccionNoLinealidadesConBuilder_M->Timing.clockTickH0 *
    DeteccionNoLinealidadesConBuilder_M->Timing.stepSize0 * 4294967296.0;

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
    if (!(++DeteccionNoLinealidadesConBuilder_M->Timing.clockTick1)) {
      ++DeteccionNoLinealidadesConBuilder_M->Timing.clockTickH1;
    }

    DeteccionNoLinealidadesConBuilder_M->Timing.t[1] =
      DeteccionNoLinealidadesConBuilder_M->Timing.clockTick1 *
      DeteccionNoLinealidadesConBuilder_M->Timing.stepSize1 +
      DeteccionNoLinealidadesConBuilder_M->Timing.clockTickH1 *
      DeteccionNoLinealidadesConBuilder_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void DeteccionNoLinealidadesConBuilder_initialize(void)
{
  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,1)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("Signal Builder/FromWs"));
        rl32eSetScope(2, 4, 11999);
        rl32eSetScope(2, 5, 1);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("Signal Builder/FromWs"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        xpceScopeAcqOK(2,
                       &DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S3>/S-Function' */

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(6)) == 0) {
      if ((i = rl32eDefScope(6,3)) != 0) {
        printf("Error creating scope 6\n");
      } else {
        rl32eAddSignal(6, rl32eGetSignalNo("Signal Builder/FromWs"));
        rl32eSetScope(6, 4, 11999);
        rl32eSetScope(6, 5, 0);
        rl32eSetScope(6, 6, 1);
        rl32eSetScope(6, 0, 0);
        xpceFSScopeSet(6, "c:\\entrada.dat", 0, 512, 0, 536870912);
        rl32eSetScope (6, 10, 0);
        rl32eSetScope(6, 3, rl32eGetSignalNo("Signal Builder/FromWs"));
        rl32eSetScope(6, 1, 0.0);
        rl32eSetScope(6, 2, 0);
        rl32eSetScope(6, 9, 0);
        xpceScopeAcqOK(6,
                       &DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(6);
    }
  }

  /* Start for FromWorkspace: '<S5>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 50.0, 50.0, 100.0, 100.0, 120.0, 120.0,
      170.0, 170.0, 220.0, 220.0, 240.0 } ;

    static real_T pDataValues0[] = { 0.0, 1.0, 1.0, 0.0, 0.0, 0.0, 0.0, -1.0,
      -1.0, 0.0, 0.0, 0.0 } ;

    DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK.TimePtr = (void *)
      pTimeValues0;
    DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK.DataPtr = (void *)
      pDataValues0;
    DeteccionNoLinealidadesConBuilder_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (donipcim): '<Root>/PCI-6221 DO' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S4>/S-Function' */

  /* S-Function Block: <S4>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,3)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("RPM carga"));
        rl32eSetScope(1, 4, 11999);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        xpceFSScopeSet(1, "c:\\salida.dat", 0, 512, 0, 536870912);
        rl32eSetScope (1, 10, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("RPM carga"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1,
                       &DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK_n.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (scblock): '<S7>/S-Function' */

  /* S-Function Block: <S7>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("RPM carga"));
        rl32eSetScope(3, 4, 11999);
        rl32eSetScope(3, 5, 1);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("RPM carga"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3,
                       &DeteccionNoLinealidadesConBuilder_DW.SFunction_IWORK_gh.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for FromWorkspace: '<S6>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.55, 1.55, 3.5500000000000003,
      3.5500000000000003, 5.5500000000000007, 5.5500000000000007, 8.0, 20.0 } ;

    static real_T pDataValues0[] = { 0.30000000000000004, 0.30000000000000004,
      0.5, 0.5, 0.70000000000000007, 0.70000000000000007, 0.9, 0.9, 0.9 } ;

    DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK_l.TimePtr = (void *)
      pTimeValues0;
    DeteccionNoLinealidadesConBuilder_DW.FromWs_PWORK_l.DataPtr = (void *)
      pDataValues0;
    DeteccionNoLinealidadesConBuilder_DW.FromWs_IWORK_e.PrevIndex = 0;
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  DeteccionNoLinealidadesConBuilder_DW.Memory_PreviousInput =
    DeteccionNoLinealidadesConBuilder_P.Memory_InitialCondition;
}

/* Model terminate function */
static void DeteccionNoLinealidadesConBuilder_terminate(void)
{
  /* Terminate for S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (donipcim): '<Root>/PCI-6221 DO' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DeteccionNoLinealidadesConBuilder_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DeteccionNoLinealidadesConBuilder_update();
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
  DeteccionNoLinealidadesConBuilder_initialize();
}

void MdlTerminate(void)
{
  DeteccionNoLinealidadesConBuilder_terminate();
}

/* Registration function */
RT_MODEL_DeteccionNoLinealidadesConBuilder_T *DeteccionNoLinealidadesConBuilder
  (void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DeteccionNoLinealidadesConBuilder_M, 0,
                sizeof(RT_MODEL_DeteccionNoLinealidadesConBuilder_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                          &DeteccionNoLinealidadesConBuilder_M->Timing.simTimeStep);
    rtsiSetTPtr(&DeteccionNoLinealidadesConBuilder_M->solverInfo, &rtmGetTPtr
                (DeteccionNoLinealidadesConBuilder_M));
    rtsiSetStepSizePtr(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                       &DeteccionNoLinealidadesConBuilder_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                          (&rtmGetErrorStatus
      (DeteccionNoLinealidadesConBuilder_M)));
    rtsiSetRTModelPtr(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                      DeteccionNoLinealidadesConBuilder_M);
  }

  rtsiSetSimTimeStep(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                     MAJOR_TIME_STEP);
  rtsiSetSolverName(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                    "FixedStepDiscrete");
  DeteccionNoLinealidadesConBuilder_M->solverInfoPtr =
    (&DeteccionNoLinealidadesConBuilder_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap =
      DeteccionNoLinealidadesConBuilder_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DeteccionNoLinealidadesConBuilder_M->Timing.sampleTimeTaskIDPtr =
      (&mdlTsMap[0]);
    DeteccionNoLinealidadesConBuilder_M->Timing.sampleTimes =
      (&DeteccionNoLinealidadesConBuilder_M->Timing.sampleTimesArray[0]);
    DeteccionNoLinealidadesConBuilder_M->Timing.offsetTimes =
      (&DeteccionNoLinealidadesConBuilder_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DeteccionNoLinealidadesConBuilder_M->Timing.sampleTimes[0] = (0.0);
    DeteccionNoLinealidadesConBuilder_M->Timing.sampleTimes[1] = (0.02);

    /* task offsets */
    DeteccionNoLinealidadesConBuilder_M->Timing.offsetTimes[0] = (0.0);
    DeteccionNoLinealidadesConBuilder_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DeteccionNoLinealidadesConBuilder_M,
             &DeteccionNoLinealidadesConBuilder_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits =
      DeteccionNoLinealidadesConBuilder_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DeteccionNoLinealidadesConBuilder_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DeteccionNoLinealidadesConBuilder_M, 240.0);
  DeteccionNoLinealidadesConBuilder_M->Timing.stepSize0 = 0.02;
  DeteccionNoLinealidadesConBuilder_M->Timing.stepSize1 = 0.02;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    DeteccionNoLinealidadesConBuilder_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, (NULL));
    rtliSetLogT(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, "tout");
    rtliSetLogX(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, "");
    rtliSetLogXFinal(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo,
      "rt_");
    rtliSetLogFormat(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, 12000);
    rtliSetLogDecimation(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, 1);
    rtliSetLogY(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(DeteccionNoLinealidadesConBuilder_M->rtwLogInfo, (NULL));
  }

  DeteccionNoLinealidadesConBuilder_M->solverInfoPtr =
    (&DeteccionNoLinealidadesConBuilder_M->solverInfo);
  DeteccionNoLinealidadesConBuilder_M->Timing.stepSize = (0.02);
  rtsiSetFixedStepSize(&DeteccionNoLinealidadesConBuilder_M->solverInfo, 0.02);
  rtsiSetSolverMode(&DeteccionNoLinealidadesConBuilder_M->solverInfo,
                    SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DeteccionNoLinealidadesConBuilder_M->blockIO = ((void *)
    &DeteccionNoLinealidadesConBuilder_B);
  (void) memset(((void *) &DeteccionNoLinealidadesConBuilder_B), 0,
                sizeof(B_DeteccionNoLinealidadesConBuilder_T));

  {
    DeteccionNoLinealidadesConBuilder_B.Puntosporciclo = 0.0;
    DeteccionNoLinealidadesConBuilder_B.FromWs = 0.0;
    DeteccionNoLinealidadesConBuilder_B.Abs = 0.0;
    DeteccionNoLinealidadesConBuilder_B.PuntosenH = 0.0;
    DeteccionNoLinealidadesConBuilder_B.Sum1 = 0.0;
    DeteccionNoLinealidadesConBuilder_B.SalidaDigital = 0.0;
    DeteccionNoLinealidadesConBuilder_B.Memory = 0.0;
    DeteccionNoLinealidadesConBuilder_B.PCI6221ENC = 0.0;
    DeteccionNoLinealidadesConBuilder_B.Sum = 0.0;
    DeteccionNoLinealidadesConBuilder_B.RPMmotor = 0.0;
    DeteccionNoLinealidadesConBuilder_B.RPMcarga = 0.0;
    DeteccionNoLinealidadesConBuilder_B.FromWs_o = 0.0;
  }

  /* parameters */
  DeteccionNoLinealidadesConBuilder_M->defaultParam = ((real_T *)
    &DeteccionNoLinealidadesConBuilder_P);

  /* states (dwork) */
  DeteccionNoLinealidadesConBuilder_M->dwork = ((void *)
    &DeteccionNoLinealidadesConBuilder_DW);
  (void) memset((void *)&DeteccionNoLinealidadesConBuilder_DW, 0,
                sizeof(DW_DeteccionNoLinealidadesConBuilder_T));
  DeteccionNoLinealidadesConBuilder_DW.Memory_PreviousInput = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  DeteccionNoLinealidadesConBuilder_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo =
      &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.sfcnInfo;
    DeteccionNoLinealidadesConBuilder_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus
      (DeteccionNoLinealidadesConBuilder_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo,
      &DeteccionNoLinealidadesConBuilder_M->Sizes.numSampTimes);
    DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.taskTimePtrs[0] =
      &(rtmGetTPtr(DeteccionNoLinealidadesConBuilder_M)[0]);
    DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.taskTimePtrs[1] =
      &(rtmGetTPtr(DeteccionNoLinealidadesConBuilder_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,
                   DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(DeteccionNoLinealidadesConBuilder_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(DeteccionNoLinealidadesConBuilder_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (DeteccionNoLinealidadesConBuilder_M));
    rtssSetStepSizePtr(sfcnInfo,
                       &DeteccionNoLinealidadesConBuilder_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested
      (DeteccionNoLinealidadesConBuilder_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &DeteccionNoLinealidadesConBuilder_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo,
      &DeteccionNoLinealidadesConBuilder_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &DeteccionNoLinealidadesConBuilder_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo,
                         &DeteccionNoLinealidadesConBuilder_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &DeteccionNoLinealidadesConBuilder_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &DeteccionNoLinealidadesConBuilder_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo,
                         &DeteccionNoLinealidadesConBuilder_M->solverInfoPtr);
  }

  DeteccionNoLinealidadesConBuilder_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)
                  &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.childSFunctions
                  [0], 0,
                  3*sizeof(SimStruct));
    DeteccionNoLinealidadesConBuilder_M->childSfunctions =
      (&DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.childSFunctionPtrs
       [0]);
    DeteccionNoLinealidadesConBuilder_M->childSfunctions[0] =
      (&DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.childSFunctions[0]);
    DeteccionNoLinealidadesConBuilder_M->childSfunctions[1] =
      (&DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.childSFunctions[1]);
    DeteccionNoLinealidadesConBuilder_M->childSfunctions[2] =
      (&DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: DeteccionNoLinealidadesConBuilder/<Root>/PCI 6221 PWM Generate  (pwmoutnipcim) */
    {
      SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.blkInfo2
                         [0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.inputOutputPortInfo2
        [0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, DeteccionNoLinealidadesConBuilder_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods2
                           [0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods3
                           [0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods4
                           [0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.statesInfo2
                         [0]);
        ssSetPeriodicStatesInfo(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.periodicStatesInfo
          [0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0,
                               &DeteccionNoLinealidadesConBuilder_B.PuntosenH);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &DeteccionNoLinealidadesConBuilder_B.Sum1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 PWM Generate ");
      ssSetPath(rts, "DeteccionNoLinealidadesConBuilder/PCI 6221 PWM Generate ");
      ssSetRTModel(rts,DeteccionNoLinealidadesConBuilder_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221PWMGenerate_P10_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &DeteccionNoLinealidadesConBuilder_DW.PCI6221PWMGenerate_IWORK
                 [0]);
      ssSetPWork(rts, (void **)
                 &DeteccionNoLinealidadesConBuilder_DW.PCI6221PWMGenerate_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &DeteccionNoLinealidadesConBuilder_DW.PCI6221PWMGenerate_IWORK
                   [0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1,
                   &DeteccionNoLinealidadesConBuilder_DW.PCI6221PWMGenerate_PWORK);
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

    /* Level2 S-Function Block: DeteccionNoLinealidadesConBuilder/<Root>/PCI-6221 DO (donipcim) */
    {
      SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.blkInfo2
                         [1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.inputOutputPortInfo2
        [1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, DeteccionNoLinealidadesConBuilder_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods2
                           [1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods3
                           [1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods4
                           [1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.statesInfo2
                         [1]);
        ssSetPeriodicStatesInfo(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.periodicStatesInfo
          [1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.inputPortInfo
          [0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.inputPortUnits
          [0]);
        ssSetInputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &DeteccionNoLinealidadesConBuilder_B.SalidaDigital;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6221 DO");
      ssSetPath(rts, "DeteccionNoLinealidadesConBuilder/PCI-6221 DO");
      ssSetRTModel(rts,DeteccionNoLinealidadesConBuilder_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221DO_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *)
                 &DeteccionNoLinealidadesConBuilder_DW.PCI6221DO_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &DeteccionNoLinealidadesConBuilder_DW.PCI6221DO_IWORK);
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

    /* Level2 S-Function Block: DeteccionNoLinealidadesConBuilder/<Root>/PCI 6221 ENC  (encnipcim) */
    {
      SimStruct *rts = DeteccionNoLinealidadesConBuilder_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap =
        DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts,
                         &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.blkInfo2
                         [2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.inputOutputPortInfo2
        [2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, DeteccionNoLinealidadesConBuilder_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods2
                           [2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods3
                           [2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts,
                           &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.methods4
                           [2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts,
                         &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.statesInfo2
                         [2]);
        ssSetPeriodicStatesInfo(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.periodicStatesInfo
          [2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.outputPortInfo
          [0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.outputPortUnits
          [0]);
        ssSetOutputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &DeteccionNoLinealidadesConBuilder_B.PCI6221ENC));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 ENC ");
      ssSetPath(rts, "DeteccionNoLinealidadesConBuilder/PCI 6221 ENC ");
      ssSetRTModel(rts,DeteccionNoLinealidadesConBuilder_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       DeteccionNoLinealidadesConBuilder_P.PCI6221ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **)
                 &DeteccionNoLinealidadesConBuilder_DW.PCI6221ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DeteccionNoLinealidadesConBuilder_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0,
                   &DeteccionNoLinealidadesConBuilder_DW.PCI6221ENC_PWORK);
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
  DeteccionNoLinealidadesConBuilder_M->Sizes.numContStates = (0);/* Number of continuous states */
  DeteccionNoLinealidadesConBuilder_M->Sizes.numY = (0);/* Number of model outputs */
  DeteccionNoLinealidadesConBuilder_M->Sizes.numU = (0);/* Number of model inputs */
  DeteccionNoLinealidadesConBuilder_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DeteccionNoLinealidadesConBuilder_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DeteccionNoLinealidadesConBuilder_M->Sizes.numBlocks = (22);/* Number of blocks */
  DeteccionNoLinealidadesConBuilder_M->Sizes.numBlockIO = (13);/* Number of block outputs */
  DeteccionNoLinealidadesConBuilder_M->Sizes.numBlockPrms = (87);/* Sum of parameter "widths" */
  return DeteccionNoLinealidadesConBuilder_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
