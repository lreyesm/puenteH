#ifndef __DeteccionNoLinealidadesConBuilder_XPCOPTIONS_H___
#define __DeteccionNoLinealidadesConBuilder_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "DeteccionNoLinealidadesConBuilder.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_DeteccionNoLinealidadesConBuilder_T))
#define SIMMODE                        0
#define LOGTET                         1
#define LOGBUFSIZE                     100000
#define PROFILINGFLAG                  1
#define EVENTNUMBER                    5000
#define IRQ_NO                         0
#define IO_IRQ                         0
#define WWW_ACCESS_LEVEL               0
#define CPUCLOCK                       0
#define MAXOVERLOAD                    0
#define MAXOVERLOADLEN                 0
#define XPCMODELSTACKSIZEKB            2048
#define XPCSTARTUPFLAG                 1
#define PTLOADPARAMFLAG                0
#define DOUBLEBUFFERING                0
#define SLRTFTZOFFFLAG                 0

/* Change all stepsize using the newBaseRateStepSize */
void DeteccionNoLinealidadesConBuilder_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_DeteccionNoLinealidadesConBuilder_T *const
  DeteccionNoLinealidadesConBuilder_M)
{
  real_T ratio = newBaseRateStepSize / 0.02;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  DeteccionNoLinealidadesConBuilder_M->Timing.stepSize0 =
    DeteccionNoLinealidadesConBuilder_M->Timing.stepSize0 * ratio;
  DeteccionNoLinealidadesConBuilder_M->Timing.stepSize1 =
    DeteccionNoLinealidadesConBuilder_M->Timing.stepSize1 * ratio;
  DeteccionNoLinealidadesConBuilder_M->Timing.stepSize =
    DeteccionNoLinealidadesConBuilder_M->Timing.stepSize * ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  DeteccionNoLinealidadesConBuilder_ChangeStepSize(stepSize,
    DeteccionNoLinealidadesConBuilder_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(DeteccionNoLinealidadesConBuilder_M, errMsg);
}

#endif                                 /* __DeteccionNoLinealidadesConBuilder_XPCOPTIONS_H___ */
