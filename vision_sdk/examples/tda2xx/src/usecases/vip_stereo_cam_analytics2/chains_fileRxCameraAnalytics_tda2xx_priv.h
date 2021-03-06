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

#ifndef _chains_fileRxCameraAnalytics_tda2xx_H_
#define _chains_fileRxCameraAnalytics_tda2xx_H_

#include <include/link_api/system.h>
#include <include/link_api/nullSrcLink.h>
#include <include/link_api/decLink.h>
#include <include/link_api/algorithmLink_sparseOpticalFlow.h>
#include <include/link_api/algorithmLink_sfm.h>
#include <include/link_api/algorithmLink_imagePreProcess.h>
#include <include/link_api/algorithmLink_imgPyramid.h>
#include <include/link_api/algorithmLink_laneDetect.h>
#include <include/link_api/dupLink.h>
#include <include/link_api/algorithmLink_clr.h>
#include <include/link_api/algorithmLink_fpCompute.h>
#include <include/link_api/algorithmLink_objectDetection.h>
#include <include/link_api/algorithmLink_objectClassification.h>
#include <include/link_api/algorithmLink_fcw.h>
#include <include/link_api/mergeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_objectDraw.h>
#include <include/link_api/ipcLink.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

typedef struct {
       UInt32    NullSourceLinkID;
       UInt32    DecodeLinkID;
       UInt32    Dup_captureLinkID;
       UInt32    IPCOut_IPU1_0_EVE1_4LinkID;
       UInt32    IPCIn_EVE1_IPU1_0_0LinkID;
       UInt32    Alg_SparseOpticalFlowLinkID;
       UInt32    IPCOut_EVE1_DSP2_0LinkID;
       UInt32    IPCIn_DSP2_EVE1_3LinkID;
       UInt32    Dup_sofLinkID;
       UInt32    Alg_SfmLinkID;
       UInt32    Dup_sfmLinkID;
       UInt32    IPCOut_IPU1_0_EVE2_1LinkID;
       UInt32    IPCIn_EVE2_IPU1_0_0LinkID;
       UInt32    Alg_ImagePreProcessLinkID;
       UInt32    IPCOut_EVE2_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_EVE2_0LinkID;
       UInt32    Alg_ImgPyramidLinkID;
       UInt32    Dup_imgpmdLinkID;
       UInt32    IPCOut_IPU1_0_DSP2_3LinkID;
       UInt32    IPCIn_DSP2_IPU1_0_2LinkID;
       UInt32    Dup_imgpmd_dspLinkID;
       UInt32    Alg_LaneDetectLinkID;
       UInt32    IPCOut_IPU1_0_DSP2_0LinkID;
       UInt32    IPCIn_DSP2_IPU1_0_0LinkID;
       UInt32    Dup_dspLinkID;
       UInt32    IPCOut_DSP2_DSP1_1LinkID;
       UInt32    IPCIn_DSP1_DSP2_2LinkID;
       UInt32    Alg_ClrLinkID;
       UInt32    IPCOut_DSP1_DSP2_2LinkID;
       UInt32    IPCIn_DSP2_DSP1_5LinkID;
       UInt32    IPCOut_IPU1_0_EVE2_2LinkID;
       UInt32    IPCIn_EVE2_IPU1_0_1LinkID;
       UInt32    Alg_FPComputeLinkID;
       UInt32    IPCOut_EVE2_DSP1_1LinkID;
       UInt32    IPCIn_DSP1_EVE2_0LinkID;
       UInt32    Alg_ObjectDetectionLinkID;
       UInt32    IPCOut_DSP1_DSP2_0LinkID;
       UInt32    IPCIn_DSP2_DSP1_1LinkID;
       UInt32    Merge_objectDetectLinkID;
       UInt32    Sync_objectDetectLinkID;
       UInt32    Alg_ObjectClassificationLinkID;
       UInt32    Merge_FcwLinkID;
       UInt32    IPCOut_DSP2_DSP1_0LinkID;
       UInt32    IPCIn_DSP1_DSP2_1LinkID;
       UInt32    Sync_FcwLinkID;
       UInt32    Alg_FcwLinkID;
       UInt32    IPCOut_DSP1_DSP2_1LinkID;
       UInt32    IPCIn_DSP2_DSP1_4LinkID;
       UInt32    Merge_algLinkID;
       UInt32    Sync_algLinkID;
       UInt32    IPCOut_DSP2_IPU1_1_2LinkID;
       UInt32    IPCIn_IPU1_1_DSP2_0LinkID;
       UInt32    Alg_ObjectDrawLinkID;
       UInt32    IPCOut_IPU1_1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_IPU1_1_1LinkID;
       UInt32    Display_VideoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       NullSrcLink_CreateParams                NullSourcePrm;
       DecLink_CreateParams                    DecodePrm;
       DupLink_CreateParams                    Dup_capturePrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE1_4Prm;
       IpcLink_CreateParams                    IPCIn_EVE1_IPU1_0_0Prm;
       AlgorithmLink_SparseOpticalFlowCreateParams Alg_SparseOpticalFlowPrm;
       IpcLink_CreateParams                    IPCOut_EVE1_DSP2_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_EVE1_3Prm;
       DupLink_CreateParams                    Dup_sofPrm;
       AlgorithmLink_SfmCreateParams           Alg_SfmPrm;
       DupLink_CreateParams                    Dup_sfmPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE2_1Prm;
       IpcLink_CreateParams                    IPCIn_EVE2_IPU1_0_0Prm;
       AlgorithmLink_ImagePreProcessCreateParams Alg_ImagePreProcessPrm;
       IpcLink_CreateParams                    IPCOut_EVE2_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_EVE2_0Prm;
       AlgorithmLink_ImgPyramidCreateParams    Alg_ImgPyramidPrm;
       DupLink_CreateParams                    Dup_imgpmdPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP2_3Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_IPU1_0_2Prm;
       DupLink_CreateParams                    Dup_imgpmd_dspPrm;
       AlgorithmLink_LaneDetectCreateParams    Alg_LaneDetectPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP2_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_IPU1_0_0Prm;
       DupLink_CreateParams                    Dup_dspPrm;
       IpcLink_CreateParams                    IPCOut_DSP2_DSP1_1Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_DSP2_2Prm;
       AlgorithmLink_ClrCreateParams           Alg_ClrPrm;
       IpcLink_CreateParams                    IPCOut_DSP1_DSP2_2Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_DSP1_5Prm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE2_2Prm;
       IpcLink_CreateParams                    IPCIn_EVE2_IPU1_0_1Prm;
       AlgorithmLink_FPComputeCreateParams     Alg_FPComputePrm;
       IpcLink_CreateParams                    IPCOut_EVE2_DSP1_1Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_EVE2_0Prm;
       AlgorithmLink_ObjectDetectionCreateParams Alg_ObjectDetectionPrm;
       IpcLink_CreateParams                    IPCOut_DSP1_DSP2_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_DSP1_1Prm;
       MergeLink_CreateParams                  Merge_objectDetectPrm;
       SyncLink_CreateParams                   Sync_objectDetectPrm;
       AlgorithmLink_ObjectClassificationCreateParams Alg_ObjectClassificationPrm;
       MergeLink_CreateParams                  Merge_FcwPrm;
       IpcLink_CreateParams                    IPCOut_DSP2_DSP1_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_DSP2_1Prm;
       SyncLink_CreateParams                   Sync_FcwPrm;
       AlgorithmLink_FcwCreateParams           Alg_FcwPrm;
       IpcLink_CreateParams                    IPCOut_DSP1_DSP2_1Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_DSP1_4Prm;
       MergeLink_CreateParams                  Merge_algPrm;
       SyncLink_CreateParams                   Sync_algPrm;
       IpcLink_CreateParams                    IPCOut_DSP2_IPU1_1_2Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_1_DSP2_0Prm;
       AlgorithmLink_ObjectDrawCreateParams    Alg_ObjectDrawPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_IPU1_1_1Prm;
       DisplayLink_CreateParams                Display_VideoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_fileRxCameraAnalytics_tda2xxObj;

Void chains_fileRxCameraAnalytics_tda2xx_SetLinkId(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Void chains_fileRxCameraAnalytics_tda2xx_ResetLinkPrms(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Void chains_fileRxCameraAnalytics_tda2xx_SetPrms(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Void chains_fileRxCameraAnalytics_tda2xx_ConnectLinks(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Int32 chains_fileRxCameraAnalytics_tda2xx_Create(chains_fileRxCameraAnalytics_tda2xxObj *pObj, Void *appObj);

Int32 chains_fileRxCameraAnalytics_tda2xx_Start(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Int32 chains_fileRxCameraAnalytics_tda2xx_Stop(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Int32 chains_fileRxCameraAnalytics_tda2xx_Delete(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Void chains_fileRxCameraAnalytics_tda2xx_printBufferStatistics(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Void chains_fileRxCameraAnalytics_tda2xx_printStatistics(chains_fileRxCameraAnalytics_tda2xxObj *pObj);

Void chains_fileRxCameraAnalytics_tda2xx_SetAppPrms(chains_fileRxCameraAnalytics_tda2xxObj *pObj, Void *appObj);

#endif /* _chains_fileRxCameraAnalytics_tda2xx_H_ */
