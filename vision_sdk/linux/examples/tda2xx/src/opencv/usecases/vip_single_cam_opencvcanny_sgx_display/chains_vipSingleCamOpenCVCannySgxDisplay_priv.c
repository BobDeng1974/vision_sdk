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
#include "chains_vipSingleCamOpenCVCannySgxDisplay_priv.h"
Void chains_vipSingleCamOpenCVCannySgxDisplay_SetLinkId(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){
       pObj->CaptureLinkID                  = SYSTEM_LINK_ID_CAPTURE_0;
       pObj->IPCOut_IPU1_0_A15_0_0LinkID    = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_A15_0_IPU1_0_0LinkID     = A15_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Alg_OpenCVCannyLinkID          = A15_0_LINK (SYSTEM_LINK_ID_ALG_0);
       pObj->SgxFrmcpyLinkID                = SYSTEM_LINK_ID_SGXFRMCPY_0;
       pObj->IPCOut_A15_0_IPU1_0_0LinkID    = A15_0_LINK (SYSTEM_LINK_ID_IPC_OUT_0);
       pObj->IPCIn_IPU1_0_A15_0_0LinkID     = IPU1_0_LINK (SYSTEM_LINK_ID_IPC_IN_0);
       pObj->Display_M4LinkID               = SYSTEM_LINK_ID_DISPLAY_0;
       pObj->GrpxSrcLinkID                  = IPU1_0_LINK (SYSTEM_LINK_ID_GRPX_SRC_0);
       pObj->Display_GrpxLinkID             = SYSTEM_LINK_ID_DISPLAY_1;
}

Void chains_vipSingleCamOpenCVCannySgxDisplay_ResetLinkPrms(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){
       CaptureLink_CreateParams_Init(&pObj->CapturePrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_IPU1_0_A15_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_A15_0_IPU1_0_0Prm);
       SgxFrmcpyLink_CreateParams_Init(&pObj->SgxFrmcpyPrm);
       IpcLink_CreateParams_Init(&pObj->IPCOut_A15_0_IPU1_0_0Prm);
       IpcLink_CreateParams_Init(&pObj->IPCIn_IPU1_0_A15_0_0Prm);
       DisplayLink_CreateParams_Init(&pObj->Display_M4Prm);
       GrpxSrcLink_CreateParams_Init(&pObj->GrpxSrcPrm);
       DisplayLink_CreateParams_Init(&pObj->Display_GrpxPrm);
}

Void chains_vipSingleCamOpenCVCannySgxDisplay_SetPrms(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){
       (pObj->Alg_OpenCVCannyPrm).baseClassCreate.size  = sizeof(AlgorithmLink_OpenCVCannyCreateParams);
       (pObj->Alg_OpenCVCannyPrm).baseClassCreate.algId  = ALGORITHM_LINK_A15_ALG_OPENCVCANNY;
}

Void chains_vipSingleCamOpenCVCannySgxDisplay_ConnectLinks(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){

       //Capture -> IPCOut_IPU1_0_A15_0_0
       pObj->CapturePrm.outQueParams.nextLink = pObj->IPCOut_IPU1_0_A15_0_0LinkID;
       pObj->IPCOut_IPU1_0_A15_0_0Prm.inQueParams.prevLinkId = pObj->CaptureLinkID;
       pObj->IPCOut_IPU1_0_A15_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_IPU1_0_A15_0_0 -> IPCIn_A15_0_IPU1_0_0
       pObj->IPCOut_IPU1_0_A15_0_0Prm.outQueParams.nextLink = pObj->IPCIn_A15_0_IPU1_0_0LinkID;
       pObj->IPCIn_A15_0_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_IPU1_0_A15_0_0LinkID;
       pObj->IPCIn_A15_0_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_A15_0_IPU1_0_0 -> Alg_OpenCVCanny
       pObj->IPCIn_A15_0_IPU1_0_0Prm.outQueParams.nextLink = pObj->Alg_OpenCVCannyLinkID;
       pObj->Alg_OpenCVCannyPrm.inQueParams.prevLinkId = pObj->IPCIn_A15_0_IPU1_0_0LinkID;
       pObj->Alg_OpenCVCannyPrm.inQueParams.prevLinkQueId = 0;

       //Alg_OpenCVCanny -> SgxFrmcpy
       pObj->Alg_OpenCVCannyPrm.outQueParams.nextLink = pObj->SgxFrmcpyLinkID;
       pObj->SgxFrmcpyPrm.inQueParams.prevLinkId = pObj->Alg_OpenCVCannyLinkID;
       pObj->SgxFrmcpyPrm.inQueParams.prevLinkQueId = 0;

       //SgxFrmcpy -> IPCOut_A15_0_IPU1_0_0
       pObj->SgxFrmcpyPrm.outQueParams.nextLink = pObj->IPCOut_A15_0_IPU1_0_0LinkID;
       pObj->IPCOut_A15_0_IPU1_0_0Prm.inQueParams.prevLinkId = pObj->SgxFrmcpyLinkID;
       pObj->IPCOut_A15_0_IPU1_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCOut_A15_0_IPU1_0_0 -> IPCIn_IPU1_0_A15_0_0
       pObj->IPCOut_A15_0_IPU1_0_0Prm.outQueParams.nextLink = pObj->IPCIn_IPU1_0_A15_0_0LinkID;
       pObj->IPCIn_IPU1_0_A15_0_0Prm.inQueParams.prevLinkId = pObj->IPCOut_A15_0_IPU1_0_0LinkID;
       pObj->IPCIn_IPU1_0_A15_0_0Prm.inQueParams.prevLinkQueId = 0;

       //IPCIn_IPU1_0_A15_0_0 -> Display_M4
       pObj->IPCIn_IPU1_0_A15_0_0Prm.outQueParams.nextLink = pObj->Display_M4LinkID;
       pObj->Display_M4Prm.inQueParams.prevLinkId = pObj->IPCIn_IPU1_0_A15_0_0LinkID;
       pObj->Display_M4Prm.inQueParams.prevLinkQueId = 0;

       //GrpxSrc -> Display_Grpx
       pObj->GrpxSrcPrm.outQueParams.nextLink = pObj->Display_GrpxLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkId = pObj->GrpxSrcLinkID;
       pObj->Display_GrpxPrm.inQueParams.prevLinkQueId = 0;

}

