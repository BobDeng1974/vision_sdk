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

#ifndef _chains_vipSingleCam_DisplayWbCrc_H_
#define _chains_vipSingleCam_DisplayWbCrc_H_

#include <include/link_api/system.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>
#include <include/link_api/captureLink.h>
#include <include/link_api/algorithmLink_crc.h>

typedef struct {
       UInt32    CaptureLinkID;
       UInt32    Display_VideoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;
       UInt32    Capture_dsswbLinkID;
       UInt32    Alg_CrcLinkID;

       CaptureLink_CreateParams                CapturePrm;
       DisplayLink_CreateParams                Display_VideoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
       CaptureLink_CreateParams                Capture_dsswbPrm;
       AlgorithmLink_CrcCreateParams           Alg_CrcPrm;
} chains_vipSingleCam_DisplayWbCrcObj;

Void chains_vipSingleCam_DisplayWbCrc_SetLinkId(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Void chains_vipSingleCam_DisplayWbCrc_ResetLinkPrms(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Void chains_vipSingleCam_DisplayWbCrc_SetPrms(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Void chains_vipSingleCam_DisplayWbCrc_ConnectLinks(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Int32 chains_vipSingleCam_DisplayWbCrc_Create(chains_vipSingleCam_DisplayWbCrcObj *pObj, Void *appObj);

Int32 chains_vipSingleCam_DisplayWbCrc_Start(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Int32 chains_vipSingleCam_DisplayWbCrc_Stop(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Int32 chains_vipSingleCam_DisplayWbCrc_Delete(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Void chains_vipSingleCam_DisplayWbCrc_printBufferStatistics(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Void chains_vipSingleCam_DisplayWbCrc_printStatistics(chains_vipSingleCam_DisplayWbCrcObj *pObj);

Void chains_vipSingleCam_DisplayWbCrc_SetAppPrms(chains_vipSingleCam_DisplayWbCrcObj *pObj, Void *appObj);

#endif /* _chains_vipSingleCam_DisplayWbCrc_H_ */