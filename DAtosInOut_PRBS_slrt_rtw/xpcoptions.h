#ifndef __DAtosInOut_PRBS_XPCOPTIONS_H___
#define __DAtosInOut_PRBS_XPCOPTIONS_H___
#include "simstruc_types.h"
#ifndef MT
#define MT                             0                         /* MT may be undefined by simstruc_types.h */
#endif

#include "DAtosInOut_PRBS.h"
#define XPCMDSSUPPORT                  0
#define MDSTASKSNUM                    0
#define FULLMULTITHREAD                0
#define SIZEOF_PARAMS                  (-1 * (int)sizeof(P_DAtosInOut_PRBS_T))
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
void DAtosInOut_PRBS_ChangeStepSize(real_T newBaseRateStepSize,
  RT_MODEL_DAtosInOut_PRBS_T *const DAtosInOut_PRBS_M)
{
  real_T ratio = newBaseRateStepSize / 0.05;

  /* update non-zore stepsize of periodic
   * sample time. Stepsize of asynchronous
   * sample time is not changed in this function */
  DAtosInOut_PRBS_M->Timing.stepSize0 = DAtosInOut_PRBS_M->Timing.stepSize0 *
    ratio;
  DAtosInOut_PRBS_M->Timing.stepSize1 = DAtosInOut_PRBS_M->Timing.stepSize1 *
    ratio;
  DAtosInOut_PRBS_M->Timing.stepSize = DAtosInOut_PRBS_M->Timing.stepSize *
    ratio;
}

void XPCCALLCONV changeStepSize(real_T stepSize)
{
  /* Change all stepsize using the newBaseRateStepSize */
  DAtosInOut_PRBS_ChangeStepSize(stepSize, DAtosInOut_PRBS_M);
}

void XPCCALLCONV SLRTSetErrorStatus(const char * errMsg)
{
  rtmSetErrorStatus(DAtosInOut_PRBS_M, errMsg);
}

#endif                                 /* __DAtosInOut_PRBS_XPCOPTIONS_H___ */
