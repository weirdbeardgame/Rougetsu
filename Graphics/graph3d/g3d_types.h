#ifndef ROUGETSU_G3D_TYPES_H
#define ROUGETSU_G3D_TYPES_H

#include "../sce/sce_types.h"

struct _LIGHT_POINT_AND_SPOT_NUM
{
  int iPad0;
  int iNumSpotGroup;
  int iNumPointGroup;
  int iPad1;
};

union SCEGIFTAG_EOP
{
  qword gtEOP;
  _LIGHT_POINT_AND_SPOT_NUM lightnum;
};

typedef enum
{
  LID_DIRECTIONAL_0 = 0,
  LID_DIRECTIONAL_1 = 1,
  LID_DIRECTIONAL_2 = 2,
  LID_POINT_0 = 3,
  LID_POINT_1 = 4,
  LID_POINT_2 = 5,
  LID_POINT_3 = 6,
  LID_POINT_4 = 7,
  LID_POINT_5 = 8,
  LID_POINT_6 = 9,
  LID_POINT_7 = 10,
  LID_POINT_8 = 11,
  LID_POINT_9 = 12,
  LID_POINT_10 = 13,
  LID_POINT_11 = 14,
  LID_POINT_12 = 15,
  LID_POINT_13 = 16,
  LID_POINT_14 = 17,
  LID_POINT_15 = 18,
  LID_POINT_FLASHLIGHT_0 = 19,
  LID_POINT_FLASHLIGHT_1 = 20,
  LID_POINT_SELFREFLECTION = 21,
  LID_SPOT_0 = 22,
  LID_SPOT_1 = 23,
  LID_SPOT_2 = 24,
  LID_SPOT_3 = 25,
  LID_SPOT_4 = 26,
  LID_SPOT_5 = 27,
  LID_SPOT_6 = 28,
  LID_SPOT_7 = 29,
  LID_SPOT_8 = 30,
  LID_SPOT_9 = 31,
  LID_SPOT_10 = 32,
  LID_SPOT_11 = 33,
  LID_SPOT_12 = 34,
  LID_SPOT_13 = 35,
  LID_SPOT_14 = 36,
  LID_SPOT_15 = 37,
  LID_SPOT_FLASHLIGHT = 38,
  NUM_GRA3DLIGHTID = 39,
  GRA3D_START_LIGHT_DIRECTIONAL = 0,
  GRA3D_END_LIGHT_DIRECTIONAL = 2,
  GRA3D_NUM_LIGHT_DIRECTIONAL = 3,
  GRA3D_START_LIGHT_POINT = 3,
  GRA3D_END_LIGHT_POINT = 21,
  GRA3D_NUM_LIGHT_POINT = 19,
  GRA3D_NUM_LIGHT_POINT_STATIC = 16,
  GRA3D_START_LIGHT_SPOT = 22,
  GRA3D_END_LIGHT_SPOT = 38,
  GRA3D_NUM_LIGHT_SPOT = 17,
  GRA3D_NUM_LIGHT_SPOT_STATIC = 16,
  INVALID_GRA3DLIGHTID = 2147483647,
  GRA3DLIGHTID_FORCE_DWORD = 2147483647
} GRA3DLIGHTID;

typedef enum
{
  G3DLIGHT_DIRECTIONAL = 0,
  G3DLIGHT_POINT = 1,
  G3DLIGHT_SPOT = 2,
  NUM_G3DLIGHTTYPE = 3,
  G3DLIGHT_AMBIENT = 3,
  INVALID_G3DLIGHTTYPE = 2147483647,
  G3DLIGHTTYPE_FORCE_DWORD = 2147483647
} G3DLIGHTTYPE;

struct G3DLIGHT
{
  /* 0x00 */ sceVu0FVECTOR vDiffuse;
  /* 0x10 */ sceVu0FVECTOR vSpecular;
  /* 0x20 */ sceVu0FVECTOR vAmbient;
  /* 0x30 */ sceVu0FVECTOR vPosition;
  /* 0x40 */ sceVu0FVECTOR vDirection;
  /* 0x50 */ G3DLIGHTTYPE Type;
  /* 0x54 */ float fAngleInside;
  /* 0x58 */ float fAngleOutside;
  /* 0x5c */ float fMaxRange;
  /* 0x60 */ float fMinRange;
  /* 0x64 */ float fFalloff;
  /* 0x68 */ float afPad0[2];
};

