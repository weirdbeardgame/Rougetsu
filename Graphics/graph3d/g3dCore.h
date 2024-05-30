#ifndef MIKOMPILATION_G3DCORE_H
#define MIKOMPILATION_G3DCORE_H

#include "sgd_types.h"

extern G3DCOREOBJECT *s_pObject;

int g3dLightEnable(int iLightId, int bEnable);
int g3dSetLight(int iLightId, G3DLIGHT *pLight);
sceVu0FVECTOR *g3dGetAmbientRef();

#endif//MIKOMPILATION_G3DCORE_H
