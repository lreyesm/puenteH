/*
 * RespuestaEscalon_data.c
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

#include "RespuestaEscalon.h"
#include "RespuestaEscalon_private.h"

/* Block parameters (auto storage) */
P_RespuestaEscalon_T RespuestaEscalon_P = {
  /* Variable: T
   * Referenced by: '<Root>/RPM motor'
   */
  0.02,

  /* Expression: 80000000
   * Referenced by: '<Root>/Frec de base de tiempos'
   */
  8.0E+7,

  /* Expression: 200
   * Referenced by: '<Root>/Frecuencia PWM'
   */
  200.0,

  /* Computed Parameter: PCI6221PWMGenerate_P1_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  0.0,

  /* Computed Parameter: PCI6221PWMGenerate_P2_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  -1.0,

  /* Computed Parameter: PCI6221PWMGenerate_P3_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: slot
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  -1.0,

  /* Computed Parameter: PCI6221PWMGenerate_P4_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: initHigh
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  0.0,

  /* Computed Parameter: PCI6221PWMGenerate_P5_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: initLow
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  0.0,

  /* Computed Parameter: PCI6221PWMGenerate_P6_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: outmask
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  4096.0,

  /* Computed Parameter: PCI6221PWMGenerate_P7_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: arm
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  0.0,

  /* Computed Parameter: PCI6221PWMGenerate_P8_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: disarmlevel
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  1.0,

  /* Computed Parameter: PCI6221PWMGenerate_P9_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: stoplevel
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  1.0,

  /* Computed Parameter: PCI6221PWMGenerate_P10_Size
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/PCI 6221 PWM Generate '
   */
  21.0,

  /* Expression: 0
   * Referenced by: '<S1>/Constant'
   */
  0.0,

  /* Computed Parameter: PCI6221DO_P1_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  1.0,

  /* Computed Parameter: PCI6221DO_P2_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: reset
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  1.0,

  /* Computed Parameter: PCI6221DO_P3_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: initValue
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  0.0,

  /* Computed Parameter: PCI6221DO_P4_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: sampletime
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  0.02,

  /* Computed Parameter: PCI6221DO_P5_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: slot
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  -1.0,

  /* Computed Parameter: PCI6221DO_P6_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: control
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  1.0,

  /* Computed Parameter: PCI6221DO_P7_Size
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  { 1.0, 1.0 },

  /* Expression: boardType
   * Referenced by: '<Root>/PCI-6221 DO'
   */
  21.0,

  /* Expression: 0
   * Referenced by: '<Root>/Memory'
   */
  0.0,

  /* Computed Parameter: PCI6221ENC_P1_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: device
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  21.0,

  /* Computed Parameter: PCI6221ENC_P2_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: channel
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P3_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: countMode
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  3.0,

  /* Computed Parameter: PCI6221ENC_P4_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: initCount
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.0,

  /* Computed Parameter: PCI6221ENC_P5_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: reload
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.0,

  /* Computed Parameter: PCI6221ENC_P6_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: indexPhase
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P7_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: filter
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  1.0,

  /* Computed Parameter: PCI6221ENC_P8_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: outmask
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  4096.0,

  /* Computed Parameter: PCI6221ENC_P9_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: sampleTime
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  0.02,

  /* Computed Parameter: PCI6221ENC_P10_Size
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  { 1.0, 1.0 },

  /* Expression: slot
   * Referenced by: '<Root>/PCI 6221 ENC '
   */
  -1.0,

  /* Expression: 1/19
   * Referenced by: '<Root>/RPM carga'
   */
  0.052631578947368418,

  /* Expression: 1/1
   * Referenced by: '<Root>/RPM carga  Normalizada'
   */
  1.0
};
