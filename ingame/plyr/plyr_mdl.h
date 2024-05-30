#ifndef ROUGETSU_PLYR_MDL_H
#define ROUGETSU_PLYR_MDL_H

#include "man_data.h"
#include "sgd_types.h"

enum _LOOK_TARGET_PRIORITY_MIO
{
  LTP_MIO_ATTACK_ENEMY = 0,
  LTP_MIO_ENEMY = 1,
  LTP_MIO_EVENT_OBJ = 2,
  LTP_DUMMY_MIO_TIRED = 3,
  LTP_MIO_SPOT_LIGHT = 4,
  LTP_MIO_KAIDAN = 5,
  LTP_MIO_DOOR = 6,
  LTP_MIO_MAYU = 7,
  LTP_MIO_LEAST = -1
};

typedef _LOOK_TARGET_PRIORITY_MIO LOOK_TARGET_PRIORITY_MIO;

struct PLYR_PLYR_DATA : MAN_DATA
{// 0x3c
  /* 0x30 */ int plyr_cam_mdl_p;
  /* 0x34 */ int plyr_light_mdl_p;
  /* 0x38 */ u_char plyr_cam_alpha;
  /* 0x39 */ u_char plyr_light_alpha;

  //private:
  /* 0x3a:0 */ unsigned int plyr_req_other_mdl : 1;
  /* 0x3a:1 */ unsigned int plyr_init_ok : 1;

 public:
  PLYR_PLYR_DATA &operator=(const PLYR_PLYR_DATA &rval);
  PLYR_PLYR_DATA();
  ~PLYR_PLYR_DATA();
  /* vtable[1] */ virtual int Setup();
  /* vtable[2] */ virtual int IsReady();
  void Release();
  void Initialize();

 private:
  void Init();
};

struct _GAME_COSTUME
{
  int mPlyrMdlNo;
  int mSisterMdlNo;
  int mPlyrAcsNo;
  int mSisterAcsNo;
};
typedef _GAME_COSTUME GAME_COSTUME;

struct MDL_REQ_SAVE
{// 0x10
  /* 0x0 */ int mMdlNo;
  /* 0x4 */ int mAnmNo;
  /* 0x8 */ int mBdNo;
  /* 0xc */ int mSmdlNo;

  MDL_REQ_SAVE &operator=(const MDL_REQ_SAVE &rval);
  MDL_REQ_SAVE();
  ~MDL_REQ_SAVE();
  void Set();
  void SetSave();
};

extern GAME_COSTUME GameCostume;
extern PLYR_PLYR_DATA plyr_data;
extern MDL_REQ_SAVE plyr_mdl_req_save;

extern int plyr_neck_flg;
extern int ltd_mode;
extern int same_priority_count;
extern int plyr_neck_no_registered_cnt;

extern LOOK_TARGET_PRIORITY_MIO plyr_neck_now_priority;
extern LOOK_TARGET_PRIORITY_MIO pre_priority;

void SetPlyrNeckFlg(int flg);
void plyr_mdlInit();
int IsReadyPlyrMdl();
void DrawGirl(int in_mirror);
int GetPlyrMdlNo();
void SetPlyrMdlNo(int iMdlNo);
int GetPlyrAcsNo();
void SetPlyrAcsNo(int iMdlNo);
int GetSisterMdlNo();
void SetSisterMdlNo(int iMdlNo);
int GetSisterAcsNo();
void SetSisterAcsNo(int iAcsNo);

#endif