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

#ifndef _chains_vipSingleCameraAnalytics2_H_
#define _chains_vipSingleCameraAnalytics2_H_

#include <include/link_api/system.h>
#include <include/link_api/captureLink.h>
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
       UInt32    CaptureLinkID;
       UInt32    Dup_captureLinkID;
       UInt32    IPCOut_IPU1_0_EVE1_4LinkID;
       UInt32    IPCIn_EVE1_IPU1_0_2LinkID;
       UInt32    Alg_SparseOpticalFlowLinkID;
       UInt32    IPCOut_EVE1_DSP2_2LinkID;
       UInt32    IPCIn_DSP2_EVE1_3LinkID;
       UInt32    Dup_sofLinkID;
       UInt32    Alg_SfmLinkID;
       UInt32    Dup_sfmLinkID;
       UInt32    IPCOut_IPU1_0_EVE1_1LinkID;
       UInt32    IPCIn_EVE1_IPU1_0_0LinkID;
       UInt32    Alg_ImagePreProcessLinkID;
       UInt32    IPCOut_EVE1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_EVE1_0LinkID;
       UInt32    Alg_ImgPyramidLinkID;
       UInt32    Dup_imgpmdLinkID;
       UInt32    IPCOut_IPU1_0_DSP2_3LinkID;
       UInt32    IPCIn_DSP2_IPU1_0_2LinkID;
       UInt32    Dup_imgpmd_dspLinkID;
       UInt32    Alg_LaneDetectLinkID;
       UInt32    IPCOut_IPU1_0_DSP2_0LinkID;
       UInt32    IPCIn_DSP2_IPU1_0_0LinkID;
       UInt32    Dup_dspLinkID;
       UInt32    Alg_ClrLinkID;
       UInt32    IPCOut_IPU1_0_EVE1_2LinkID;
       UInt32    IPCIn_EVE1_IPU1_0_1LinkID;
       UInt32    Alg_FPComputeLinkID;
       UInt32    IPCOut_EVE1_DSP1_1LinkID;
       UInt32    IPCIn_DSP1_EVE1_0LinkID;
       UInt32    Alg_ObjectDetectionLinkID;
       UInt32    IPCOut_DSP1_DSP2_0LinkID;
       UInt32    IPCIn_DSP2_DSP1_1LinkID;
       UInt32    Merge_objectDetectLinkID;
       UInt32    Sync_objectDetectLinkID;
       UInt32    Alg_ObjectClassificationLinkID;
       UInt32    Merge_FcwLinkID;
       UInt32    Sync_FcwLinkID;
       UInt32    Alg_FcwLinkID;
       UInt32    Merge_algLinkID;
       UInt32    Sync_algLinkID;
       UInt32    Alg_ObjectDrawLinkID;
       UInt32    IPCOut_DSP2_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_DSP2_1LinkID;
       UInt32    Display_VideoLinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       CaptureLink_CreateParams                CapturePrm;
       DupLink_CreateParams                    Dup_capturePrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE1_4Prm;
       IpcLink_CreateParams                    IPCIn_EVE1_IPU1_0_2Prm;
       AlgorithmLink_SparseOpticalFlowCreateParams Alg_SparseOpticalFlowPrm;
       IpcLink_CreateParams                    IPCOut_EVE1_DSP2_2Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_EVE1_3Prm;
       DupLink_CreateParams                    Dup_sofPrm;
       AlgorithmLink_SfmCreateParams           Alg_SfmPrm;
       DupLink_CreateParams                    Dup_sfmPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE1_1Prm;
       IpcLink_CreateParams                    IPCIn_EVE1_IPU1_0_0Prm;
       AlgorithmLink_ImagePreProcessCreateParams Alg_ImagePreProcessPrm;
       IpcLink_CreateParams                    IPCOut_EVE1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_EVE1_0Prm;
       AlgorithmLink_ImgPyramidCreateParams    Alg_ImgPyramidPrm;
       DupLink_CreateParams                    Dup_imgpmdPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP2_3Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_IPU1_0_2Prm;
       DupLink_CreateParams                    Dup_imgpmd_dspPrm;
       AlgorithmLink_LaneDetectCreateParams    Alg_LaneDetectPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP2_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_IPU1_0_0Prm;
       DupLink_CreateParams                    Dup_dspPrm;
       AlgorithmLink_ClrCreateParams           Alg_ClrPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_EVE1_2Prm;
       IpcLink_CreateParams                    IPCIn_EVE1_IPU1_0_1Prm;
       AlgorithmLink_FPComputeCreateParams     Alg_FPComputePrm;
       IpcLink_CreateParams                    IPCOut_EVE1_DSP1_1Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_EVE1_0Prm;
       AlgorithmLink_ObjectDetectionCreateParams Alg_ObjectDetectionPrm;
       IpcLink_CreateParams                    IPCOut_DSP1_DSP2_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP2_DSP1_1Prm;
       MergeLink_CreateParams                  Merge_objectDetectPrm;
       SyncLink_CreateParams                   Sync_objectDetectPrm;
       AlgorithmLink_ObjectClassificationCreateParams Alg_ObjectClassificationPrm;
       MergeLink_CreateParams                  Merge_FcwPrm;
       SyncLink_CreateParams                   Sync_FcwPrm;
       AlgorithmLink_FcwCreateParams           Alg_FcwPrm;
       MergeLink_CreateParams                  Merge_algPrm;
       SyncLink_CreateParams                   Sync_algPrm;
       AlgorithmLink_ObjectDrawCreateParams    Alg_ObjectDrawPrm;
       IpcLink_CreateParams                    IPCOut_DSP2_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP2_1Prm;
       DisplayLink_CreateParams                Display_VideoPrm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_vipSingleCameraAnalytics2Obj;

Void chains_vipSingleCameraAnalytics2_SetLinkId(chains_vipSingleCameraAnalytics2Obj *pObj);

Void chains_vipSingleCameraAnalytics2_ResetLinkPrms(chains_vipSingleCameraAnalytics2Obj *pObj);

Void chains_vipSingleCameraAnalytics2_SetPrms(chains_vipSingleCameraAnalytics2Obj *pObj);

Void chains_vipSingleCameraAnalytics2_ConnectLinks(chains_vipSingleCameraAnalytics2Obj *pObj);

Int32 chains_vipSingleCameraAnalytics2_Create(chains_vipSingleCameraAnalytics2Obj *pObj, Void *appObj);

Int32 chains_vipSingleCameraAnalytics2_Start(chains_vipSingleCameraAnalytics2Obj *pObj);

Int32 chains_vipSingleCameraAnalytics2_Stop(chains_vipSingleCameraAnalytics2Obj *pObj);

Int32 chains_vipSingleCameraAnalytics2_Delete(chains_vipSingleCameraAnalytics2Obj *pObj);

Void chains_vipSingleCameraAnalytics2_printBufferStatistics(chains_vipSingleCameraAnalytics2Obj *pObj);

Void chains_vipSingleCameraAnalytics2_printStatistics(chains_vipSingleCameraAnalytics2Obj *pObj);

Void chains_vipSingleCameraAnalytics2_SetAppPrms(chains_vipSingleCameraAnalytics2Obj *pObj, Void *appObj);

#endif /* _chains_vipSingleCameraAnalytics2_H_ */