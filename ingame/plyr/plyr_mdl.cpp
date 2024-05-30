#include "plyr_mdl.h"
#include "../../Graphics/graph3d/gra3d.h"
#include "../../Graphics/obj_draw_ctrl.h"

void SetPlyrNeckFlg(int flg)
{
  plyr_neck_flg = flg;
}

static void PlyrNeckFrameInit()
{
  plyr_neck_now_priority = LTP_MIO_LEAST;
  return;
}

static void PlyrNeckInit()
{
  SetPlyrNeckFlg(1);
  ltd_mode = 0;
  pre_priority = LTP_MIO_LEAST;
  same_priority_count = 0;
  plyr_neck_no_registered_cnt = 0;
  PlyrNeckFrameInit();
  return;
}

void plyr_mdlInit()
{
  plyr_mdl_req_save.mMdlNo = GetPlyrMdlNo();
  plyr_mdl_req_save.mBdNo = 0xcfd;
  plyr_mdl_req_save.mAnmNo = 0;
  plyr_mdl_req_save.mSmdlNo = 0x10;
  PlyrNeckInit();
  plyr_data.InitializeIn();

  plyr_data.plyr_init_ok = 0;
  plyr_data.plyr_req_other_mdl = 0;
  return;
}

/*void DrawGirl(void)
{
  float work_amb[4];
  float tgirlbox[8][4];

  if (!IsReadyPlyrMdl() || !GetPlyrDrawFLG())
  {
    return;
  }
  if (plyr_data.IsLocked())
  {
    return;
  }

  gra3dLightEnablePush();

  // inlined from g3dxVu0.h @ line 134
  //GetAmbientRef(work_amb);

  HeaderSection *hs = plyr_data.GetAniCtrl()->base_p;

  charbbGet(tgirlbox, plyr_data.GetAniCtrl(), hs->coordp->matCoord);
  GRA3DEMULATIONLIGHTDATACREATIONDATA *pData =
      _GetEmulationLightdataCreationDataRef();

  if (CheckModelBoundingBox(tgirlbox))
  {
    playerSetLight(plyr_wrk.bwp, pData);

    int iAlpha;

    if (PlayerModeIsFinder())
    {
      iAlpha = 0x80;
    }
    else
    {
      iAlpha = playerCalcAlpha(plyr_data.GetAniCtrl());
    }

    plyr_data.AccessoryDraw(iAlpha);

    if (gra3dIsMonotoneDrawEnable())
    {
      SendEneVramMono(plyr_data.GetAniCtrl()->mdl_p, 0x2bc0,
                      plyr_data.GetAniCtrl()->bwc_p);
    }
    else
    {
      SendEneVram(plyr_data.GetAniCtrl()->mdl_p, 0x2bc0);
    }

    ManmdlSetAlpha(hs, (u_char) iAlpha);
    _gra3dDrawSGD((SGDFILEHEADER *) hs, SRT_REALTIME, nullptr, -1);
    DrawGirlSubObj(plyr_data.GetAniCtrl()->mpk_p, (u_char) iAlpha);

    if (plyr_wrk.cmn_wrk.st.sta & 0x8000 && !GetSynchroModeFlg()
        && (plyr_data.GetAniCtrl()->anm.playnum < 0x18
            || 0x39 < plyr_data.GetAniCtrl()->anm.playnum))
    {
      HeaderSection *item =
          (HeaderSection *) GetItemSgdAddr((int *) plyr_data.plyr_light_mdl_p);
      SendItemVram((u_int *) plyr_data.plyr_light_mdl_p, 0);
      ManmdlSetAlpha(item, plyr_data.plyr_light_alpha);
      ManItemSGDDraw(item, plyr_data.GetAniCtrl(), 1);
    }

    if (plyr_data.GetAniCtrl()->anm.playnum == 0x30
        || plyr_data.GetAniCtrl()->anm.playnum == 0x31)
    {
      HeaderSection *item =
          (HeaderSection *) GetItemSgdAddr((int *) plyr_data.plyr_cam_mdl_p);
      SendItemVram((u_int *) plyr_data.plyr_cam_mdl_p, 0);
      ManmdlSetAlpha(item, plyr_data.plyr_cam_alpha);
      ManItemSGDDraw(item, plyr_data.GetAniCtrl(), 0);
    }
    _SetPREVIOUSTRI2PRIM(nullptr);
  }

  gra3dSetAmbient(work_amb);
  gra3dLightEnablePop();
  gra3dApplyLight();
}*/