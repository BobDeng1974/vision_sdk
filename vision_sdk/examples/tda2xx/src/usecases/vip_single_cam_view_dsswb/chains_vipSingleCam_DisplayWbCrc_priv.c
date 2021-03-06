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
#include "chains_vipSingleCam_DisplayWbCrc_priv.h"
Void chains_vipSingleCam_DisplayWbCrc_SetLinkId(chains_vipSingleCam_DisplayWbCrcObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE_0;
       pObj->Display_VideoLinkID            = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_1;
       pObj->Capture_dsswbLinkID            = SYSTEM_LINK_ID_CAPTURE_1;
       pObj->Alg_CrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_ALG_0);
}

Void chains_vipSingleCam_DisplayWbCrc_ResetLinkPrms(chains_vipSingleCam_DisplayWbCrcObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       DisplayLink_CreateParams_Init(&pObj->Display_VideoPrm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);
       CaptureLink_CreateParams_Init(&pObj->Capture_dsswbPrm);
       AlgorithmLink_Crc_Init(&pObj->Alg_CrcPrm);
}

Void chains_vipSingleCam_DisplayWbCrc_SetPrms(chains_vipSingleCam_DisplayWbCrcObj *pObj){
       (pObj->Alg_CrcPrm).baseClassCreate.size  = sizeof(AlgorithmLink_CrcCreateParams);
       (pObj->Alg_CrcPrm).baseClassCreate.algId  = ALGORITHM_LINK_IPU_ALG_HW_CRC;
}

Void chains_vipSingleCam_DisplayWbCrc_ConnectLinks(chains_vipSingleCam_DisplayWbCrcObj *pObj){

       //Capture -> Display_Video
       pObj->CapturePrm.outQueParams.nextLink = pObj->Display_VideoLinkID;
       pObj->Display_VideoPrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->Display_VideoPrm.inQueParams.prevLinkQueId = 0;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;

       //Capture_dsswb -> Alg_Crc
       pObj->Capture_dsswbPrm.outQueParams.nextLink = pObj->Alg_CrcLinkID;
       pObj->Alg_CrcPrm.inQueParams.prevLinkId = pObj->Capture_dsswbLinkID;
       pObj->Alg_CrcPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_vipSingleCam_DisplayWbCrc_Create(chains_vipSingleCam_DisplayWbCrcObj *pObj, Void *appObj){

       Int32 status;

       chains_vipSingleCam_DisplayWbCrc_SetLinkId(pObj);
       chains_vipSingleCam_DisplayWbCrc_ResetLinkPrms(pObj);

       chains_vipSingleCam_DisplayWbCrc_SetPrms(pObj);
       chains_vipSingleCam_DisplayWbCrc_SetAppPrms(pObj, appObj);

       chains_vipSingleCam_DisplayWbCrc_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_VideoLinkID, &pObj->Display_VideoPrm, sizeof(pObj->Display_VideoPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Capture_dsswbLinkID, &pObj->Capture_dsswbPrm, sizeof(pObj->Capture_dsswbPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_CrcLinkID, &pObj->Alg_CrcPrm, sizeof(pObj->Alg_CrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCam_DisplayWbCrc_Start(chains_vipSingleCam_DisplayWbCrcObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Alg_CrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Capture_dsswbLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_VideoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCam_DisplayWbCrc_Stop(chains_vipSingleCam_DisplayWbCrcObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Alg_CrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Capture_dsswbLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_VideoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCam_DisplayWbCrc_Delete(chains_vipSingleCam_DisplayWbCrcObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Alg_CrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Capture_dsswbLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_VideoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_vipSingleCam_DisplayWbCrc_printBufferStatistics(chains_vipSingleCam_DisplayWbCrcObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->Display_VideoLinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       System_linkPrintBufferStatistics(pObj->Capture_dsswbLinkID);
       System_linkPrintBufferStatistics(pObj->Alg_CrcLinkID);
       Task_sleep(500);
}

Void chains_vipSingleCam_DisplayWbCrc_printStatistics(chains_vipSingleCam_DisplayWbCrcObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->Display_VideoLinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       System_linkPrintStatistics(pObj->Capture_dsswbLinkID);
       System_linkPrintStatistics(pObj->Alg_CrcLinkID);
       Task_sleep(500);
}

