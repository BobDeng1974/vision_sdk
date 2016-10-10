/*
 *******************************************************************************
 *
 * Copyright (C) 2013 Texas Instruments Incorporated - http://www.ti.com/
 * ALL RIGHTS RESERVED
 *
 *******************************************************************************
 */

/**
 *******************************************************************************
 * \file chains_vipSingleCamFrmcpyEve_SgxDisplay.c
 *
 * \brief  Usecase file implementation of capture + frameCopy + display usecase.
 *
 *         Single channel Capture + Alg frame copy on EVE + SGX frame copy
 *         SGX output is send to Display Link on M4
 *
 *         The data flow daigram is shown is corrsponding
 *         chains_vipSingleCamFrmcpyEve_SgxDisplay.jpg file
 *
 * \version 0.0 (Jun 2014) : [YM] First version ported for linux.
 *
 *******************************************************************************
*/

/*******************************************************************************
 *  INCLUDE FILES
 *******************************************************************************
 */

#include "chains_vipSingleCamFrmcpyEve_SgxDisplay_priv.h"
#include <linux/examples/tda2xx/include/chains.h>
#include <linux/examples/common/chains_common.h>
#include <linux/src/system/system_gbm_allocator.h>

#define CAPTURE_SENSOR_WIDTH            (1280)
#define CAPTURE_SENSOR_HEIGHT           (720)

/**
 *******************************************************************************
 *
 *  \brief  SingleCameraViewObject
 *
 *        This structure contains all the LinksId's and create Params.
 *        The same is passed to all create, start, stop functions.
 *
 *******************************************************************************
*/
typedef struct {
    /**< Link Id's and device IDs to use for this use-case */
    chains_vipSingleCamFrmcpyEve_SgxDisplayObj ucObj;

    UInt32  appCtrlLinkId;
    UInt32  captureOutWidth;
    UInt32  captureOutHeight;

    Chains_Ctrl *chainsCfg;

} chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj;

static struct control_srv_egl_ctx chainsEglParams = {
   .get_egl_native_display = gbm_allocator_get_native_display,
   .get_egl_native_buffer = gbm_allocator_get_native_buffer,
   .destroy_egl_native_buffer = gbm_allocator_destroy_native_buffer,
};

/**
 *******************************************************************************
 *
 * \brief   Set PD draw parameters
 *
 * \param   pPrm    [IN]    algorithm parameters
 *
 *******************************************************************************
*/
Void chains_vipSingleCamFrmcpyEve_SgxDisplay_SetFrameCopyAlgPrms(
                                  AlgorithmLink_FrameCopyCreateParams *pPrm,
                                  Chains_Ctrl *chainsCfg)
{
    if( chainsCfg->algProcId == SYSTEM_PROC_EVE1
            ||
        chainsCfg->algProcId == SYSTEM_PROC_EVE2
            ||
        chainsCfg->algProcId == SYSTEM_PROC_EVE3
            ||
        chainsCfg->algProcId == SYSTEM_PROC_EVE4)
    {
        pPrm->baseClassCreate.algId = ALGORITHM_LINK_EVE_ALG_FRAMECOPY;
    } 
    else
    {
        Vps_printf ("Frame copy on EVE is only supported in this UC \n");
        UTILS_assert(0);
    }

    pPrm->maxWidth    = CAPTURE_SENSOR_WIDTH;
    pPrm->maxHeight   = CAPTURE_SENSOR_HEIGHT;

    pPrm->numOutputFrames = 3;
}

/**
 *******************************************************************************
 *
 * \brief   Set SGXDISPLAY Link Parameters
 *
 *          It is called in Create function.
 *
 *
 * \param   pPrm    [IN]    IpcLink_CreateParams
 *
 *******************************************************************************
*/
static Void chains_vipSingleCamFrmcpyEve_SgxDisplay_SetSgxDisplayLinkPrms (
                                  SgxFrmcpyLink_CreateParams *prms,
                                  UInt32 width, UInt32 height)
{
    prms->displayWidth = width;
    prms->displayHeight = height;
    prms->renderType = SGXFRMCPY_RENDER_TYPE_1x1;
    prms->inBufType = SYSTEM_BUFFER_TYPE_VIDEO_FRAME;
    prms->bEglInfoInCreate = TRUE;
    prms->EglInfo = (void *)&chainsEglParams;
}

