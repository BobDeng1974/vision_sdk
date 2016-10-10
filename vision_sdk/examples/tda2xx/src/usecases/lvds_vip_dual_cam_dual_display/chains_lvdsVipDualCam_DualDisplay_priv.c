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
#include "chains_lvdsVipDualCam_DualDisplay_priv.h"
Void chains_lvdsVipDualCam_DualDisplay_SetLinkId(chains_lvdsVipDualCam_DualDisplayObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE;
       pObj->Select_CaptureLinkID           = IPU1_0_LINK (SYSTEM_LINK_ID_SELECT_0);
       pObj->Display_HDMILinkID             = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->Display_LCDLinkID              = SYSTEM_LINK_ID_DISPLAY_1;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_2;
}

Void chains_lvdsVipDualCam_DualDisplay_ResetLinkPrms(chains_lvdsVipDualCam_DualDisplayObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       SelectLink_CreateParams_Init(&pObj->Select_CapturePrm);
       DisplayLink_CreateParams_Init(&pObj->Display_HDMIPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_LCDPrm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);
}

Void chains_lvdsVipDualCam_DualDisplay_SetPrms(chains_lvdsVipDualCam_DualDisplayObj *pObj){
       (pObj->Select_CapturePrm).numOutQue = 2;
}

Void chains_lvdsVipDualCam_DualDisplay_ConnectLinks(chains_lvdsVipDualCam_DualDisplayObj *pObj){

       //Capture -> Select_Capture
       pObj->CapturePrm.outQueParams.nextLink = pObj->Select_CaptureLinkID;
       pObj->Select_CapturePrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->Select_CapturePrm.inQueParams.prevLinkQueId = 0;

       //Select_Capture -> Display_LCD
       pObj->Select_CapturePrm.outQueParams[0].nextLink = pObj->Display_LCDLinkID;
       pObj->Display_LCDPrm.inQueParams.prevLinkId = pObj->Select_CaptureLinkID;
       pObj->Display_LCDPrm.inQueParams.prevLinkQueId = 0;

       //Select_Capture -> Display_HDMI
       pObj->Select_CapturePrm.outQueParams[1].nextLink = pObj->Display_HDMILinkID;
       pObj->Display_HDMIPrm.inQueParams.prevLinkId = pObj->Select_CaptureLinkID;
       pObj->Display_HDMIPrm.inQueParams.prevLinkQueId = 1;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_lvdsVipDualCam_DualDisplay_Create(chains_lvdsVipDualCam_DualDisplayObj *pObj, Void *appObj){

       Int32 status;

       chains_lvdsVipDualCam_DualDisplay_SetLinkId(pObj);
       chains_lvdsVipDualCam_DualDisplay_ResetLinkPrms(pObj);

       chains_lvdsVipDualCam_DualDisplay_SetPrms(pObj);
       chains_lvdsVipDualCam_DualDisplay_SetAppPrms(pObj, appObj);

       chains_lvdsVipDualCam_DualDisplay_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Select_CaptureLinkID, &pObj->Select_CapturePrm, sizeof(pObj->Select_CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_HDMILinkID, &pObj->Display_HDMIPrm, sizeof(pObj->Display_HDMIPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_LCDLinkID, &pObj->Display_LCDPrm, sizeof(pObj->Display_LCDPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipDualCam_DualDisplay_Start(chains_lvdsVipDualCam_DualDisplayObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_LCDLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_HDMILinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Select_CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipDualCam_DualDisplay_Stop(chains_lvdsVipDualCam_DualDisplayObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_LCDLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_HDMILinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Select_CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipDualCam_DualDisplay_Delete(chains_lvdsVipDualCam_DualDisplayObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_LCDLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_HDMILinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Select_CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_lvdsVipDualCam_DualDisplay_printBufferStatistics(chains_lvdsVipDualCam_DualDisplayObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->Select_CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->Display_HDMILinkID);
       System_linkPrintBufferStatistics(pObj->Display_LCDLinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

Void chains_lvdsVipDualCam_DualDisplay_printStatistics(chains_lvdsVipDualCam_DualDisplayObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->Select_CaptureLinkID);
       System_linkPrintStatistics(pObj->Display_HDMILinkID);
       System_linkPrintStatistics(pObj->Display_LCDLinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}
