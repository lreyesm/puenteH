/*
 * DAtosInOut_PRBS.c
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

#include "rt_logging_mmi.h"
#include "DAtosInOut_PRBS_capi.h"
#include "DAtosInOut_PRBS.h"
#include "DAtosInOut_PRBS_private.h"

/* Block signals (auto storage) */
B_DAtosInOut_PRBS_T DAtosInOut_PRBS_B;

/* Block states (auto storage) */
DW_DAtosInOut_PRBS_T DAtosInOut_PRBS_DW;

/* Real-time model */
RT_MODEL_DAtosInOut_PRBS_T DAtosInOut_PRBS_M_;
RT_MODEL_DAtosInOut_PRBS_T *const DAtosInOut_PRBS_M = &DAtosInOut_PRBS_M_;

/* Model output function */
static void DAtosInOut_PRBS_output(void)
{
  real_T B;

  /* Product: '<Root>/Puntos por ciclo' incorporates:
   *  Constant: '<Root>/Frec de base de tiempos'
   *  Constant: '<Root>/Frecuencia PWM'
   */
  DAtosInOut_PRBS_B.Puntosporciclo = DAtosInOut_PRBS_P.Frecdebasedetiempos_Value
    / DAtosInOut_PRBS_P.FrecuenciaPWM_Value;

  /* FromWorkspace: '<Root>/PRBS' */
  {
    real_T *pDataValues = (real_T *) DAtosInOut_PRBS_DW.PRBS_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) DAtosInOut_PRBS_DW.PRBS_PWORK.TimePtr;
    int_T currTimeIndex = DAtosInOut_PRBS_DW.PRBS_IWORK.PrevIndex;
    real_T t = DAtosInOut_PRBS_M->Timing.t[1];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[760]) {
      currTimeIndex = 759;
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

    DAtosInOut_PRBS_DW.PRBS_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          DAtosInOut_PRBS_B.PRBS = pDataValues[currTimeIndex];
        } else {
          DAtosInOut_PRBS_B.PRBS = pDataValues[currTimeIndex + 1];
        }
      } else {
        real_T f1 = (t2 - t) / (t2 - t1);
        real_T f2 = 1.0 - f1;
        real_T d1;
        real_T d2;
        int_T TimeIndex= currTimeIndex;
        d1 = pDataValues[TimeIndex];
        d2 = pDataValues[TimeIndex + 1];
        DAtosInOut_PRBS_B.PRBS = (real_T) rtInterpolate(d1, d2, f1, f2);
        pDataValues += 761;
      }
    }
  }

  /* Abs: '<Root>/Abs' */
  DAtosInOut_PRBS_B.Abs = fabs(DAtosInOut_PRBS_B.PRBS);

  /* Product: '<Root>/Puntos en H' */
  DAtosInOut_PRBS_B.PuntosenH = DAtosInOut_PRBS_B.Puntosporciclo *
    DAtosInOut_PRBS_B.Abs;

  /* Sum: '<Root>/Sum1' */
  DAtosInOut_PRBS_B.Sum1 = DAtosInOut_PRBS_B.Puntosporciclo -
    DAtosInOut_PRBS_B.PuntosenH;

  /* S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */

  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[0];
    sfcnOutputs(rts,1);
  }

  /* RelationalOperator: '<S1>/Compare' incorporates:
   *  Constant: '<S1>/Constant'
   */
  DAtosInOut_PRBS_B.Compare = (uint8_T)(DAtosInOut_PRBS_B.PRBS >
    DAtosInOut_PRBS_P.Constant_Value);

  /* DataTypeConversion: '<Root>/Data Type Conversion' */
  DAtosInOut_PRBS_B.SalidaDigital = DAtosInOut_PRBS_B.Compare;

  /* S-Function (donipcim): '<Root>/PCI-6221 DO' */

  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[1];
    sfcnOutputs(rts,1);
  }

  /* S-Function (scblock): '<S2>/S-Function' */
  /* ok to acquire for <S2>/S-Function */
  DAtosInOut_PRBS_DW.SFunction_IWORK.AcquireOK = 1;

  /* S-Function (scblock): '<S3>/S-Function' */
  /* ok to acquire for <S3>/S-Function */
  DAtosInOut_PRBS_DW.SFunction_IWORK_f.AcquireOK = 1;

  /* S-Function (scblock): '<S6>/S-Function' */
  /* ok to acquire for <S6>/S-Function */
  DAtosInOut_PRBS_DW.SFunction_IWORK_g.AcquireOK = 1;

  /* Memory: '<Root>/Memory' */
  DAtosInOut_PRBS_B.Memory = DAtosInOut_PRBS_DW.Memory_PreviousInput;

  /* S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */

  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[2];
    sfcnOutputs(rts,1);
  }

  /* Sum: '<Root>/Sum' */
  DAtosInOut_PRBS_B.Sum = DAtosInOut_PRBS_B.PCI6221ENC -
    DAtosInOut_PRBS_B.Memory;

  /* Gain: '<Root>/RPM motor' */
  B = 64.0 * DAtosInOut_PRBS_P.ts;
  B = 60.0 / B;
  DAtosInOut_PRBS_B.RPMmotor = B * DAtosInOut_PRBS_B.Sum;

  /* Gain: '<Root>/RPM carga' */
  DAtosInOut_PRBS_B.RPMcarga = DAtosInOut_PRBS_P.RPMcarga_Gain *
    DAtosInOut_PRBS_B.RPMmotor;

  /* Gain: '<Root>/RPM carga  Normalizada' */
  DAtosInOut_PRBS_B.RPMcargaNormalizada =
    DAtosInOut_PRBS_P.RPMcargaNormalizada_Gain * DAtosInOut_PRBS_B.RPMcarga;

  /* FromWorkspace: '<S4>/FromWs' */
  {
    real_T *pDataValues = (real_T *) DAtosInOut_PRBS_DW.FromWs_PWORK.DataPtr;
    real_T *pTimeValues = (real_T *) DAtosInOut_PRBS_DW.FromWs_PWORK.TimePtr;
    int_T currTimeIndex = DAtosInOut_PRBS_DW.FromWs_IWORK.PrevIndex;
    real_T t = DAtosInOut_PRBS_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[49]) {
      currTimeIndex = 48;
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

    DAtosInOut_PRBS_DW.FromWs_IWORK.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&DAtosInOut_PRBS_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex];
              pDataValues += 50;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&DAtosInOut_PRBS_B.FromWs[0])[elIdx] = pDataValues[currTimeIndex
                + 1];
              pDataValues += 50;
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
            (&DAtosInOut_PRBS_B.FromWs[0])[elIdx] = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 50;
          }
        }
      }
    }
  }

  /* FromWorkspace: '<S5>/FromWs' */
  {
    real_T *pDataValues = (real_T *) DAtosInOut_PRBS_DW.FromWs_PWORK_b.DataPtr;
    real_T *pTimeValues = (real_T *) DAtosInOut_PRBS_DW.FromWs_PWORK_b.TimePtr;
    int_T currTimeIndex = DAtosInOut_PRBS_DW.FromWs_IWORK_f.PrevIndex;
    real_T t = DAtosInOut_PRBS_M->Timing.t[0];

    /* Get index */
    if (t <= pTimeValues[0]) {
      currTimeIndex = 0;
    } else if (t >= pTimeValues[55]) {
      currTimeIndex = 54;
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

    DAtosInOut_PRBS_DW.FromWs_IWORK_f.PrevIndex = currTimeIndex;

    /* Post output */
    {
      real_T t1 = pTimeValues[currTimeIndex];
      real_T t2 = pTimeValues[currTimeIndex + 1];
      if (t1 == t2) {
        if (t < t1) {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&DAtosInOut_PRBS_B.FromWs_l[0])[elIdx] =
                pDataValues[currTimeIndex];
              pDataValues += 56;
            }
          }
        } else {
          {
            int_T elIdx;
            for (elIdx = 0; elIdx < 2; ++elIdx) {
              (&DAtosInOut_PRBS_B.FromWs_l[0])[elIdx] =
                pDataValues[currTimeIndex + 1];
              pDataValues += 56;
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
            (&DAtosInOut_PRBS_B.FromWs_l[0])[elIdx] = (real_T) rtInterpolate(d1,
              d2, f1, f2);
            pDataValues += 56;
          }
        }
      }
    }
  }
}

