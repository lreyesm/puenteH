#ifndef RTW_HEADER_RespuestaEscalon_cap_host_h_
#define RTW_HEADER_RespuestaEscalon_cap_host_h_
#ifdef HOST_CAPI_BUILD
#include "rtw_capi.h"
#include "rtw_modelmap.h"

typedef struct {
  rtwCAPI_ModelMappingInfo mmi;
} RespuestaEscalon_host_DataMapInfo_T;

#ifdef __cplusplus

extern "C" {

#endif

  void RespuestaEscalon_host_InitializeDataMapInfo
    (RespuestaEscalon_host_DataMapInfo_T *dataMap, const char *path);

#ifdef __cplusplus

}
#endif
#endif                                 /* HOST_CAPI_BUILD */
#endif                                 /* RTW_HEADER_RespuestaEscalon_cap_host_h_ */

/* EOF: RespuestaEscalon_capi_host.h */
