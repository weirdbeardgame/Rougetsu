#ifndef ROUGETSU_PLYR_MDL_H
#define ROUGETSU_PLYR_MDL_H

#include "../graph3d/sgd_types.h"

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

extern int plyr_neck_flg;
extern int ltd_mode;
extern int same_priority_count;
extern int plyr_neck_no_registered_cnt;

extern LOOK_TARGET_PRIORITY_MIO plyr_neck_now_priority;
extern LOOK_TARGET_PRIORITY_MIO pre_priority;

void SetPlyrNeckFlg(int flg);
void PlyrNeckInit();

#endif