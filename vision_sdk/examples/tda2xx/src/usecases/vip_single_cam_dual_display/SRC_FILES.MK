
SRCDIR += $(vision_sdk_PATH)/examples/tda2xx/src/usecases/vip_single_cam_dual_display

SRCS_$(IPU_PRIMARY_CORE) += \
		chains_vipSingleCam_DualDisplay.c \
		chains_vipSingleCam_DualDisplay_priv.c