Int32 chains_vipSingleCamOpenCVCannySgxDisplay_Create(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj, Void *appObj){

       Int32 status;

       chains_vipSingleCamOpenCVCannySgxDisplay_SetLinkId(pObj);
       chains_vipSingleCamOpenCVCannySgxDisplay_ResetLinkPrms(pObj);

       chains_vipSingleCamOpenCVCannySgxDisplay_SetPrms(pObj);
       chains_vipSingleCamOpenCVCannySgxDisplay_SetAppPrms(pObj, appObj);

       chains_vipSingleCamOpenCVCannySgxDisplay_ConnectLinks(pObj);
       status = System_linkCreate(pObj->CaptureLinkID, &pObj->CapturePrm, sizeof(pObj->CapturePrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_IPU1_0_A15_0_0LinkID, &pObj->IPCOut_IPU1_0_A15_0_0Prm, sizeof(pObj->IPCOut_IPU1_0_A15_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_A15_0_IPU1_0_0LinkID, &pObj->IPCIn_A15_0_IPU1_0_0Prm, sizeof(pObj->IPCIn_A15_0_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Alg_OpenCVCannyLinkID, &pObj->Alg_OpenCVCannyPrm, sizeof(pObj->Alg_OpenCVCannyPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->SgxFrmcpyLinkID, &pObj->SgxFrmcpyPrm, sizeof(pObj->SgxFrmcpyPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCOut_A15_0_IPU1_0_0LinkID, &pObj->IPCOut_A15_0_IPU1_0_0Prm, sizeof(pObj->IPCOut_A15_0_IPU1_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->IPCIn_IPU1_0_A15_0_0LinkID, &pObj->IPCIn_IPU1_0_A15_0_0Prm, sizeof(pObj->IPCIn_IPU1_0_A15_0_0Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_M4LinkID, &pObj->Display_M4Prm, sizeof(pObj->Display_M4Prm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->GrpxSrcLinkID, &pObj->GrpxSrcPrm, sizeof(pObj->GrpxSrcPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkCreate(pObj->Display_GrpxLinkID, &pObj->Display_GrpxPrm, sizeof(pObj->Display_GrpxPrm));
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCamOpenCVCannySgxDisplay_Start(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){

       Int32 status;

       status = System_linkStart(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Display_M4LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->SgxFrmcpyLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->Alg_OpenCVCannyLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStart(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCamOpenCVCannySgxDisplay_Stop(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){

       Int32 status;

       status = System_linkStop(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Display_M4LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->SgxFrmcpyLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->Alg_OpenCVCannyLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkStop(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Int32 chains_vipSingleCamOpenCVCannySgxDisplay_Delete(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){

       Int32 status;

       status = System_linkDelete(pObj->Display_GrpxLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->GrpxSrcLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Display_M4LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->SgxFrmcpyLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->Alg_OpenCVCannyLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       status = System_linkDelete(pObj->CaptureLinkID);
       UTILS_assert(status == SYSTEM_LINK_STATUS_SOK);

       return status;
}

Void chains_vipSingleCamOpenCVCannySgxDisplay_printBufferStatistics(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){
       System_linkPrintBufferStatistics(pObj->CaptureLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->Alg_OpenCVCannyLinkID);
       System_linkPrintBufferStatistics(pObj->SgxFrmcpyLinkID);
       System_linkPrintBufferStatistics(pObj->IPCOut_A15_0_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintBufferStatistics(pObj->IPCIn_IPU1_0_A15_0_0LinkID);
       System_linkPrintBufferStatistics(pObj->Display_M4LinkID);
       System_linkPrintBufferStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintBufferStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

Void chains_vipSingleCamOpenCVCannySgxDisplay_printStatistics(chains_vipSingleCamOpenCVCannySgxDisplayObj *pObj){
       System_linkPrintStatistics(pObj->CaptureLinkID);
       System_linkPrintStatistics(pObj->IPCOut_IPU1_0_A15_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_A15_0_IPU1_0_0LinkID);
       System_linkPrintStatistics(pObj->Alg_OpenCVCannyLinkID);
       System_linkPrintStatistics(pObj->SgxFrmcpyLinkID);
       System_linkPrintStatistics(pObj->IPCOut_A15_0_IPU1_0_0LinkID);
       Task_sleep(500);
       System_linkPrintStatistics(pObj->IPCIn_IPU1_0_A15_0_0LinkID);
       System_linkPrintStatistics(pObj->Display_M4LinkID);
       System_linkPrintStatistics(pObj->GrpxSrcLinkID);
       System_linkPrintStatistics(pObj->Display_GrpxLinkID);
       Task_sleep(500);
}

