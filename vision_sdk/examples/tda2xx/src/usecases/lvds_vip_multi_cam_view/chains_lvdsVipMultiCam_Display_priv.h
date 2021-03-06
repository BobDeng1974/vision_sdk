/*
*******************************************************************************
*
* Copyright (C) 2014 Texas Instruments Incorporated - http://www.ti.com/
* ALL RIGHTS RESERVED
*
*******************************************************************************
*/

/*
*******************************************************************************
*
* IMPORTANT NOTE:
*  This file is AUTO-GENERATED by Vision SDK use case generation tool
*
*******************************************************************************
*/

#ifndef _chains_lvdsVipMultiCam_Display_H_
#define _chains_lvdsVipMultiCam_Display_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/dupLink.h>
#include <include/link_api/vpeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_dmaSwMs.h>
#include <include/link_api/mergeLink.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

typedef struct {
       UInt32    CaptureLinkID;
       UInt32    DupLinkID;
       UInt32    VPELinkID;
       UInt32    SyncLinkID;
       UInt32    Alg_DmaSwMsLinkID;
       UInt32    MergeLinkID;
       UInt32    Display_videoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       DupLink_CreateParams                    DupPrm;
       VpeLink_CreateParams                    VPEPrm;
       SyncLink_CreateParams                   SyncPrm;
       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMsPrm;
       MergeLink_CreateParams                  MergePrm;
       DisplayLink_CreateParams                Display_videoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_lvdsVipMultiCam_DisplayObj;

Void chains_lvdsVipMultiCam_Display_SetLinkId(chains_lvdsVipMultiCam_DisplayObj *pObj);

Void chains_lvdsVipMultiCam_Display_ResetLinkPrms(chains_lvdsVipMultiCam_DisplayObj *pObj);

Void chains_lvdsVipMultiCam_Display_SetPrms(chains_lvdsVipMultiCam_DisplayObj *pObj);

Void chains_lvdsVipMultiCam_Display_ConnectLinks(chains_lvdsVipMultiCam_DisplayObj *pObj);

Int32 chains_lvdsVipMultiCam_Display_Create(chains_lvdsVipMultiCam_DisplayObj *pObj, Void *appObj);

Int32 chains_lvdsVipMultiCam_Display_Start(chains_lvdsVipMultiCam_DisplayObj *pObj);

Int32 chains_lvdsVipMultiCam_Display_Stop(chains_lvdsVipMultiCam_DisplayObj *pObj);

Int32 chains_lvdsVipMultiCam_Display_Delete(chains_lvdsVipMultiCam_DisplayObj *pObj);

Void chains_lvdsVipMultiCam_Display_printBufferStatistics(chains_lvdsVipMultiCam_DisplayObj *pObj);

Void chains_lvdsVipMultiCam_Display_printStatistics(chains_lvdsVipMultiCam_DisplayObj *pObj);

Void chains_lvdsVipMultiCam_Display_SetAppPrms(chains_lvdsVipMultiCam_DisplayObj *pObj, Void *appObj);

#endif /* _chains_lvdsVipMultiCam_Display_H_ */
