#include "g3dCore.h"

int g3dLightEnable(int iLightId, int bEnable)
{
  return 0;
}

int g3dSetLight(int iLightId, G3DLIGHT *pLight)
{
  return 0;
}

sceVu0FVECTOR *g3dGetAmbientRef()
{
#line 522
  g3ddbg_ASSERT(s_pObject, "g3d is not initialized yet");
  return &s_pObject->vAmbient;
}