/* Model update function */
static void DAtosInOut_PRBS_update(void)
{
  /* Update for Memory: '<Root>/Memory' */
  DAtosInOut_PRBS_DW.Memory_PreviousInput = DAtosInOut_PRBS_B.PCI6221ENC;

  /* Update absolute time for base rate */
  /* The "clockTick0" counts the number of times the code of this task has
   * been executed. The absolute time is the multiplication of "clockTick0"
   * and "Timing.stepSize0". Size of "clockTick0" ensures timer will not
   * overflow during the application lifespan selected.
   * Timer of this task consists of two 32 bit unsigned integers.
   * The two integers represent the low bits Timing.clockTick0 and the high bits
   * Timing.clockTickH0. When the low bit overflows to 0, the high bits increment.
   */
  if (!(++DAtosInOut_PRBS_M->Timing.clockTick0)) {
    ++DAtosInOut_PRBS_M->Timing.clockTickH0;
  }

  DAtosInOut_PRBS_M->Timing.t[0] = DAtosInOut_PRBS_M->Timing.clockTick0 *
    DAtosInOut_PRBS_M->Timing.stepSize0 + DAtosInOut_PRBS_M->Timing.clockTickH0 *
    DAtosInOut_PRBS_M->Timing.stepSize0 * 4294967296.0;

  {
    /* Update absolute timer for sample time: [0.05s, 0.0s] */
    /* The "clockTick1" counts the number of times the code of this task has
     * been executed. The absolute time is the multiplication of "clockTick1"
     * and "Timing.stepSize1". Size of "clockTick1" ensures timer will not
     * overflow during the application lifespan selected.
     * Timer of this task consists of two 32 bit unsigned integers.
     * The two integers represent the low bits Timing.clockTick1 and the high bits
     * Timing.clockTickH1. When the low bit overflows to 0, the high bits increment.
     */
    if (!(++DAtosInOut_PRBS_M->Timing.clockTick1)) {
      ++DAtosInOut_PRBS_M->Timing.clockTickH1;
    }

    DAtosInOut_PRBS_M->Timing.t[1] = DAtosInOut_PRBS_M->Timing.clockTick1 *
      DAtosInOut_PRBS_M->Timing.stepSize1 +
      DAtosInOut_PRBS_M->Timing.clockTickH1 *
      DAtosInOut_PRBS_M->Timing.stepSize1 * 4294967296.0;
  }
}