/**
 *******************************************************************************
 *
 * \brief   Set link Parameters
 *
 *          It is called in Create function of the auto generated use-case file.
 *
 * \param pUcObj    [IN] Auto-generated usecase object
 * \param appObj    [IN] Application specific object
 *
 *******************************************************************************
*/
Void chains_vipSingleCamFrmcpyEve_SgxDisplay_SetAppPrms(
               chains_vipSingleCamFrmcpyEve_SgxDisplayObj *pUcObj,Void *appObj)
{
    UInt32 displayWidth, displayHeight;

    chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj *pObj
            = (chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj*)appObj;

    pObj->captureOutWidth  = CAPTURE_SENSOR_WIDTH;
    pObj->captureOutHeight = CAPTURE_SENSOR_HEIGHT;

    ChainsCommon_SingleCam_SetCapturePrms(&(pUcObj->CapturePrm),
            CAPTURE_SENSOR_WIDTH,
            CAPTURE_SENSOR_HEIGHT,
            pObj->captureOutWidth,
            pObj->captureOutHeight,
            pObj->chainsCfg->captureSrc
            );

    chains_vipSingleCamFrmcpyEve_SgxDisplay_SetFrameCopyAlgPrms(
                                            &pUcObj->Alg_FrameCopyPrm,
                                             pObj->chainsCfg);

    ChainsCommon_GetDisplayWidthHeight(
        pObj->chainsCfg->displayType,
        &displayWidth,
        &displayHeight
        );

    chains_vipSingleCamFrmcpyEve_SgxDisplay_SetSgxDisplayLinkPrms
                    (&pUcObj->SgxFrmcpyPrm,
                     displayWidth,
                     displayHeight
                    );

    ChainsCommon_SetGrpxSrcPrms(&pUcObj->GrpxSrcPrm,
                                 displayWidth,
                                 displayHeight
                                );

    pUcObj->Display_GrpxPrm.rtParams.tarWidth       = displayWidth;
    pUcObj->Display_GrpxPrm.rtParams.tarHeight      = displayHeight;
    pUcObj->Display_GrpxPrm.rtParams.posX           = 0;
    pUcObj->Display_GrpxPrm.rtParams.posY           = 0;
    pUcObj->Display_GrpxPrm.displayId               = DISPLAY_LINK_INST_DSS_GFX1;

    ChainsCommon_SetDisplayPrms(&pUcObj->Display_M4Prm,
                                NULL,
                                pObj->chainsCfg->displayType,
                                displayWidth,
                                displayHeight
                               );

    ChainsCommon_StartDisplayCtrl(
        pObj->chainsCfg->displayType,
        displayWidth,
        displayHeight
        );
}

/**
 *******************************************************************************
 *
 * \brief   Start the capture display Links
 *
 *          Function sends a control command to capture and display link to
 *          to Start all the required links . Links are started in reverce
 *          order as information of next link is required to connect.
 *          System_linkStart is called with LinkId to start the links.
 *
 * \param   pObj  [IN] chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj
 *
 *
 *******************************************************************************
*/
Void chains_vipSingleCamFrmcpyEve_SgxDisplay_StartApp(
                     chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj *pObj)
{
    ChainsCommon_statCollectorReset();
    ChainsCommon_memPrintHeapStatus();

    chains_vipSingleCamFrmcpyEve_SgxDisplay_Start(&pObj->ucObj);

    ChainsCommon_prfLoadCalcEnable(TRUE, FALSE, FALSE);

}

/**
 *******************************************************************************
 *
 * \brief   Delete the capture display Links
 *
 *          Function sends a control command to capture and display link to
 *          to delete all the prior created links
 *          System_linkDelete is called with LinkId to delete the links.
 *
 * \param   pObj   [IN]   chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj
 *
 *******************************************************************************
*/
Void chains_vipSingleCamFrmcpyEve_SgxDisplay_StopApp(
                     chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj *pObj)
{

    chains_vipSingleCamFrmcpyEve_SgxDisplay_Stop(&pObj->ucObj);

    chains_vipSingleCamFrmcpyEve_SgxDisplay_Delete(&pObj->ucObj);

    ChainsCommon_StopDisplayCtrl();

    ChainsCommon_prfLoadCalcEnable(FALSE, FALSE, FALSE);

}

/**
 *******************************************************************************
 *
 * \brief   Single Channel Capture + PD + Display usecase function
 *
 *          This functions executes the create, start functions
 *
 *          Further in a while loop displays run time menu and waits
 *          for user inputs to print the statistics or to end the demo.
 *
 *          Once the user inputs end of demo stop and delete
 *          functions are executed.
 *
 * \param   chainsCfg       [IN]   Chains_Ctrl
 *
 *******************************************************************************
*/
Void chains_vipSingleCamFrmcpyEve_SgxDisplay(Chains_Ctrl *chainsCfg)
{
    char ch;
    UInt32 done = FALSE;
    chains_vipSingleCamFrmcpyEve_SgxDisplayAppObj chainsObj;

    chainsObj.chainsCfg = chainsCfg;

    chains_vipSingleCamFrmcpyEve_SgxDisplay_Create(&chainsObj.ucObj, &chainsObj);

    chains_vipSingleCamFrmcpyEve_SgxDisplay_StartApp(&chainsObj);

    while(!done)
    {
        ch = Chains_menuRunTime();

        switch(ch)
        {
            case '0':
                done = TRUE;
                break;
            case 'p':
            case 'P':
                ChainsCommon_prfCpuLoadPrint();
                ChainsCommon_statCollectorPrint();
                chains_vipSingleCamFrmcpyEve_SgxDisplay_printStatistics(&chainsObj.ucObj);
                chains_vipSingleCamFrmcpyEve_SgxDisplay_printBufferStatistics(&chainsObj.ucObj);
                break;
            default:
                Vps_printf("\nUnsupported option '%c'. Please try again\n", ch);
                break;
        }
    }

    chains_vipSingleCamFrmcpyEve_SgxDisplay_StopApp(&chainsObj);
}
