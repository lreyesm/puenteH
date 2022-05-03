#include "slrtappmapping.h"
#include "./maps/DeteccionNoLinealidadesConBuilder.map"



const AppMapInfo appInfo[] = 
{
	{ /* Idx 0, <DeteccionNoLinealidadesConBuilder> */
		{ /* SignalMapInfo */
			DeteccionNoLinealidadesConBuilder_BIOMAP,
			DeteccionNoLinealidadesConBuilder_LBLMAP,
			DeteccionNoLinealidadesConBuilder_SIDMAP,
			DeteccionNoLinealidadesConBuilder_SBIO,
			DeteccionNoLinealidadesConBuilder_SLBL,
			{0,12},
			13,
		},
		{ /* ParamMapInfo */
			DeteccionNoLinealidadesConBuilder_PTIDSMAP,
			DeteccionNoLinealidadesConBuilder_PTNAMESMAP,
			DeteccionNoLinealidadesConBuilder_SPTMAP,
			{0,32},
			33,
		},
		"DeteccionNoLinealidadesConBuilder",
		"",
		"DeteccionNoLinealidadesConBuilder",
		2,
		DeteccionNoLinealidadesConBuilder_dtmap,
	},
};
int getNumRef(void){
	 return(sizeof(appInfo) / sizeof(AppMapInfo));
}