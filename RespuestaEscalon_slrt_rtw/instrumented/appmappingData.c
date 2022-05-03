#include "slrtappmapping.h"
#include "./maps/RespuestaEscalon.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <RespuestaEscalon> */
		{ /* SignalMapInfo */
			RespuestaEscalon_BIOMAP,
			RespuestaEscalon_LBLMAP,
			RespuestaEscalon_SIDMAP,
			RespuestaEscalon_SBIO,
			RespuestaEscalon_SLBL,
			{0,13},
			13,
		},
		{ /* ParamMapInfo */
			RespuestaEscalon_PTIDSMAP,
			RespuestaEscalon_PTNAMESMAP,
			RespuestaEscalon_SPTMAP,
			{0,33},
			34,
		},
		"RespuestaEscalon",
		"",
		"RespuestaEscalon",
		2,
		RespuestaEscalon_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}