struct G3DVIF1CODE_UNPACK
{// 0x4
  /* 0x0:0 */ unsigned int ADDR : 10;
  /* 0x1:2 */ unsigned int pad : 4;
  /* 0x1:6 */ unsigned int USN : 1;
  /* 0x1:7 */ unsigned int FLG : 1;
  /* 0x2:0 */ unsigned int NUM : 8;
  /* 0x3:0 */ unsigned int CMD : 8;
};

struct GRA3DMATERIALINDEXCACHE
{
  /* 0x0 */ int bEnable;
  /* 0x4 */ int aiIndex[3];
};

struct GRA3DVU1LIGHTDATA_DIRECTIONAL
{
  LMATRIX lmDiffuse;
  LMATRIX lmSpecular;
};

struct GRA3DVU1LIGHTDATA_POINT
{
  LMATRIX lmPosition;
  float _vDirectionInverse[4];
};

struct GRA3DVU1LIGHTDATA_SPOT
{
  LMATRIX lmPosition;
  float vIntens[4];
  float vIntensB[4];
  LMATRIX lmDirection;
  LMATRIX lmSpecular;
};

struct GRA3DVU1LIGHTDATA
{
  GRA3DVU1LIGHTDATA_DIRECTIONAL dir;
  GRA3DVU1LIGHTDATA_SPOT spot;
  GRA3DVU1LIGHTDATA_POINT point;
};

struct GRA3DVU1DBADDRESS
{
  unsigned int uiContext0;
  unsigned int uiContext1;
  unsigned int auiPad[2];
};

struct G3DVU1FOG
{
  float fMin;
  float fMax;
  float FA;
  float FB;
};

struct GRA3DVU1MEMLAYOUT_DIRECT
{
  float _vVF1[4];
  float _vVF2[4];
  GRA3DVU1DBADDRESS DBAddress;
  qword gtTRISTRIP_NOTEXTURE;
  qword gtTRISTRIP_TEXTURE;
  SCEGIFTAG_EOP gtEOP;
  qword gtTRIFAN_NOTEXTURE;
  qword gtTRIFAN_TEXTURE;
  float matWorldScreen[4][4];
  float matWorldClip[4][4];
  float matLocalWorld[4][4];
  float matLocalWorldNoNormalized[4][4];
  G3DVU1FOG Fog;
  LMATRIX lmatDiffuse_Directional;
  LMATRIX lmatSpecular_Directional;
  float vPosition_Spot0[4];
  float vPosition_Spot1[4];
  float vPosition_Spot2[4];
  float vIntension_Spot[4];
  float vIntensionB_Spot[4];
  LMATRIX lmatDiffuse_Spot;
  LMATRIX lmatSpecular_Spot;
  float vPosition_Point0[4];
  float vPosition_Point1[4];
  float vPosition_Point2[4];
  float _vEyeDirection_Point[4];
  float vAmbient_Directional[4];
  LMATRIX lmatDiffuse_Directional_Material;
  LMATRIX lmatSpecular_Directional_Material;
  float vBTimes_Spot[4];
  LMATRIX lmatDiffuse_Spot_Material;
  LMATRIX lmatSpecular_Spot_Material;
  float vBTimes_Point[4];
  LMATRIX lmatDiffuse_Point_Material;
  LMATRIX lmatSpecular_Point_Material;
};

struct GRA3DVU1CONSTDATA
{
  float _vVF1[4];
  float _vVF2[4];
  GRA3DVU1DBADDRESS DBAddress;
  qword gtTRISTRIP_NOTEXTURE;
  qword gtTRISTRIP_TEXTURE;
  SCEGIFTAG_EOP gtEOP;
  qword gtTRIFAN_NOTEXTURE;
  qword gtTRIFAN_TEXTURE;
};

struct GRA3DVU1TRANSFORMDATA
{
  float matWorldScreen[4][4];
  float matWorldClip[4][4];
  float matLocalWorld[4][4];
  float matLocalWorldNoNormalized[4][4];
};

struct GRA3DVU1MATERIALDATA_POINT
{
  float vPower[4];
  LMATRIX lmDiffuse;
  LMATRIX lmSpecular;
};

struct GRA3DVU1MATERIALDATA_SPOT
{
  float vPower[4];
  LMATRIX lmDiffuse;
  LMATRIX lmSpecular;
};