/* Model initialize function */
static void DAtosInOut_PRBS_initialize(void)
{
  /* Start for FromWorkspace: '<Root>/PRBS' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.05, 0.1, 0.15000000000000002, 0.2,
      0.25, 0.30000000000000004, 0.35000000000000003, 0.4, 0.45, 0.5, 0.55,
      0.60000000000000009, 0.65, 0.70000000000000007, 0.75, 0.8,
      0.85000000000000009, 0.9, 0.95000000000000007, 1.0, 1.05, 1.1,
      1.1500000000000001, 1.2000000000000002, 1.25, 1.3, 1.35,
      1.4000000000000001, 1.4500000000000002, 1.5, 1.55, 1.6, 1.6500000000000001,
      1.7000000000000002, 1.75, 1.8, 1.85, 1.9000000000000001,
      1.9500000000000002, 2.0, 2.0500000000000003, 2.1, 2.15, 2.2, 2.25,
      2.3000000000000003, 2.35, 2.4000000000000004, 2.45, 2.5,
      2.5500000000000003, 2.6, 2.6500000000000004, 2.7, 2.75, 2.8000000000000003,
      2.85, 2.9000000000000004, 2.95, 3.0, 3.0500000000000003, 3.1,
      3.1500000000000004, 3.2, 3.25, 3.3000000000000003, 3.35,
      3.4000000000000004, 3.45, 3.5, 3.5500000000000003, 3.6, 3.6500000000000004,
      3.7, 3.75, 3.8000000000000003, 3.85, 3.9000000000000004, 3.95, 4.0, 4.05,
      4.1000000000000005, 4.15, 4.2, 4.25, 4.3, 4.3500000000000005, 4.4, 4.45,
      4.5, 4.55, 4.6000000000000005, 4.65, 4.7, 4.75, 4.8000000000000007,
      4.8500000000000005, 4.9, 4.95, 5.0, 5.0500000000000007, 5.1000000000000005,
      5.15, 5.2, 5.25, 5.3000000000000007, 5.3500000000000005, 5.4, 5.45, 5.5,
      5.5500000000000007, 5.6000000000000005, 5.65, 5.7, 5.75,
      5.8000000000000007, 5.8500000000000005, 5.9, 5.95, 6.0, 6.0500000000000007,
      6.1000000000000005, 6.15, 6.2, 6.25, 6.3000000000000007,
      6.3500000000000005, 6.4, 6.45, 6.5, 6.5500000000000007, 6.6000000000000005,
      6.65, 6.7, 6.75, 6.8000000000000007, 6.8500000000000005, 6.9, 6.95, 7.0,
      7.0500000000000007, 7.1000000000000005, 7.15, 7.2, 7.25,
      7.3000000000000007, 7.3500000000000005, 7.4, 7.45, 7.5, 7.5500000000000007,
      7.6000000000000005, 7.65, 7.7, 7.75, 7.8000000000000007,
      7.8500000000000005, 7.9, 7.95, 8.0, 8.05, 8.1, 8.15, 8.2000000000000011,
      8.25, 8.3, 8.35, 8.4, 8.4500000000000011, 8.5, 8.55, 8.6, 8.65,
      8.7000000000000011, 8.75, 8.8, 8.85, 8.9, 8.9500000000000011, 9.0, 9.05,
      9.1, 9.15, 9.2000000000000011, 9.25, 9.3, 9.35, 9.4, 9.4500000000000011,
      9.5, 9.55, 9.6000000000000014, 9.65, 9.7000000000000011, 9.75, 9.8,
      9.8500000000000014, 9.9, 9.9500000000000011, 10.0, 10.05,
      10.100000000000001, 10.15, 10.200000000000001, 10.25, 10.3,
      10.350000000000001, 10.4, 10.450000000000001, 10.5, 10.55,
      10.600000000000001, 10.65, 10.700000000000001, 10.75, 10.8,
      10.850000000000001, 10.9, 10.950000000000001, 11.0, 11.05,
      11.100000000000001, 11.15, 11.200000000000001, 11.25, 11.3,
      11.350000000000001, 11.4, 11.450000000000001, 11.5, 11.55,
      11.600000000000001, 11.65, 11.700000000000001, 11.75, 11.8,
      11.850000000000001, 11.9, 11.950000000000001, 12.0, 12.05,
      12.100000000000001, 12.15, 12.200000000000001, 12.25, 12.3,
      12.350000000000001, 12.4, 12.450000000000001, 12.5, 12.55,
      12.600000000000001, 12.65, 12.700000000000001, 12.75, 12.8,
      12.850000000000001, 12.9, 12.950000000000001, 13.0, 13.05,
      13.100000000000001, 13.15, 13.200000000000001, 13.25, 13.3,
      13.350000000000001, 13.4, 13.450000000000001, 13.5, 13.55,
      13.600000000000001, 13.65, 13.700000000000001, 13.75, 13.8,
      13.850000000000001, 13.9, 13.950000000000001, 14.0, 14.05,
      14.100000000000001, 14.15, 14.200000000000001, 14.25, 14.3,
      14.350000000000001, 14.4, 14.450000000000001, 14.5, 14.55,
      14.600000000000001, 14.65, 14.700000000000001, 14.75, 14.8,
      14.850000000000001, 14.9, 14.950000000000001, 15.0, 15.05,
      15.100000000000001, 15.15, 15.200000000000001, 15.25, 15.3,
      15.350000000000001, 15.4, 15.450000000000001, 15.5, 15.55,
      15.600000000000001, 15.65, 15.700000000000001, 15.75, 15.8,
      15.850000000000001, 15.9, 15.950000000000001, 16.0, 16.05, 16.1,
      16.150000000000002, 16.2, 16.25, 16.3, 16.35, 16.400000000000002, 16.45,
      16.5, 16.55, 16.6, 16.650000000000002, 16.7, 16.75, 16.8, 16.85,
      16.900000000000002, 16.95, 17.0, 17.05, 17.1, 17.150000000000002, 17.2,
      17.25, 17.3, 17.35, 17.400000000000002, 17.45, 17.5, 17.55, 17.6,
      17.650000000000002, 17.7, 17.75, 17.8, 17.85, 17.900000000000002, 17.95,
      18.0, 18.05, 18.1, 18.150000000000002, 18.2, 18.25, 18.3, 18.35,
      18.400000000000002, 18.45, 18.5, 18.55, 18.6, 18.650000000000002, 18.7,
      18.75, 18.8, 18.85, 18.900000000000002, 18.95, 19.000000000000004,
      19.050000000000008, 19.100000000000005, 19.150000000000006,
      19.200000000000006, 19.250000000000007, 19.300000000000008,
      19.350000000000005, 19.400000000000006, 19.450000000000006,
      19.500000000000007, 19.550000000000008, 19.600000000000005,
      19.650000000000006, 19.700000000000006, 19.750000000000007,
      19.800000000000008, 19.850000000000005, 19.900000000000006,
      19.950000000000006, 20.000000000000007, 20.050000000000008,
      20.100000000000005, 20.150000000000006, 20.200000000000006,
      20.250000000000007, 20.300000000000008, 20.350000000000005,
      20.400000000000006, 20.450000000000006, 20.500000000000007,
      20.550000000000008, 20.600000000000005, 20.650000000000006,
      20.700000000000006, 20.750000000000007, 20.800000000000008,
      20.850000000000005, 20.900000000000006, 20.950000000000006,
      21.000000000000007, 21.050000000000008, 21.100000000000005,
      21.150000000000006, 21.200000000000006, 21.250000000000007,
      21.300000000000008, 21.350000000000005, 21.400000000000006,
      21.450000000000006, 21.500000000000007, 21.550000000000008,
      21.600000000000005, 21.650000000000006, 21.700000000000006,
      21.750000000000007, 21.800000000000008, 21.850000000000005,
      21.900000000000006, 21.950000000000006, 22.000000000000007,
      22.050000000000004, 22.100000000000009, 22.150000000000006,
      22.200000000000006, 22.250000000000007, 22.300000000000004,
      22.350000000000009, 22.400000000000006, 22.450000000000006,
      22.500000000000007, 22.550000000000004, 22.600000000000009,
      22.650000000000006, 22.700000000000006, 22.750000000000007,
      22.800000000000004, 22.850000000000009, 22.900000000000006,
      22.950000000000006, 23.000000000000007, 23.050000000000004,
      23.100000000000009, 23.150000000000006, 23.200000000000006,
      23.250000000000007, 23.300000000000004, 23.350000000000009,
      23.400000000000006, 23.450000000000006, 23.500000000000007,
      23.550000000000004, 23.600000000000009, 23.650000000000006,
      23.700000000000006, 23.750000000000007, 23.800000000000004,
      23.850000000000009, 23.900000000000006, 23.950000000000006,
      24.000000000000007, 24.050000000000004, 24.100000000000009,
      24.150000000000006, 24.200000000000006, 24.250000000000007,
      24.300000000000004, 24.350000000000009, 24.400000000000006,
      24.450000000000006, 24.500000000000007, 24.550000000000004,
      24.600000000000009, 24.650000000000006, 24.700000000000006,
      24.750000000000007, 24.800000000000004, 24.850000000000009,
      24.900000000000006, 24.950000000000006, 25.000000000000007,
      25.050000000000004, 25.100000000000009, 25.150000000000006,
      25.200000000000006, 25.250000000000007, 25.300000000000004,
      25.350000000000009, 25.400000000000006, 25.450000000000006,
      25.500000000000007, 25.550000000000004, 25.600000000000009,
      25.650000000000006, 25.700000000000006, 25.750000000000007,
      25.800000000000004, 25.850000000000009, 25.900000000000006,
      25.950000000000006, 26.000000000000007, 26.050000000000004,
      26.100000000000009, 26.150000000000006, 26.200000000000006,
      26.250000000000007, 26.300000000000004, 26.350000000000009,
      26.400000000000006, 26.450000000000006, 26.500000000000007,
      26.550000000000004, 26.600000000000009, 26.650000000000006,
      26.700000000000006, 26.750000000000007, 26.800000000000004,
      26.850000000000009, 26.900000000000006, 26.950000000000006,
      27.000000000000007, 27.050000000000004, 27.100000000000009,
      27.150000000000006, 27.200000000000006, 27.250000000000007,
      27.300000000000004, 27.350000000000009, 27.400000000000006,
      27.450000000000006, 27.500000000000007, 27.550000000000004,
      27.600000000000009, 27.650000000000006, 27.700000000000006,
      27.750000000000007, 27.800000000000004, 27.850000000000009,
      27.900000000000006, 27.950000000000006, 28.000000000000007,
      28.050000000000004, 28.100000000000009, 28.150000000000006,
      28.200000000000006, 28.250000000000007, 28.300000000000004,
      28.350000000000009, 28.400000000000006, 28.450000000000006,
      28.500000000000007, 28.550000000000004, 28.600000000000009,
      28.650000000000006, 28.700000000000006, 28.750000000000007,
      28.800000000000004, 28.850000000000009, 28.900000000000006,
      28.950000000000006, 29.000000000000007, 29.050000000000004,
      29.100000000000009, 29.150000000000006, 29.200000000000006,
      29.250000000000007, 29.300000000000004, 29.350000000000009,
      29.400000000000006, 29.450000000000006, 29.500000000000007,
      29.550000000000004, 29.600000000000009, 29.650000000000006,
      29.700000000000006, 29.750000000000007, 29.800000000000004,
      29.850000000000009, 29.900000000000006, 29.950000000000006,
      30.000000000000007, 30.050000000000008, 30.100000000000009,
      30.150000000000006, 30.200000000000006, 30.250000000000007,
      30.300000000000008, 30.350000000000009, 30.400000000000006,
      30.450000000000006, 30.500000000000007, 30.550000000000008,
      30.600000000000009, 30.650000000000006, 30.700000000000006,
      30.750000000000007, 30.800000000000008, 30.850000000000009,
      30.900000000000006, 30.950000000000006, 31.000000000000007,
      31.050000000000008, 31.100000000000009, 31.150000000000006,
      31.200000000000006, 31.250000000000007, 31.300000000000008,
      31.350000000000009, 31.400000000000006, 31.450000000000006,
      31.500000000000007, 31.550000000000008, 31.600000000000009,
      31.650000000000006, 31.700000000000006, 31.750000000000007,
      31.800000000000008, 31.850000000000009, 31.900000000000006,
      31.950000000000006, 32.000000000000007, 32.050000000000004,
      32.100000000000009, 32.150000000000006, 32.2, 32.250000000000007,
      32.300000000000004, 32.350000000000009, 32.400000000000006, 32.45,
      32.500000000000007, 32.550000000000004, 32.600000000000009,
      32.650000000000006, 32.7, 32.750000000000007, 32.800000000000004,
      32.850000000000009, 32.900000000000006, 32.95, 33.000000000000007,
      33.050000000000004, 33.100000000000009, 33.150000000000006, 33.2,
      33.250000000000007, 33.300000000000004, 33.350000000000009,
      33.400000000000006, 33.45000000000001, 33.500000000000007,
      33.550000000000004, 33.600000000000009, 33.650000000000006,
      33.70000000000001, 33.750000000000007, 33.800000000000004,
      33.850000000000009, 33.900000000000006, 33.95000000000001,
      34.000000000000007, 34.050000000000004, 34.100000000000009,
      34.150000000000006, 34.20000000000001, 34.250000000000007,
      34.300000000000004, 34.350000000000009, 34.400000000000006,
      34.45000000000001, 34.500000000000007, 34.550000000000004,
      34.600000000000009, 34.650000000000006, 34.70000000000001,
      34.750000000000007, 34.800000000000004, 34.850000000000009,
      34.900000000000006, 34.95000000000001, 35.000000000000007,
      35.050000000000004, 35.100000000000009, 35.150000000000006,
      35.20000000000001, 35.250000000000007, 35.300000000000004,
      35.350000000000009, 35.400000000000006, 35.45000000000001,
      35.500000000000007, 35.550000000000004, 35.600000000000009,
      35.650000000000006, 35.70000000000001, 35.750000000000007,
      35.800000000000004, 35.850000000000009, 35.900000000000006,
      35.95000000000001, 36.000000000000007, 36.050000000000004,
      36.100000000000009, 36.150000000000006, 36.20000000000001,
      36.250000000000007, 36.300000000000004, 36.350000000000009,
      36.400000000000006, 36.45000000000001, 36.500000000000007,
      36.550000000000004, 36.600000000000009, 36.650000000000006,
      36.70000000000001, 36.750000000000007, 36.800000000000004,
      36.850000000000009, 36.900000000000006, 36.95000000000001,
      37.000000000000007, 37.050000000000004, 37.100000000000009,
      37.150000000000006, 37.20000000000001, 37.250000000000007,
      37.300000000000004, 37.350000000000009, 37.400000000000006,
      37.45000000000001, 37.500000000000007, 37.550000000000004,
      37.600000000000009, 37.650000000000006, 37.70000000000001,
      37.750000000000007, 37.800000000000004, 37.850000000000009,
      37.900000000000006, 37.95000000000001, 38.000000000000007 } ;

    static real_T pDataValues0[] = { 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65, 0.65,
      0.65, 0.65, 0.65, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5,
      0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5,
      0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5,
      0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8,
      0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8,
      0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5,
      0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8,
      0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8,
      0.8, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8,
      0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.8,
      0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8,
      0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.8,
      0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5,
      0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5,
      0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5,
      0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5,
      0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5,
      0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5,
      0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5,
      0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5,
      0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5,
      0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8,
      0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.5, 0.8,
      0.8, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5,
      0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.5, 0.5, 0.8, 0.8, 0.8,
      0.8, 0.5, 0.5, 0.5, 0.5, 0.8, 0.8, 0.8, 0.8, 0.8, 0.8, 0.5, 0.5, 0.5, 0.5,
      0.8, 0.8, 0.8, 0.8, 0.8 } ;

    DAtosInOut_PRBS_DW.PRBS_PWORK.TimePtr = (void *) pTimeValues0;
    DAtosInOut_PRBS_DW.PRBS_PWORK.DataPtr = (void *) pDataValues0;
    DAtosInOut_PRBS_DW.PRBS_IWORK.PrevIndex = 0;
  }

  /* Start for S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[0];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (donipcim): '<Root>/PCI-6221 DO' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[1];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for S-Function (scblock): '<S2>/S-Function' */

  /* S-Function Block: <S2>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(1)) == 0) {
      if ((i = rl32eDefScope(1,3)) != 0) {
        printf("Error creating scope 1\n");
      } else {
        rl32eAddSignal(1, rl32eGetSignalNo("RPM carga  Normalizada"));
        rl32eSetScope(1, 4, 760);
        rl32eSetScope(1, 5, 0);
        rl32eSetScope(1, 6, 1);
        rl32eSetScope(1, 0, 0);
        xpceFSScopeSet(1, "salida.dat", 0, 512, 0, 536870912);
        rl32eSetScope (1, 10, 0);
        rl32eSetScope(1, 3, rl32eGetSignalNo("RPM carga  Normalizada"));
        rl32eSetScope(1, 1, 0.0);
        rl32eSetScope(1, 2, 0);
        rl32eSetScope(1, 9, 0);
        xpceScopeAcqOK(1, &DAtosInOut_PRBS_DW.SFunction_IWORK.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(1);
    }
  }

  /* Start for S-Function (scblock): '<S3>/S-Function' */

  /* S-Function Block: <S3>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(2)) == 0) {
      if ((i = rl32eDefScope(2,3)) != 0) {
        printf("Error creating scope 2\n");
      } else {
        rl32eAddSignal(2, rl32eGetSignalNo("PRBS"));
        rl32eSetScope(2, 4, 760);
        rl32eSetScope(2, 5, 0);
        rl32eSetScope(2, 6, 1);
        rl32eSetScope(2, 0, 0);
        xpceFSScopeSet(2, "entrada.dat", 0, 512, 0, 536870912);
        rl32eSetScope (2, 10, 0);
        rl32eSetScope(2, 3, rl32eGetSignalNo("PRBS"));
        rl32eSetScope(2, 1, 0.0);
        rl32eSetScope(2, 2, 0);
        rl32eSetScope(2, 9, 0);
        xpceScopeAcqOK(2, &DAtosInOut_PRBS_DW.SFunction_IWORK_f.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(2);
    }
  }

  /* Start for S-Function (scblock): '<S6>/S-Function' */

  /* S-Function Block: <S6>/S-Function (scblock) */
  {
    int i;
    if ((i = rl32eScopeExists(3)) == 0) {
      if ((i = rl32eDefScope(3,1)) != 0) {
        printf("Error creating scope 3\n");
      } else {
        rl32eAddSignal(3, rl32eGetSignalNo("PRBS"));
        rl32eAddSignal(3, rl32eGetSignalNo("RPM carga  Normalizada"));
        rl32eSetScope(3, 4, 760);
        rl32eSetScope(3, 5, 1);
        rl32eSetScope(3, 6, 1);
        rl32eSetScope(3, 0, 0);
        rl32eSetScope(3, 3, rl32eGetSignalNo("PRBS"));
        rl32eSetScope(3, 1, 0.0);
        rl32eSetScope(3, 2, 0);
        rl32eSetScope(3, 9, 0);
        xpceScopeAcqOK(3, &DAtosInOut_PRBS_DW.SFunction_IWORK_g.AcquireOK);
      }
    }

    if (i) {
      rl32eRestartAcquisition(3);
    }
  }

  /* Start for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[2];
    sfcnStart(rts);
    if (ssGetErrorStatus(rts) != (NULL))
      return;
  }

  /* Start for FromWorkspace: '<S4>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 1.0, 1.0, 2.0, 2.0, 2.02, 2.02, 2.34,
      2.34, 2.38, 2.38, 3.0, 3.0, 4.0, 4.0, 4.62, 4.62, 4.64, 4.64, 5.3, 5.3,
      5.32, 5.32, 6.0, 6.0, 7.0, 7.0, 8.0, 8.0, 9.0, 9.0, 9.02, 9.02, 10.0, 10.0,
      11.94, 11.94, 12.0, 12.0, 12.280000000000001, 12.280000000000001, 12.3,
      12.3, 12.4, 12.4, 12.700000000000001, 12.700000000000001,
      12.780000000000001, 12.780000000000001, 15.0 } ;

    static real_T pDataValues0[] = { 0.2, 0.4, 0.4, 0.20392156862745098,
      0.20392156862745098, 0.2, 0.2, 0.2, 0.4, 0.4, 0.4, 0.4, 0.4, 0.2,
      0.30000000000000004, 0.30000000000000004, 0.30000000000000004,
      0.30000000000000004, 0.30000000000000004, 0.49411764705882333,
      0.49411764705882333, 0.5, 0.4, 0.4, 0.4, 0.30000000000000004,
      0.30000000000000004, 0.4, 0.4, 0.2, 0.2, 0.2, 0.2, 0.2, 0.2, 0.5, 0.2, 0.2,
      0.2, 0.2, 0.2, 0.30000000000000004, 0.30000000000000004,
      0.30000000000000004, 0.30000000000000004, 0.30000000000000004, 0.4,
      0.39304347826086961, 0.39304347826086961, 0.2, -0.2, -0.60000000000000009,
      -0.60000000000000009, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.8, -0.8,
      -0.60000000000000009, -0.2, -0.8, -0.8, -0.8, -0.79411764705882359,
      -0.79411764705882359, -0.60000000000000009, -0.4, -0.4, -0.4, -0.4,
      -0.60000000000000009, -0.8, -0.8, -0.4, -0.4, -0.2039215686274507,
      -0.2039215686274507, -0.2, -0.2, -0.2, -0.2, -0.685, -0.685,
      -0.70000000000000007, -0.2, -0.2, -0.2, -0.2, -0.2, -0.2, -0.5, -0.5, -0.5,
      -0.5, -0.30000000000000004, -0.2 } ;

    DAtosInOut_PRBS_DW.FromWs_PWORK.TimePtr = (void *) pTimeValues0;
    DAtosInOut_PRBS_DW.FromWs_PWORK.DataPtr = (void *) pDataValues0;
    DAtosInOut_PRBS_DW.FromWs_IWORK.PrevIndex = 0;
  }

  /* Start for FromWorkspace: '<S5>/FromWs' */
  {
    static real_T pTimeValues0[] = { 0.0, 0.5, 0.5, 0.8, 0.8, 1.5, 1.5, 1.6, 1.6,
      1.7000000000000002, 1.7000000000000002, 2.34, 2.34, 2.38, 2.38, 3.0, 3.0,
      3.6, 3.6, 3.9000000000000004, 3.9000000000000004, 4.3, 4.3, 5.0, 5.0, 6.0,
      6.0, 6.1000000000000005, 6.1000000000000005, 6.9, 6.9, 7.0, 7.0, 7.4, 7.4,
      7.9, 7.9, 8.4, 8.4, 10.0, 10.0, 11.94, 11.94, 12.0, 12.0,
      12.280000000000001, 12.280000000000001, 12.3, 12.3, 12.4, 12.4,
      12.700000000000001, 12.700000000000001, 12.780000000000001,
      12.780000000000001, 15.0 } ;

    static real_T pDataValues0[] = { 0.2, 0.325, 0.325, 0.4, 0.4, 0.4, 0.4,
      0.34999999999999987, 0.34999999999999987, 0.30000000000000004,
      0.30000000000000004, 0.4, 0.4, 0.4, 0.4, 0.4, 0.2, 0.2, 0.4, 0.4, 0.4,
      0.30000000000000004, 0.30000000000000004, 0.30000000000000004,
      0.30000000000000004, 0.39090909090909093, 0.39090909090909093, 0.4, 0.4,
      0.4, 0.2, 0.2, 0.2, 0.2, 0.4, 0.4, 0.2, 0.2, 0.4, 0.2, 0.2, 0.4, 0.2, 0.2,
      0.2, 0.2, 0.2, 0.4, 0.4, 0.4, 0.4, 0.4, 0.4, 0.39304347826086961,
      0.39304347826086961, 0.2, -0.2, -0.60000000000000009, -0.60000000000000009,
      -0.65454545454545465, -0.65454545454545465, -0.781818181818182,
      -0.781818181818182, -0.8, -0.4, -0.45128205128205134, -0.45128205128205134,
      -0.7794871794871796, -0.7794871794871796, -0.8, -0.8, -0.8, -0.2, -0.2,
      -0.4, -0.4, -0.60000000000000009, -0.60000000000000009, -0.8,
      -0.63529411764705879, -0.63529411764705879, -0.4, -0.4, -0.4, -0.4, -0.4,
      -0.4, -0.4, -0.2, -0.2, -0.2, -0.2, -0.8, -0.657142857142857,
      -0.657142857142857, -0.2, -0.2, -0.782, -0.782, -0.8, -0.2, -0.2, -0.2,
      -0.2, -0.2, -0.2, -0.8, -0.8, -0.8, -0.8, -0.4, -0.2 } ;

    DAtosInOut_PRBS_DW.FromWs_PWORK_b.TimePtr = (void *) pTimeValues0;
    DAtosInOut_PRBS_DW.FromWs_PWORK_b.DataPtr = (void *) pDataValues0;
    DAtosInOut_PRBS_DW.FromWs_IWORK_f.PrevIndex = 0;
  }

  /* InitializeConditions for Memory: '<Root>/Memory' */
  DAtosInOut_PRBS_DW.Memory_PreviousInput =
    DAtosInOut_PRBS_P.Memory_InitialCondition;
}

