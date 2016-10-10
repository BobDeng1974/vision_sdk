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

#ifndef _chains_avbRxSurroundView_H_
#define _chains_avbRxSurroundView_H_

#include <include/link_api/system.h>
#include <include/link_api/avbRxLink.h>
#include <include/link_api/decLink.h>
#include <include/link_api/dupLink.h>
#include <include/link_api/algorithmLink_geometricAlignment.h>
#include <include/link_api/algorithmLink_synthesis.h>
#include <include/link_api/ipcLink.h>
#include <include/link_api/algorithmLink_photoAlignment.h>
#include <include/link_api/selectLink.h>
#include <include/link_api/vpeLink.h>
#include <include/link_api/syncLink.h>
#include <include/link_api/algorithmLink_dmaSwMs.h>
#include <include/link_api/grpxSrcLink.h>
#include <include/link_api/displayLink.h>

typedef struct {
       UInt32    AvbRxLinkID;
       UInt32    IPCOut_IPU1_1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_IPU1_1_0LinkID;
       UInt32    DecodeLinkID;
       UInt32    Dup_sv_orgLinkID;
       UInt32    Sync_svLinkID;
       UInt32    Dup_svLinkID;
       UInt32    IPCOut_IPU1_0_DSP1_1LinkID;
       UInt32    IPCIn_DSP1_IPU1_0_1LinkID;
       UInt32    IPCOut_IPU1_0_DSP1_0LinkID;
       UInt32    IPCIn_DSP1_IPU1_0_0LinkID;
       UInt32    Alg_GeoAlignLinkID;
       UInt32    Alg_SynthesisLinkID;
       UInt32    IPCOut_DSP1_IPU1_0_0LinkID;
       UInt32    IPCIn_IPU1_0_DSP1_1LinkID;
       UInt32    Display_svLinkID;
       UInt32    Alg_PhotoAlignLinkID;
       UInt32    SelectLinkID;
       UInt32    VPE_sv_org2LinkID;
       UInt32    Sync_sv_org2LinkID;
       UInt32    Alg_DmaSwMs_sv_org2LinkID;
       UInt32    Display_sv_org2LinkID;
       UInt32    VPE_sv_org1LinkID;
       UInt32    Sync_sv_org1LinkID;
       UInt32    Alg_DmaSwMs_sv_org1LinkID;
       UInt32    Display_sv_org1LinkID;
       UInt32    GrpxSrcLinkID;
       UInt32    Display_GrpxLinkID;

       AvbRxLink_CreateParams                  AvbRxPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_IPU1_1_0Prm;
       DecLink_CreateParams                    DecodePrm;
       DupLink_CreateParams                    Dup_sv_orgPrm;
       SyncLink_CreateParams                   Sync_svPrm;
       DupLink_CreateParams                    Dup_svPrm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_1Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_1Prm;
       IpcLink_CreateParams                    IPCOut_IPU1_0_DSP1_0Prm;
       IpcLink_CreateParams                    IPCIn_DSP1_IPU1_0_0Prm;
       AlgorithmLink_GAlignCreateParams        Alg_GeoAlignPrm;
       AlgorithmLink_SynthesisCreateParams     Alg_SynthesisPrm;
       IpcLink_CreateParams                    IPCOut_DSP1_IPU1_0_0Prm;
       IpcLink_CreateParams                    IPCIn_IPU1_0_DSP1_1Prm;
       DisplayLink_CreateParams                Display_svPrm;
       AlgorithmLink_PAlignCreateParams        Alg_PhotoAlignPrm;
       SelectLink_CreateParams                 SelectPrm;
       VpeLink_CreateParams                    VPE_sv_org2Prm;
       SyncLink_CreateParams                   Sync_sv_org2Prm;
       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMs_sv_org2Prm;
       DisplayLink_CreateParams                Display_sv_org2Prm;
       VpeLink_CreateParams                    VPE_sv_org1Prm;
       SyncLink_CreateParams                   Sync_sv_org1Prm;
       AlgorithmLink_DmaSwMsCreateParams       Alg_DmaSwMs_sv_org1Prm;
       DisplayLink_CreateParams                Display_sv_org1Prm;
       GrpxSrcLink_CreateParams                GrpxSrcPrm;
       DisplayLink_CreateParams                Display_GrpxPrm;
} chains_avbRxSurroundViewObj;

Void chains_avbRxSurroundView_SetLinkId(chains_avbRxSurroundViewObj *pObj);

Void chains_avbRxSurroundView_ResetLinkPrms(chains_avbRxSurroundViewObj *pObj);

Void chains_avbRxSurroundView_SetPrms(chains_avbRxSurroundViewObj *pObj);

Void chains_avbRxSurroundView_ConnectLinks(chains_avbRxSurroundViewObj *pObj);

Int32 chains_avbRxSurroundView_Create(chains_avbRxSurroundViewObj *pObj, Void *appObj);

Int32 chains_avbRxSurroundView_Start(chains_avbRxSurroundViewObj *pObj);

Int32 chains_avbRxSurroundView_Stop(chains_avbRxSurroundViewObj *pObj);

Int32 chains_avbRxSurroundView_Delete(chains_avbRxSurroundViewObj *pObj);

Void chains_avbRxSurroundView_printBufferStatistics(chains_avbRxSurroundViewObj *pObj);

Void chains_avbRxSurroundView_printStatistics(chains_avbRxSurroundViewObj *pObj);

Void chains_avbRxSurroundView_SetAppPrms(chains_avbRxSurroundViewObj *pObj, Void *appObj);

#endif /* _chains_avbRxSurroundView_H_ */