struct GRA3DVU1MATERIALDATA_DIRECTIONAL
{
  float vAmbient[4];
  LMATRIX lmDiffuse;
  LMATRIX lmSpecular;
};

struct GRA3DVU1MATERIALCACHE_POINT
{
  GRA3DVU1MATERIALDATA_POINT Data;
  GRA3DMATERIALINDEXCACHE Index;
};

struct GRA3DVU1MATERIALCACHE_SPOT
{
  GRA3DVU1MATERIALDATA_SPOT Data;
  GRA3DMATERIALINDEXCACHE Index;
};

struct GRA3DVU1MATERIALDATA
{
  GRA3DVU1MATERIALDATA_DIRECTIONAL dir;
  GRA3DVU1MATERIALDATA_SPOT spot;
  GRA3DVU1MATERIALDATA_POINT point;
};

struct GRA3DVU1MEMLAYOUT_PACKED
{
  GRA3DVU1CONSTDATA Const;
  GRA3DVU1TRANSFORMDATA Transform;
  G3DVU1FOG Fog;
  GRA3DVU1LIGHTDATA Light;
  GRA3DVU1MATERIALDATA Material;
};

union GRA3DVU1MEMLAYOUT
{
  GRA3DVU1MEMLAYOUT_DIRECT Direct;
  GRA3DVU1MEMLAYOUT_PACKED Packed;
};

struct GRA3DSCRATCHPADLAYOUT
{
  qword qwVif1Code0;
  GRA3DVU1MEMLAYOUT Vu1Mem;
};

struct _LIGHTDATA
{// 0x80
  /* 0x00 */ G3DLIGHT L;
  /* 0x70 */ int bEnable;
};

struct G3DMATERIAL
{// 0x50
  /* 0x00 */ sceVu0FVECTOR vDiffuse;
  /* 0x10 */ sceVu0FVECTOR vAmbient;
  /* 0x20 */ sceVu0FVECTOR vSpecular;
  /* 0x30 */ sceVu0FVECTOR vEmissive;
  /* 0x40 */ float fPower;
  /* 0x44 */ int aiPad[3];
};

struct G3DWINDOW
{// 0x10
  /* 0x0 */ float fAspectX;
  /* 0x4 */ float fAspectY;
  /* 0x8 */ float fCenterX;
  /* 0xc */ float fCenterY;
};

struct G3DVIEWPORT
{// 0x18
  /* 0x00 */ float fX;
  /* 0x04 */ float fY;
  /* 0x08 */ float fWidth;
  /* 0x0c */ float fHeight;
  /* 0x10 */ float fMinZ;
  /* 0x14 */ float fMaxZ;
};

enum G3DRESOURCETYPE
{
  G3DRTYPE_TEXTURE = 1,
  G3DRTYPE_VERTEXBUFFER = 2,
  G3DRTYPE_INDEXBUFFER = 3,
  INVALID_G3DRESOURCETYPE = 2147483647,
  G3DRTYPE_FORCE_DWORD = 2147483647
};

struct G3DVU1LIGHTACTIVITYSTATUS
{// 0x4
  /* 0x0:0 */ unsigned int uiEnableDir0 : 1;
  /* 0x0:1 */ unsigned int uiEnableDir1 : 1;
  /* 0x0:2 */ unsigned int uiEnableDir2 : 1;
  /* 0x0:3 */ unsigned int _uiPad0 : 1;
  /* 0x0:4 */ unsigned int uiEnablePoint0 : 1;
  /* 0x0:5 */ unsigned int uiEnablePoint1 : 1;
  /* 0x0:6 */ unsigned int uiEnablePoint2 : 1;
  /* 0x0:7 */ unsigned int _uiPad1 : 1;
  /* 0x1:0 */ unsigned int uiEnableSpot0 : 1;
  /* 0x1:1 */ unsigned int uiEnableSpot1 : 1;
  /* 0x1:2 */ unsigned int uiEnableSpot2 : 1;
  /* 0x1:3 */ unsigned int _uiPad2 : 1;
  /* 0x1:4 */ unsigned int _uiPad : 4;
};

struct G3DVU1LIGHTSTATUS
{// 0x10
  /* 0x0 */ unsigned int auiPad[2];
  /* 0x8 */ union
  {// 0x8
    /* 0x8 */ G3DVU1LIGHTACTIVITYSTATUS as;
    /* 0x8 */ long int lAS;
  };
};

