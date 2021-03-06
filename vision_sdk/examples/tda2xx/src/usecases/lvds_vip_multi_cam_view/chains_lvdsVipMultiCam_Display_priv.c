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
#include "chains_lvdsVipMultiCam_Display_priv.h"
Void chains_lvdsVipMultiCam_Display_SetLinkId(chains_lvdsVipMultiCam_DisplayObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE_0;
       pObj->DupLinkID                      = IPU1_0_LINK (SYSTEM_LINK_ID_DUP_0);
       pObj->VPELinkID                      = SYSTEM_LINK_ID_VPE_0;
       pObj->SyncLinkID                     = IPU1_0_LINK (SYSTEM_LINK_ID_SYNC_0);
       pObj->Alg_DmaSwMsLinkID              = IPU1_0_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->MergeLinkID                    = IPU1_0_LINK (SYSTEM_LINK_ID_MERGE_0);
       pObj->Display_videoLinkID            = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_1;
}

Void chains_lvdsVipMultiCam_Display_ResetLinkPrms(chains_lvdsVipMultiCam_DisplayObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       DupLink_CreateParams_Init(&pObj->DupPrm);
       VpeLink_CreateParams_Init(&pObj->VPEPrm);
       SyncLink_CreateParams_Init(&pObj->SyncPrm);
       AlgorithmLink_DmaSwMsCreateParams_Init(&pObj->Alg_DmaSwMsPrm);
       MergeLink_CreateParams_Init(&pObj->MergePrm);
       DisplayLink_CreateParams_Init(&pObj->Display_videoPrm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);
}

Void chains_lvdsVipMultiCam_Display_SetPrms(chains_lvdsVipMultiCam_DisplayObj *pObj){
       (pObj->DupPrm).numOutQue = 2;
       (pObj->Alg_DmaSwMsPrm).baseClassCreate.size  = sizeof(AlgorithmLink_DmaSwMsCreateParams);
       (pObj->Alg_DmaSwMsPrm).baseClassCreate.algId  = ALGORITHM_LINK_IPU_ALG_DMA_SWMS;
       (pObj->MergePrm).numInQue = 2;
}

Void chains_lvdsVipMultiCam_Display_ConnectLinks(chains_lvdsVipMultiCam_DisplayObj *pObj){

       //Capture -> Dup
       pObj->CapturePrm.outQueParams.nextLink = pObj->DupLinkID;
       pObj->DupPrm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->DupPrm.inQueParams.prevLinkQueId = 0;

       //Dup -> VPE
       pObj->DupPrm.outQueParams[0].nextLink = pObj->VPELinkID;
       pObj->VPEPrm.inQueParams.prevLinkId = pObj->DupLinkID;
       pObj->VPEPrm.inQueParams.prevLinkQueId = 0;

       //Dup -> Merge
       pObj->DupPrm.outQueParams[1].nextLink = pObj->MergeLinkID;
       pObj->MergePrm.inQueParams[1].prevLinkId = pObj->DupLinkID;
       pObj->MergePrm.inQueParams[1].prevLinkQueId = 1;

       //VPE -> Sync
       pObj->VPEPrm.outQueParams[0].nextLink = pObj->SyncLinkID;
       pObj->SyncPrm.inQueParams.prevLinkId = pObj->VPELinkID;
       pObj->SyncPrm.inQueParams.prevLinkQueId = 0;

       //Sync -> Alg_DmaSwMs
       pObj->SyncPrm.outQueParams.nextLink = pObj->Alg_DmaSwMsLinkID;
       pObj->Alg_DmaSwMsPrm.inQueParams.prevLinkId = pObj->SyncLinkID;
       pObj->Alg_DmaSwMsPrm.inQueParams.prevLinkQueId = 0;

       //Alg_DmaSwMs -> Merge
       pObj->Alg_DmaSwMsPrm.outQueParams.nextLink = pObj->MergeLinkID;
       pObj->MergePrm.inQueParams[0].prevLinkId = pObj->Alg_DmaSwMsLinkID;
       pObj->MergePrm.inQueParams[0].prevLinkQueId = 0;

       //Merge -> Display_video
       pObj->MergePrm.outQueParams.nextLink = pObj->Display_videoLinkID;
       pObj->Display_videoPrm.inQueParams.prevLinkId = pObj->MergeLinkID;
       pObj->Display_videoPrm.inQueParams.prevLinkQueId = 0;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_lvdsVipMultiCam_Display_Create(chains_lvdsVipMultiCam_DisplayObj *pObj, Void *appObj){

       Int32 status;

       chains_lvdsVipMultiCam_Display_SetLinkId(pObj);
       chains_lvdsVipMultiCam_Display_ResetLinkPrms(pObj);

       chains_lvdsVipMultiCam_Display_SetPrms(pObj);
       chains_lvdsVipMultiCam_Display_SetAppPrms(pObj, appObj);

       chains_lvdsVipMultiCam_Display_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->DupLinkID, &pObj->DupPrm, sizeof(pObj->DupPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->VPELinkID, &pObj->VPEPrm, sizeof(pObj->VPEPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->SyncLinkID, &pObj->SyncPrm, sizeof(pObj->SyncPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_DmaSwMsLinkID, &pObj->Alg_DmaSwMsPrm, sizeof(pObj->Alg_DmaSwMsPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->MergeLinkID, &pObj->MergePrm, sizeof(pObj->MergePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_videoLinkID, &pObj->Display_videoPrm, sizeof(pObj->Display_videoPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipMultiCam_Display_Start(chains_lvdsVipMultiCam_DisplayObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_videoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->MergeLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_DmaSwMsLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->VPELinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->DupLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipMultiCam_Display_Stop(chains_lvdsVipMultiCam_DisplayObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_videoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->MergeLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_DmaSwMsLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->VPELinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->DupLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_lvdsVipMultiCam_Display_Delete(chains_lvdsVipMultiCam_DisplayObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_videoLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->MergeLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_DmaSwMsLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->SyncLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->VPELinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->DupLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_lvdsVipMultiCam_Display_printBufferStatistics(chains_lvdsVipMultiCam_DisplayObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->DupLinkID);
       System_linkPrintBufferStatistics(pObj->VPELinkID);
       System_linkPrintBufferStatistics(pObj->SyncLinkID);
       System_linkPrintBufferStatistics(pObj->Alg_DmaSwMsLinkID);
       System_linkPrintBufferStatistics(pObj->MergeLinkID);
       System_linkPrintBufferStatistics(pObj->Display_videoLinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

Void chains_lvdsVipMultiCam_Display_printStatistics(chains_lvdsVipMultiCam_DisplayObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->DupLinkID);
       System_linkPrintStatistics(pObj->VPELinkID);
       System_linkPrintStatistics(pObj->SyncLinkID);
       System_linkPrintStatistics(pObj->Alg_DmaSwMsLinkID);
       System_linkPrintStatistics(pObj->MergeLinkID);
       System_linkPrintStatistics(pObj->Display_videoLinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

