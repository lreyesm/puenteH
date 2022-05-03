#include "slrtappmapping.h"
#include "./maps/DAtosInOut_PRBS.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <DAtosInOut_PRBS> */
		{ /* SignalMapInfo */
			DAtosInOut_PRBS_BIOMAP,
			DAtosInOut_PRBS_LBLMAP,
			DAtosInOut_PRBS_SIDMAP,
			DAtosInOut_PRBS_SBIO,
			DAtosInOut_PRBS_SLBL,
			{0,16},
			15,
		},
		{ /* ParamMapInfo */
			DAtosInOut_PRBS_PTIDSMAP,
			DAtosInOut_PRBS_PTNAMESMAP,
			DAtosInOut_PRBS_SPTMAP,
			{0,33},
			34,
		},
		"DAtosInOut_PRBS",
		"",
		"DAtosInOut_PRBS",
		2,
		DAtosInOut_PRBS_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}