struct G3DVU1COLOR_DIRECTIONAL
{// 0x90
  /* 0x00 */ sceVu0FVECTOR avAmbient[3];
  /* 0x30 */ sceVu0FVECTOR avDiffuse[3];
  /* 0x60 */ sceVu0FVECTOR avSpecular[3];
};

struct G3DVU1COLOR_POINT
{// 0x90
  /* 0x00 */ sceVu0FVECTOR avAmbient[3];
  /* 0x30 */ sceVu0FVECTOR avDiffuse[3];
  /* 0x60 */ sceVu0FVECTOR avSpecular[3];
};

struct G3DVU1COLOR_SPOT
{// 0x90
  /* 0x00 */ sceVu0FVECTOR avAmbient[3];
  /* 0x30 */ sceVu0FVECTOR avDiffuse[3];
  /* 0x60 */ sceVu0FVECTOR avSpecular[3];
};

struct G3DVU1COLOR
{// 0x1b0
  /* 0x000 */ G3DVU1COLOR_DIRECTIONAL dir;
  /* 0x090 */ G3DVU1COLOR_POINT point;
  /* 0x120 */ G3DVU1COLOR_SPOT spot;
};

struct G3DVU1MEMLAYOUT_DIRECT
{// 0x6e0
  /* 0x000 */ sceVu0FVECTOR v0001;
  /* 0x010 */ sceVu0FVECTOR v1111;
  /* 0x020 */ sceVu0FMATRIX matLocalWorld;
  /* 0x060 */ sceVu0FMATRIX matLocalWorld1;
  /* 0x0a0 */ sceVu0FMATRIX matCamera;
  /* 0x0e0 */ sceVu0FMATRIX matWorldScreen;
  /* 0x120 */ sceVu0FMATRIX matWorldClip;
  /* 0x160 */ sceVu0FVECTOR vVertex;
  /* 0x170 */ sceVu0FVECTOR vNormal;
  /* 0x180 */ sceVu0FVECTOR avAmbientDirectional[3];
  /* 0x1b0 */ sceVu0FVECTOR avDiffuseDirectional[3];
  /* 0x1e0 */ sceVu0FVECTOR avSpecularDirectional[3];
  /* 0x210 */ sceVu0FVECTOR avAmbientPoint[3];
  /* 0x240 */ sceVu0FVECTOR avDiffusePoint[3];
  /* 0x270 */ sceVu0FVECTOR avSpecularPoint[3];
  /* 0x2a0 */ sceVu0FVECTOR avAmbientSpot[3];
  /* 0x2d0 */ sceVu0FVECTOR avDiffuseSpot[3];
  /* 0x300 */ sceVu0FVECTOR avSpecularSpot[3];
  /* 0x330 */ G3DVU1LIGHTSTATUS lightstatus;
  /* 0x340 */ sceVu0FVECTOR avDirectionDirectional[3];
  /* 0x370 */ sceVu0FVECTOR avPositionPoint[3];
  /* 0x3a0 */ sceVu0FVECTOR vMaxRangePoint;
  /* 0x3b0 */ sceVu0FVECTOR vMax_Min_RangeInversePoint;
  /* 0x3c0 */ sceVu0FVECTOR avPositionSpot[3];
  /* 0x3f0 */ sceVu0FVECTOR avDirectionSpot[3];
  /* 0x420 */ sceVu0FVECTOR vMaxRangeSpot;
  /* 0x430 */ sceVu0FVECTOR vMax_Min_RangeInverseSpot;
  /* 0x440 */ sceVu0FVECTOR vCosOutsideSpot;
  /* 0x450 */ sceVu0FVECTOR vCosIn_Out_InverseSpot;
  /* 0x460 */ sceVu0FVECTOR vAmbientMaterial;
  /* 0x470 */ sceVu0FVECTOR vDiffuseMaterial;
  /* 0x480 */ sceVu0FVECTOR vSpecularMaterial;
  /* 0x490 */ sceVu0FVECTOR vEmissiveMaterial;
  /* 0x4a0 */ sceVu0FVECTOR vAlphaMaterial;
  /* 0x4b0 */ sceVu0FVECTOR vAmbientGlobal;
  /* 0x4c0 */ sceVu0FVECTOR vTemp;
  /* 0x4d0 */ sceVu0IVECTOR ivFogColor;
  /* 0x4e0 */ G3DVU1FOG Fog;
  /* 0x4f0 */ void *gtPrimitve;
  /* 0x500 */ void *gtVertexBuffer;
  /* 0x510 */ sceVu0FVECTOR vAmbientCalculated;
  /* 0x520 */ sceVu0FVECTOR vMisc;
  /* 0x530 */ sceVu0FVECTOR avAmbientDirectionalOrigin[3];
  /* 0x560 */ sceVu0FVECTOR avDiffuseDirectionalOrigin[3];
  /* 0x590 */ sceVu0FVECTOR avSpecularDirectionalOrigin[3];
  /* 0x5c0 */ sceVu0FVECTOR avAmbientPointOrigin[3];
  /* 0x5f0 */ sceVu0FVECTOR avDiffusePointOrigin[3];
  /* 0x620 */ sceVu0FVECTOR avSpecularPointOrigin[3];
  /* 0x650 */ sceVu0FVECTOR avAmbientSpotOrigin[3];
  /* 0x680 */ sceVu0FVECTOR avDiffuseSpotOrigin[3];
  /* 0x6b0 */ sceVu0FVECTOR avSpecularSpotOrigin[3];
};