/* Model terminate function */
static void DAtosInOut_PRBS_terminate(void)
{
  /* Terminate for S-Function (pwmoutnipcim): '<Root>/PCI 6221 PWM Generate ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 PWM Generate ' (pwmoutnipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[0];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (donipcim): '<Root>/PCI-6221 DO' */
  /* Level2 S-Function Block: '<Root>/PCI-6221 DO' (donipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[1];
    sfcnTerminate(rts);
  }

  /* Terminate for S-Function (encnipcim): '<Root>/PCI 6221 ENC ' */
  /* Level2 S-Function Block: '<Root>/PCI 6221 ENC ' (encnipcim) */
  {
    SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[2];
    sfcnTerminate(rts);
  }
}

/*========================================================================*
 * Start of Classic call interface                                        *
 *========================================================================*/
void MdlOutputs(int_T tid)
{
  DAtosInOut_PRBS_output();
  UNUSED_PARAMETER(tid);
}

void MdlUpdate(int_T tid)
{
  DAtosInOut_PRBS_update();
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
  DAtosInOut_PRBS_initialize();
}

void MdlTerminate(void)
{
  DAtosInOut_PRBS_terminate();
}

/* Registration function */
RT_MODEL_DAtosInOut_PRBS_T *DAtosInOut_PRBS(void)
{
  /* Registration code */

  /* initialize non-finites */
  rt_InitInfAndNaN(sizeof(real_T));

  /* initialize real-time model */
  (void) memset((void *)DAtosInOut_PRBS_M, 0,
                sizeof(RT_MODEL_DAtosInOut_PRBS_T));

  {
    /* Setup solver object */
    rtsiSetSimTimeStepPtr(&DAtosInOut_PRBS_M->solverInfo,
                          &DAtosInOut_PRBS_M->Timing.simTimeStep);
    rtsiSetTPtr(&DAtosInOut_PRBS_M->solverInfo, &rtmGetTPtr(DAtosInOut_PRBS_M));
    rtsiSetStepSizePtr(&DAtosInOut_PRBS_M->solverInfo,
                       &DAtosInOut_PRBS_M->Timing.stepSize0);
    rtsiSetErrorStatusPtr(&DAtosInOut_PRBS_M->solverInfo, (&rtmGetErrorStatus
      (DAtosInOut_PRBS_M)));
    rtsiSetRTModelPtr(&DAtosInOut_PRBS_M->solverInfo, DAtosInOut_PRBS_M);
  }

  rtsiSetSimTimeStep(&DAtosInOut_PRBS_M->solverInfo, MAJOR_TIME_STEP);
  rtsiSetSolverName(&DAtosInOut_PRBS_M->solverInfo,"FixedStepDiscrete");
  DAtosInOut_PRBS_M->solverInfoPtr = (&DAtosInOut_PRBS_M->solverInfo);

  /* Initialize timing info */
  {
    int_T *mdlTsMap = DAtosInOut_PRBS_M->Timing.sampleTimeTaskIDArray;
    mdlTsMap[0] = 0;
    mdlTsMap[1] = 1;
    DAtosInOut_PRBS_M->Timing.sampleTimeTaskIDPtr = (&mdlTsMap[0]);
    DAtosInOut_PRBS_M->Timing.sampleTimes =
      (&DAtosInOut_PRBS_M->Timing.sampleTimesArray[0]);
    DAtosInOut_PRBS_M->Timing.offsetTimes =
      (&DAtosInOut_PRBS_M->Timing.offsetTimesArray[0]);

    /* task periods */
    DAtosInOut_PRBS_M->Timing.sampleTimes[0] = (0.0);
    DAtosInOut_PRBS_M->Timing.sampleTimes[1] = (0.05);

    /* task offsets */
    DAtosInOut_PRBS_M->Timing.offsetTimes[0] = (0.0);
    DAtosInOut_PRBS_M->Timing.offsetTimes[1] = (0.0);
  }

  rtmSetTPtr(DAtosInOut_PRBS_M, &DAtosInOut_PRBS_M->Timing.tArray[0]);

  {
    int_T *mdlSampleHits = DAtosInOut_PRBS_M->Timing.sampleHitArray;
    mdlSampleHits[0] = 1;
    mdlSampleHits[1] = 1;
    DAtosInOut_PRBS_M->Timing.sampleHits = (&mdlSampleHits[0]);
  }

  rtmSetTFinal(DAtosInOut_PRBS_M, 38.050000000000004);
  DAtosInOut_PRBS_M->Timing.stepSize0 = 0.05;
  DAtosInOut_PRBS_M->Timing.stepSize1 = 0.05;

  /* Setup for data logging */
  {
    static RTWLogInfo rt_DataLoggingInfo;
    rt_DataLoggingInfo.loggingInterval = NULL;
    DAtosInOut_PRBS_M->rtwLogInfo = &rt_DataLoggingInfo;
  }

  /* Setup for data logging */
  {
    rtliSetLogXSignalInfo(DAtosInOut_PRBS_M->rtwLogInfo, (NULL));
    rtliSetLogXSignalPtrs(DAtosInOut_PRBS_M->rtwLogInfo, (NULL));
    rtliSetLogT(DAtosInOut_PRBS_M->rtwLogInfo, "tout");
    rtliSetLogX(DAtosInOut_PRBS_M->rtwLogInfo, "");
    rtliSetLogXFinal(DAtosInOut_PRBS_M->rtwLogInfo, "");
    rtliSetLogVarNameModifier(DAtosInOut_PRBS_M->rtwLogInfo, "rt_");
    rtliSetLogFormat(DAtosInOut_PRBS_M->rtwLogInfo, 0);
    rtliSetLogMaxRows(DAtosInOut_PRBS_M->rtwLogInfo, 510);
    rtliSetLogDecimation(DAtosInOut_PRBS_M->rtwLogInfo, 1);
    rtliSetLogY(DAtosInOut_PRBS_M->rtwLogInfo, "");
    rtliSetLogYSignalInfo(DAtosInOut_PRBS_M->rtwLogInfo, (NULL));
    rtliSetLogYSignalPtrs(DAtosInOut_PRBS_M->rtwLogInfo, (NULL));
  }

  DAtosInOut_PRBS_M->solverInfoPtr = (&DAtosInOut_PRBS_M->solverInfo);
  DAtosInOut_PRBS_M->Timing.stepSize = (0.05);
  rtsiSetFixedStepSize(&DAtosInOut_PRBS_M->solverInfo, 0.05);
  rtsiSetSolverMode(&DAtosInOut_PRBS_M->solverInfo, SOLVER_MODE_SINGLETASKING);

  /* block I/O */
  DAtosInOut_PRBS_M->blockIO = ((void *) &DAtosInOut_PRBS_B);
  (void) memset(((void *) &DAtosInOut_PRBS_B), 0,
                sizeof(B_DAtosInOut_PRBS_T));

  {
    DAtosInOut_PRBS_B.Puntosporciclo = 0.0;
    DAtosInOut_PRBS_B.PRBS = 0.0;
    DAtosInOut_PRBS_B.Abs = 0.0;
    DAtosInOut_PRBS_B.PuntosenH = 0.0;
    DAtosInOut_PRBS_B.Sum1 = 0.0;
    DAtosInOut_PRBS_B.SalidaDigital = 0.0;
    DAtosInOut_PRBS_B.Memory = 0.0;
    DAtosInOut_PRBS_B.PCI6221ENC = 0.0;
    DAtosInOut_PRBS_B.Sum = 0.0;
    DAtosInOut_PRBS_B.RPMmotor = 0.0;
    DAtosInOut_PRBS_B.RPMcarga = 0.0;
    DAtosInOut_PRBS_B.RPMcargaNormalizada = 0.0;
    DAtosInOut_PRBS_B.FromWs[0] = 0.0;
    DAtosInOut_PRBS_B.FromWs[1] = 0.0;
    DAtosInOut_PRBS_B.FromWs_l[0] = 0.0;
    DAtosInOut_PRBS_B.FromWs_l[1] = 0.0;
  }

  /* parameters */
  DAtosInOut_PRBS_M->defaultParam = ((real_T *)&DAtosInOut_PRBS_P);

  /* states (dwork) */
  DAtosInOut_PRBS_M->dwork = ((void *) &DAtosInOut_PRBS_DW);
  (void) memset((void *)&DAtosInOut_PRBS_DW, 0,
                sizeof(DW_DAtosInOut_PRBS_T));
  DAtosInOut_PRBS_DW.Memory_PreviousInput = 0.0;

  /* Initialize DataMapInfo substructure containing ModelMap for C API */
  DAtosInOut_PRBS_InitializeDataMapInfo();

  /* child S-Function registration */
  {
    RTWSfcnInfo *sfcnInfo = &DAtosInOut_PRBS_M->NonInlinedSFcns.sfcnInfo;
    DAtosInOut_PRBS_M->sfcnInfo = (sfcnInfo);
    rtssSetErrorStatusPtr(sfcnInfo, (&rtmGetErrorStatus(DAtosInOut_PRBS_M)));
    rtssSetNumRootSampTimesPtr(sfcnInfo, &DAtosInOut_PRBS_M->Sizes.numSampTimes);
    DAtosInOut_PRBS_M->NonInlinedSFcns.taskTimePtrs[0] = &(rtmGetTPtr
      (DAtosInOut_PRBS_M)[0]);
    DAtosInOut_PRBS_M->NonInlinedSFcns.taskTimePtrs[1] = &(rtmGetTPtr
      (DAtosInOut_PRBS_M)[1]);
    rtssSetTPtrPtr(sfcnInfo,DAtosInOut_PRBS_M->NonInlinedSFcns.taskTimePtrs);
    rtssSetTStartPtr(sfcnInfo, &rtmGetTStart(DAtosInOut_PRBS_M));
    rtssSetTFinalPtr(sfcnInfo, &rtmGetTFinal(DAtosInOut_PRBS_M));
    rtssSetTimeOfLastOutputPtr(sfcnInfo, &rtmGetTimeOfLastOutput
      (DAtosInOut_PRBS_M));
    rtssSetStepSizePtr(sfcnInfo, &DAtosInOut_PRBS_M->Timing.stepSize);
    rtssSetStopRequestedPtr(sfcnInfo, &rtmGetStopRequested(DAtosInOut_PRBS_M));
    rtssSetDerivCacheNeedsResetPtr(sfcnInfo,
      &DAtosInOut_PRBS_M->derivCacheNeedsReset);
    rtssSetZCCacheNeedsResetPtr(sfcnInfo, &DAtosInOut_PRBS_M->zCCacheNeedsReset);
    rtssSetContTimeOutputInconsistentWithStateAtMajorStepPtr(sfcnInfo,
      &DAtosInOut_PRBS_M->CTOutputIncnstWithState);
    rtssSetSampleHitsPtr(sfcnInfo, &DAtosInOut_PRBS_M->Timing.sampleHits);
    rtssSetPerTaskSampleHitsPtr(sfcnInfo,
      &DAtosInOut_PRBS_M->Timing.perTaskSampleHits);
    rtssSetSimModePtr(sfcnInfo, &DAtosInOut_PRBS_M->simMode);
    rtssSetSolverInfoPtr(sfcnInfo, &DAtosInOut_PRBS_M->solverInfoPtr);
  }

  DAtosInOut_PRBS_M->Sizes.numSFcns = (3);

  /* register each child */
  {
    (void) memset((void *)&DAtosInOut_PRBS_M->NonInlinedSFcns.childSFunctions[0],
                  0,
                  3*sizeof(SimStruct));
    DAtosInOut_PRBS_M->childSfunctions =
      (&DAtosInOut_PRBS_M->NonInlinedSFcns.childSFunctionPtrs[0]);
    DAtosInOut_PRBS_M->childSfunctions[0] =
      (&DAtosInOut_PRBS_M->NonInlinedSFcns.childSFunctions[0]);
    DAtosInOut_PRBS_M->childSfunctions[1] =
      (&DAtosInOut_PRBS_M->NonInlinedSFcns.childSFunctions[1]);
    DAtosInOut_PRBS_M->childSfunctions[2] =
      (&DAtosInOut_PRBS_M->NonInlinedSFcns.childSFunctions[2]);

    /* Level2 S-Function Block: DAtosInOut_PRBS/<Root>/PCI 6221 PWM Generate  (pwmoutnipcim) */
    {
      SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[0];

      /* timing info */
      time_T *sfcnPeriod = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.sfcnPeriod;
      time_T *sfcnOffset = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.sfcnOffset;
      int_T *sfcnTsMap = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.blkInfo2[0]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &DAtosInOut_PRBS_M->NonInlinedSFcns.inputOutputPortInfo2[0]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, DAtosInOut_PRBS_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods2[0]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods3[0]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods4[0]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.statesInfo2[0]);
        ssSetPeriodicStatesInfo(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.periodicStatesInfo[0]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 2);
        ssSetPortInfoForInputs(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);
        ssSetInputPortUnit(rts, 1, 0);

        /* port 0 */
        {
          ssSetInputPortRequiredContiguous(rts, 0, 1);
          ssSetInputPortSignal(rts, 0, &DAtosInOut_PRBS_B.PuntosenH);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }

        /* port 1 */
        {
          ssSetInputPortRequiredContiguous(rts, 1, 1);
          ssSetInputPortSignal(rts, 1, &DAtosInOut_PRBS_B.Sum1);
          _ssSetInputPortNumDimensions(rts, 1, 1);
          ssSetInputPortWidth(rts, 1, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 PWM Generate ");
      ssSetPath(rts, "DAtosInOut_PRBS/PCI 6221 PWM Generate ");
      ssSetRTModel(rts,DAtosInOut_PRBS_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)
                       DAtosInOut_PRBS_P.PCI6221PWMGenerate_P10_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &DAtosInOut_PRBS_DW.PCI6221PWMGenerate_IWORK[0]);
      ssSetPWork(rts, (void **) &DAtosInOut_PRBS_DW.PCI6221PWMGenerate_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn0.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 2);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 5);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &DAtosInOut_PRBS_DW.PCI6221PWMGenerate_IWORK[0]);

        /* PWORK */
        ssSetDWorkWidth(rts, 1, 1);
        ssSetDWorkDataType(rts, 1,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 1, 0);
        ssSetDWork(rts, 1, &DAtosInOut_PRBS_DW.PCI6221PWMGenerate_PWORK);
      }

      /* registration */
      pwmoutnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
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

    /* Level2 S-Function Block: DAtosInOut_PRBS/<Root>/PCI-6221 DO (donipcim) */
    {
      SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[1];

      /* timing info */
      time_T *sfcnPeriod = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.sfcnPeriod;
      time_T *sfcnOffset = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.sfcnOffset;
      int_T *sfcnTsMap = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.blkInfo2[1]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &DAtosInOut_PRBS_M->NonInlinedSFcns.inputOutputPortInfo2[1]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, DAtosInOut_PRBS_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods2[1]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods3[1]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods4[1]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.statesInfo2[1]);
        ssSetPeriodicStatesInfo(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.periodicStatesInfo[1]);
      }

      /* inputs */
      {
        _ssSetNumInputPorts(rts, 1);
        ssSetPortInfoForInputs(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.inputPortInfo[0]);
        _ssSetPortInfo2ForInputUnits(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.inputPortUnits[0]);
        ssSetInputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          real_T const **sfcnUPtrs = (real_T const **)
            &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.UPtrs0;
          sfcnUPtrs[0] = &DAtosInOut_PRBS_B.SalidaDigital;
          ssSetInputPortSignalPtrs(rts, 0, (InputPtrsType)&sfcnUPtrs[0]);
          _ssSetInputPortNumDimensions(rts, 0, 1);
          ssSetInputPortWidth(rts, 0, 1);
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI-6221 DO");
      ssSetPath(rts, "DAtosInOut_PRBS/PCI-6221 DO");
      ssSetRTModel(rts,DAtosInOut_PRBS_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.params;
        ssSetSFcnParamsCount(rts, 7);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)DAtosInOut_PRBS_P.PCI6221DO_P7_Size);
      }

      /* work vectors */
      ssSetIWork(rts, (int_T *) &DAtosInOut_PRBS_DW.PCI6221DO_IWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn1.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* IWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_INTEGER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &DAtosInOut_PRBS_DW.PCI6221DO_IWORK);
      }

      /* registration */
      donipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
      ssSetOffsetTime(rts, 0, 0.0);
      sfcnTsMap[0] = 1;

      /* set compiled values of dynamic vector attributes */
      ssSetNumNonsampledZCs(rts, 0);

      /* Update connectivity flags for each port */
      _ssSetInputPortConnected(rts, 0, 1);

      /* Update the BufferDstPort flags for each input port */
      ssSetInputPortBufferDstPort(rts, 0, -1);
    }

    /* Level2 S-Function Block: DAtosInOut_PRBS/<Root>/PCI 6221 ENC  (encnipcim) */
    {
      SimStruct *rts = DAtosInOut_PRBS_M->childSfunctions[2];

      /* timing info */
      time_T *sfcnPeriod = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.sfcnPeriod;
      time_T *sfcnOffset = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.sfcnOffset;
      int_T *sfcnTsMap = DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.sfcnTsMap;
      (void) memset((void*)sfcnPeriod, 0,
                    sizeof(time_T)*1);
      (void) memset((void*)sfcnOffset, 0,
                    sizeof(time_T)*1);
      ssSetSampleTimePtr(rts, &sfcnPeriod[0]);
      ssSetOffsetTimePtr(rts, &sfcnOffset[0]);
      ssSetSampleTimeTaskIDPtr(rts, sfcnTsMap);

      {
        ssSetBlkInfo2Ptr(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.blkInfo2[2]);
      }

      _ssSetBlkInfo2PortInfo2Ptr(rts,
        &DAtosInOut_PRBS_M->NonInlinedSFcns.inputOutputPortInfo2[2]);

      /* Set up the mdlInfo pointer */
      ssSetRTWSfcnInfo(rts, DAtosInOut_PRBS_M->sfcnInfo);

      /* Allocate memory of model methods 2 */
      {
        ssSetModelMethods2(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods2[2]);
      }

      /* Allocate memory of model methods 3 */
      {
        ssSetModelMethods3(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods3[2]);
      }

      /* Allocate memory of model methods 4 */
      {
        ssSetModelMethods4(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.methods4[2]);
      }

      /* Allocate memory for states auxilliary information */
      {
        ssSetStatesInfo2(rts, &DAtosInOut_PRBS_M->NonInlinedSFcns.statesInfo2[2]);
        ssSetPeriodicStatesInfo(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.periodicStatesInfo[2]);
      }

      /* outputs */
      {
        ssSetPortInfoForOutputs(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.outputPortInfo[0]);
        _ssSetNumOutputPorts(rts, 1);
        _ssSetPortInfo2ForOutputUnits(rts,
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.outputPortUnits[0]);
        ssSetOutputPortUnit(rts, 0, 0);

        /* port 0 */
        {
          _ssSetOutputPortNumDimensions(rts, 0, 1);
          ssSetOutputPortWidth(rts, 0, 1);
          ssSetOutputPortSignal(rts, 0, ((real_T *)
            &DAtosInOut_PRBS_B.PCI6221ENC));
        }
      }

      /* path info */
      ssSetModelName(rts, "PCI 6221 ENC ");
      ssSetPath(rts, "DAtosInOut_PRBS/PCI 6221 ENC ");
      ssSetRTModel(rts,DAtosInOut_PRBS_M);
      ssSetParentSS(rts, (NULL));
      ssSetRootSS(rts, rts);
      ssSetVersion(rts, SIMSTRUCT_VERSION_LEVEL2);

      /* parameters */
      {
        mxArray **sfcnParams = (mxArray **)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.params;
        ssSetSFcnParamsCount(rts, 10);
        ssSetSFcnParamsPtr(rts, &sfcnParams[0]);
        ssSetSFcnParam(rts, 0, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P1_Size);
        ssSetSFcnParam(rts, 1, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P2_Size);
        ssSetSFcnParam(rts, 2, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P3_Size);
        ssSetSFcnParam(rts, 3, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P4_Size);
        ssSetSFcnParam(rts, 4, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P5_Size);
        ssSetSFcnParam(rts, 5, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P6_Size);
        ssSetSFcnParam(rts, 6, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P7_Size);
        ssSetSFcnParam(rts, 7, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P8_Size);
        ssSetSFcnParam(rts, 8, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P9_Size);
        ssSetSFcnParam(rts, 9, (mxArray*)DAtosInOut_PRBS_P.PCI6221ENC_P10_Size);
      }

      /* work vectors */
      ssSetPWork(rts, (void **) &DAtosInOut_PRBS_DW.PCI6221ENC_PWORK);

      {
        struct _ssDWorkRecord *dWorkRecord = (struct _ssDWorkRecord *)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.dWork;
        struct _ssDWorkAuxRecord *dWorkAuxRecord = (struct _ssDWorkAuxRecord *)
          &DAtosInOut_PRBS_M->NonInlinedSFcns.Sfcn2.dWorkAux;
        ssSetSFcnDWork(rts, dWorkRecord);
        ssSetSFcnDWorkAux(rts, dWorkAuxRecord);
        _ssSetNumDWork(rts, 1);

        /* PWORK */
        ssSetDWorkWidth(rts, 0, 1);
        ssSetDWorkDataType(rts, 0,SS_POINTER);
        ssSetDWorkComplexSignal(rts, 0, 0);
        ssSetDWork(rts, 0, &DAtosInOut_PRBS_DW.PCI6221ENC_PWORK);
      }

      /* registration */
      encnipcim(rts);
      sfcnInitializeSizes(rts);
      sfcnInitializeSampleTimes(rts);

      /* adjust sample time */
      ssSetSampleTime(rts, 0, 0.05);
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
  DAtosInOut_PRBS_M->Sizes.numContStates = (0);/* Number of continuous states */
  DAtosInOut_PRBS_M->Sizes.numY = (0); /* Number of model outputs */
  DAtosInOut_PRBS_M->Sizes.numU = (0); /* Number of model inputs */
  DAtosInOut_PRBS_M->Sizes.sysDirFeedThru = (0);/* The model is not direct feedthrough */
  DAtosInOut_PRBS_M->Sizes.numSampTimes = (2);/* Number of sample times */
  DAtosInOut_PRBS_M->Sizes.numBlocks = (23);/* Number of blocks */
  DAtosInOut_PRBS_M->Sizes.numBlockIO = (15);/* Number of block outputs */
  DAtosInOut_PRBS_M->Sizes.numBlockPrms = (88);/* Sum of parameter "widths" */
  return DAtosInOut_PRBS_M;
}

/*========================================================================*
 * End of Classic call interface                                          *
 *========================================================================*/
