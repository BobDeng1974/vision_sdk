
SRCDIR += $(vision_sdk_PATH)/examples/tda2xx/src/usecases/vip_single_cam_view_dsswb

SRCS_$(IPU_PRIMARY_CORE) += \
		chains_vipSingleCam_DisplayWbCrc.c \
		chains_vipSingleCam_DisplayWbCrc_priv.c