struct G3DVU1MEMLAYOUT_PACKED
{// 0x6e0
  /* 0x000 */ G3DVU1CONSTANT Constant;
  /* 0x020 */ G3DVU1TRANSFORM Transform;
  /* 0x180 */ G3DVU1COLOR Color;
  /* 0x330 */ G3DVU1LIGHT Light;
  /* 0x460 */ G3DMATERIAL Material;
  /* 0x4b0 */ G3DVU1GLOBAL Global;
  /* 0x510 */ G3DVU1CALCULATED Calc;
  /* 0x530 */ G3DVU1COLOR ColorOrigin;
};

union G3DVU1MEMLAYOUT
{// 0x6e0
  /* 0x000 */ G3DVU1MEMLAYOUT_PACKED Packed;
  /* 0x000 */ G3DVU1MEMLAYOUT_DIRECT Direct;
};

struct IG3DResource
{// 0x8
 protected:
  /* 0x0 */ G3DRESOURCETYPE m_Type;

 public:
  IG3DResource &operator=(const IG3DResource &rval);
  IG3DResource();
  //static void* operator new(int siz);
  static void operator delete(void *);
  ~IG3DResource();
  //virtual IG3DResource(IG3DResource*, int, void);
  G3DRESOURCETYPE GetType();
  virtual void PreLoad();
};

struct CTexture : /* 0x00 */ IG3DResource
{// 0x90
 private:
  /* 0x10 */ void *m_gsLoadImage;
  /* 0x70 */ G3DTEXTUREDATA m_TextureData;
  /* 0x80 */ unsigned char *m_pbyData;
  /* 0x84 */ int m_iSize;

 public:
  CTexture &operator=(const CTexture &rval);
  CTexture();
  ~CTexture();
  //virtual CTexture(CTexture*, int, void);
  int Create();
  G3DTEXTUREDATA &GetTextureDataRef();
  unsigned char *GetImage();
  int GetSize();
  /* vtable[2] */ virtual void PreLoad();
};

struct IG3DVertexBuffer;// Forward declared but no known
struct IG3DIndexBuffer;

struct G3DRESOURCE
{// 0xc
  /* 0x0 */ CTexture *apTexture[1];
  /* 0x4 */ IG3DVertexBuffer *pVertexBuffer;
  /* 0x8 */ IG3DIndexBuffer *pIndexBuffer;
};

struct G3DCOREOBJECT
{// 0x1170
  /* 0x0000 */ unsigned int auiRenderState[8];
  /* 0x0020 */ unsigned int auiGlobalState[2];
  /* 0x0030 */ _LIGHTDATA aLightData[9];
  /* 0x04b0 */ float vAmbient[4];
  /* 0x04c0 */ G3DMATERIAL Material;
  /* 0x0510 */ sceVu0FMATRIX amatTransform[5];
  /* 0x0650 */ G3DVIEWPORT Viewport;
  /* 0x0670 */ G3DWINDOW Window;
  /* 0x0680 */ G3DRESOURCE Resource;
  /* 0x0690 */ G3DVU1MEMLAYOUT Vu1Mem;
  /* 0x0d70 */ G3DGSREGISTERLAYOUT GsRegister;
};

struct G3DCREATIONDATA
{// 0x4
  /* 0x0 */ G3DCOREOBJECT *pObj;
};

#endif//ROUGETSU_G3D_TYPES_H
