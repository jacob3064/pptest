#ifndef __BD_COMM_ISP_H__
#define __BD_COMM_ISP_H__

#include "bd_type.h"
#include "bd_errno.h"
#include "bd_common.h"
#include "bd_debug.h"

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* End of #ifdef __cplusplus */

/****************************************************************************
 * GENERAL STRUCTURES                                                       *
 ****************************************************************************/

typedef enum bdISP_ERR_CODE_E
{
    ERR_ISP_NOT_INIT				= 0x40,
    ERR_ISP_TM_NOT_CFG				= 0x41,
    ERR_ISP_ATTR_NOT_CFG			= 0x42,
    ERR_ISP_SNS_UNREGISTER			= 0x43,
    ERR_ISP_INVALID_ADDR			= 0x44,
    ERR_ISP_INVALID_ACCESS			= 0x45,
    ERR_ISP_WAIT_TIMEOUT			= 0x46,
    
} ISP_ERR_CODE_E;


#define BD_ERR_ISP_NULL_PTR							BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, EN_ERR_NULL_PTR)
#define BD_ERR_ISP_ILLEGAL_PARAM         			BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, EN_ERR_ILLEGAL_PARAM)

#define BD_ERR_ISP_NOT_INIT         				BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_NOT_INIT)
#define BD_ERR_ISP_TM_NOT_CFG         				BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_TM_NOT_CFG)
#define BD_ERR_ISP_ATTR_NOT_CFG         			BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_ATTR_NOT_CFG)
#define BD_ERR_ISP_SNS_UNREGISTER  	       			BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_SNS_UNREGISTER)
#define BD_ERR_ISP_INVALID_ADDR	   		   			BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_INVALID_ADDR)
#define BD_ERR_ISP_INVALID_ACCESS  		   			BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_INVALID_ACCESS)
#define BD_ERR_ISP_WAIT_TIMEOUT  		   			BD_DEF_ERR(BD_ID_ISP, EN_ERR_LEVEL_ERROR, ERR_ISP_WAIT_TIMEOUT)

typedef enum bdISP_GAMMATABLE_TYPE_E
{
	ISP_GAMMATABLE_TYPE_Y1 = 0,
	ISP_GAMMATABLE_TYPE_Y2,
	ISP_GAMMATABLE_TYPE_C1,
	ISP_GAMMATABLE_TYPE_C2,
	ISP_GAMMATABLE_TYPE_BUTT,
} ISP_GAMMATABLE_TYPE_E;

#define ISP_FUNC_HIGH_LSC			 0x80000000
#define ISP_FUNC_HIGH_AWB			 0x40000000
#define ISP_FUNC_HIGH_WDPC			 0x20000000
#define ISP_FUNC_HIGH_BDPC			 0x10000000
#define ISP_FUNC_HIGH_GINTP			 0x08000000
#define ISP_FUNC_HIGH_MOIRE			 0x04000000
#define ISP_FUNC_HIGH_CCR			 0x02000000
#define ISP_FUNC_HIGH_CCRLPF		 0x01000000
#define ISP_FUNC_HIGH_RGBGM			 0x00800000
#define ISP_FUNC_HIGH_YGM			 0x00400000
#define ISP_FUNC_HIGH_EBLF			 0x00200000
#define ISP_FUNC_HIGH_EBLFM			 0x00100000
#define ISP_FUNC_HIGH_EDGE			 0x00080000
#define ISP_FUNC_HIGH_CLAMP			 0x00040000
#define ISP_FUNC_HIGH_BSEQ_A		 0x00030000
#define ISP_FUNC_HIGH_BSEQ_B		 0x00020000
#define ISP_FUNC_HIGH_BSEQ_C		 0x00010000
#define ISP_FUNC_HIGH_BSEQ_D		 0x00000000
#define ISP_FUNC_HIGH_REV			 0x00008000
#define ISP_FUNC_HIGH_EMBOS			 0x00004000
#define ISP_FUNC_HIGH_EMBOSM		 0x00002000
#define ISP_FUNC_HIGH_SKETCH		 0x00001000
#define ISP_FUNC_HIGH_BW			 0x00000800
#define ISP_FUNC_HIGH_MDSLP			 0x00000400
#define ISP_FUNC_HIGH_MDALA			 0x00000200
#define ISP_FUNC_HIGH_MDALAM		 0x00000100
#define ISP_FUNC_HIGH_TP_A			 0x000000C0
#define ISP_FUNC_HIGH_TP_B			 0x00000080
#define ISP_FUNC_HIGH_TP_C			 0x00000040
#define ISP_FUNC_HIGH_TP_D			 0x00000000
#define ISP_FUNC_HIGH_LSEQ_A		 0x00000030
#define ISP_FUNC_HIGH_LSEQ_B		 0x00000020
#define ISP_FUNC_HIGH_LSEQ_C		 0x00000010
#define ISP_FUNC_HIGH_LSEQ_D		 0x00000000
#define ISP_FUNC_HIGH_WBSE_A		 0x0000000C
#define ISP_FUNC_HIGH_WBSE_B		 0x00000008
#define ISP_FUNC_HIGH_WBSE_C		 0x00000004
#define ISP_FUNC_HIGH_WBSE_D		 0x00000000
#define ISP_FUNC_HIGH_INTP_A		 0x00000003
#define ISP_FUNC_HIGH_INTP_B		 0x00000002
#define ISP_FUNC_HIGH_INTP_C		 0x00000001
#define ISP_FUNC_HIGH_INTP_D		 0x00000000
#define ISP_FUNC_HIGH_BUTT			 0x00000000


#define ISP_FUNC_LOW_AESHO			 0x80000000
#define ISP_FUNC_LOW_AWBSHO			 0x40000000
#define ISP_FUNC_LOW_GODSHO			 0x20000000
#define ISP_FUNC_LOW_DEFSHO			 0x10000000
#define ISP_FUNC_LOW_AFEDGE			 0x08000000
#define ISP_FUNC_LOW_AFWIND			 0x04000000
#define ISP_FUNC_LOW_MLEDPD			 0x02000000
#define ISP_FUNC_LOW_RESEV0			 0x01000000
#define ISP_FUNC_LOW_PERIE			 0x00800000
#define ISP_FUNC_LOW_YRANG			 0x00400000
#define ISP_FUNC_LOW_EDGSHO			 0x00200000
#define ISP_FUNC_LOW_ECLPSHO		 0x00100000
#define ISP_FUNC_LOW_INTPDSHO		 0x00080000
#define ISP_FUNC_LOW_EDGSEL			 0x00040000
#define ISP_FUNC_LOW_ECSEL_A		 0x00030000
#define ISP_FUNC_LOW_ECSEL_B		 0x00020000
#define ISP_FUNC_LOW_ECSEL_C		 0x00010000
#define ISP_FUNC_LOW_ECSEL_D		 0x00000000
#define ISP_FUNC_LOW_CONTSEL		 0x00008000
#define ISP_FUNC_LOW_WBSE_A			 0x00006000
#define ISP_FUNC_LOW_WBSE_B			 0x00004000
#define ISP_FUNC_LOW_WBSE_C			 0x00002000
#define ISP_FUNC_LOW_WBSE_D			 0x00000000
#define ISP_FUNC_LOW_IWBSE_A		 0x00001800
#define ISP_FUNC_LOW_IWBSE_B		 0x00001000
#define ISP_FUNC_LOW_IWBSE_C		 0x00000800
#define ISP_FUNC_LOW_IWBSE_D		 0x00000000
#define ISP_FUNC_LOW_DECOL			 0x00000400
#define ISP_FUNC_LOW_DZOM			 0x00000200
#define ISP_FUNC_LOW_HDYCC			 0x00000100
#define ISP_FUNC_LOW_RESEV1			 0x00000000
#define ISP_FUNC_LOW_AWBSSHO_A		 0x00000060
#define ISP_FUNC_LOW_AWBSSHO_B		 0x00000040
#define ISP_FUNC_LOW_AWBSSHO_C		 0x00000020
#define ISP_FUNC_LOW_AWBSSHO_D		 0x00000000
#define ISP_FUNC_LOW_RESEV2			 0x00000000
#define ISP_FUNC_LOW_USRCSM			 0x00000008
#define ISP_FUNC_LOW_EGMDFSEL		 0x00000004
#define ISP_FUNC_LOW_EGMEN			 0x00000002
#define ISP_FUNC_LOW_EGMSEL			 0x00000001
#define ISP_FUNC_LOW_BUTT			 0x00000000

#define ISP_AUTO_TYPE_FLK1STEP		 0x80000000
#define ISP_AUTO_TYPE_FLK2STEP		 0x40000000
#define ISP_AUTO_TYPE_FLKPERIOD		 0x20000000
#define ISP_AUTO_TYPE_AEFRMINT		 0x10000000
#define ISP_AUTO_TYPE_AWBFRMINT		 0x08000000
#define ISP_AUTO_TYPE_LGCSXAXIS		 0x00800000
#define ISP_AUTO_TYPE_LGCSFIT		 0x00400000
#define ISP_AUTO_TYPE_YTFIT			 0x00200000
#define ISP_AUTO_TYPE_DGAINMOD		 0x00040000
#define ISP_AUTO_TYPE_RGBGRFIT		 0x00008000
#define ISP_AUTO_TYPE_RGBGRXAXIS	 0x00004000
#define ISP_AUTO_TYPE_AWBNORMAL		 0x00002000
#define ISP_AUTO_TYPE_FBLACKFIT		 0x00001000
#define ISP_AUTO_TYPE_IRISMOD		 0x00000800
#define ISP_AUTO_TYPE_LEDOFFMOD		 0x00000400
#define ISP_AUTO_TYPE_MAXEXP		 0x00000200
#define ISP_AUTO_TYPE_AWBFULL		 0x00000020
#define ISP_AUTO_TYPE_PEDESTGG		 0x00000010
#define ISP_AUTO_TYPE_PEDESTFIT		 0x00000008
#define ISP_AUTO_TYPE_DIGBINNING	 0x00000004
#define ISP_AUTO_TYPE_MIRSMOD		 0x00000002
#define ISP_AUTO_TYPE_BUTT			 0x00000000

typedef enum bdISP_FLICKER_TYPE_E
{
	ISP_FLICKER_TYPE_OFF = 0,
	ISP_FLICKER_TYPE_AUTO,
	ISP_FLICKER_TYPE_60HZ,
	ISP_FLICKER_TYPE_50HZ,
	ISP_FLICKER_TYPE_BUTT,		
} ISP_FLICKER_TYPE_E;

#define isp_flicker_type_str(x)		\
	((x==ISP_FLICKER_TYPE_OFF)?"Off":\
	(x==ISP_FLICKER_TYPE_AUTO)?"Auto":\
	(x==ISP_FLICKER_TYPE_60HZ)?"60Hz":\
	(x==ISP_FLICKER_TYPE_50HZ)?"50Hz":"Unknown")

typedef enum bdISP_IRIS_TYPE_E
{
	ISP_IRIS_TYPE_FIXED	= 0,
	ISP_IRIS_TYPE_DCIRIS,
	ISP_IRIS_TYPE_BUTT,
} ISP_IRIS_TYPE_E;

#define isp_iris_type_str(x)	\
	((x==ISP_IRIS_TYPE_FIXED)?"Fixed":\
	(x==ISP_IRIS_TYPE_DCIRIS)?"DC-iris":"Unknown")

typedef enum bdISP_BLC_TYPE_E
{
	ISP_BLC_TYPE_OFF = 0,
	ISP_BLC_TYPE_LOW,
	ISP_BLC_TYPE_MID,
	ISP_BLC_TYPE_HIGH,
	ISP_BLC_TYPE_BUTT
} ISP_BLC_TYPE_E;

#define isp_blc_type_str(x)	\
	((x==ISP_BLC_TYPE_OFF)?"Off":\
	(x==ISP_BLC_TYPE_LOW)?"Low":\
	(x==ISP_BLC_TYPE_MID)?"Mid":\
	(x==ISP_BLC_TYPE_HIGH)?"High":"Unknown")

typedef enum bdISP_SHUTTER_TYPE_E
{
	ISP_SHUTTER_TYPE_AUTO = 0,
	ISP_SHUTTER_TYPE_1_100,	 
	ISP_SHUTTER_TYPE_1_120,	 
	ISP_SHUTTER_TYPE_1_250,	 
	ISP_SHUTTER_TYPE_1_500,	 
	ISP_SHUTTER_TYPE_1_1000,	 
	ISP_SHUTTER_TYPE_1_2000,	 
	ISP_SHUTTER_TYPE_1_4000,	 
	ISP_SHUTTER_TYPE_1_10000, 
	ISP_SHUTTER_TYPE_1_100000,
	ISP_SHUTTER_TYPE_BUTT,
} ISP_SHUTTER_TYPE_E;

#define isp_shutter_type_str(x)	\
	((x==ISP_SHUTTER_TYPE_AUTO)?"Auto":\
	(x==ISP_SHUTTER_TYPE_1_100)?"1/100":\
	(x==ISP_SHUTTER_TYPE_1_120)?"1/120":\
	(x==ISP_SHUTTER_TYPE_1_250)?"1/250":\
	(x==ISP_SHUTTER_TYPE_1_500)?"1/500":\
	(x==ISP_SHUTTER_TYPE_1_1000)?"1/1000":\
	(x==ISP_SHUTTER_TYPE_1_2000)?"1/2000":\
	(x==ISP_SHUTTER_TYPE_1_4000)?"1/4000":\
	(x==ISP_SHUTTER_TYPE_1_10000)?"1/10000":\
	(x==ISP_SHUTTER_TYPE_1_100000)?"1/100000":"Unknwon")

typedef enum bdISP_SENSORUP_TYPE_E
{
	ISP_SENSORUP_TYPE_OFF = 0,
	ISP_SENSORUP_TYPE_LOW,	
	ISP_SENSORUP_TYPE_MID,	
	ISP_SENSORUP_TYPE_HIGH,	
	ISP_SENSORUP_TYPE_BUTT,
} ISP_SENSORUP_TYPE_E;

#define isp_sensorup_type_str(x)	\
	((x==ISP_SENSORUP_TYPE_OFF)?"Off":\
	(x==ISP_SENSORUP_TYPE_LOW)?"Low":\
	(x==ISP_SENSORUP_TYPE_MID)?"Mid":\
	(x==ISP_SENSORUP_TYPE_HIGH)?"High":"Unknown")

typedef enum bdISP_AWB_MODE_E
{
	ISP_AWB_MODE_AUTO	 = 0,
	ISP_AWB_MODE_INDOOR,		
	ISP_AWB_MODE_OUTDOOR,	
	ISP_AWB_MODE_USER,	
	ISP_AWB_MODE_BUTT,
} ISP_AWB_MODE_E;

#define isp_awb_type_str(x)	\
	((x==ISP_AWB_MODE_AUTO)?"Auto":\
	(x==ISP_AWB_MODE_INDOOR)?"In-Door":\
	(x==ISP_AWB_MODE_OUTDOOR)?"Out-Door":\
	(x==ISP_AWB_MODE_USER)?"User":"Unknown")


typedef enum bdISP_NOISEFILTER_MODE_E
{
	ISP_NOISEFILTER_MODE_OFF = 0,
	ISP_NOISEFILTER_MODE_LOW,	
	ISP_NOISEFILTER_MODE_MID,	
	ISP_NOISEFILTER_MODE_HIGH,	
	ISP_NOISEFILTER_MODE_BUTT,
} ISP_NOISEFILTER_MODE_E;

#define isp_nfilter_type_str(x)	\
	((x==ISP_NOISEFILTER_MODE_OFF)?"Off":\
	(x==ISP_NOISEFILTER_MODE_LOW)?"Low":\
	(x==ISP_NOISEFILTER_MODE_MID)?"Mid":\
	(x==ISP_NOISEFILTER_MODE_HIGH)?"High":"Unknown")
	

typedef enum bdISP_FLIP_MODE_E
{
	ISP_FLIP_MODE_OFF = 0,
	ISP_FLIP_MODE_VER,
	ISP_FLIP_MODE_HOR,
	ISP_FLIP_MODE_ALL,
	ISP_FLIP_MODE_BUTT,
} ISP_FLIP_MODE_E;

#define isp_flip_type_str(x)	\
	((x==ISP_FLIP_MODE_OFF)?"Off":\
	(x==ISP_FLIP_MODE_VER)?"Vertical":\
	(x==ISP_FLIP_MODE_HOR)?"Horizontal":\
	(x==ISP_FLIP_MODE_ALL)?"Vertical+Horizontal":"Unknown")

typedef enum bdISP_BAYER_FORMAT_E
{
	ISP_BAYER_FORMAT_RGGB	= 0,
	ISP_BAYER_FORMAT_GBRG	= 1,
	ISP_BAYER_FORMAT_GRBG	= 2,
	ISP_BAYER_FORMAT_BGGR	= 3,
	ISP_BAYER_FORMAT_BUTT	
} ISP_BAYER_FORMAT_E;

#define isp_bayerseq_type_str(x)	\
	((x==ISP_BAYER_FORMAT_RGGB)?"RGGB":\
	(x==ISP_BAYER_FORMAT_GBRG)?"GBRG":\
	(x==ISP_BAYER_FORMAT_GRBG)?"GRBG":\
	(x==ISP_BAYER_FORMAT_BGGR)?"BGGR":"Unknown")

typedef enum bdISP_WIND_MODE_E
{
	ISP_WIND_NONE		= 0,
	ISP_WIND_ALL		= 1,
	ISP_WIND_BUTT
    
} ISP_WIND_MODE_E;

#define MAX_EXPOSURE_BRIGHTNESS 28
#define MAX_AGC_VALUE	64
#define MAX_SATURATION	127
#define MAX_BRIGHTNESS	127
#define MAX_CONTRAST	127
#define MAX_SHARPNESS	255

typedef struct bdISP_INPUT_TIMING_S
{
	ISP_WIND_MODE_E enWndMode;
	BD_U16 u16HorWndStart;   
	BD_U16 u16HorWndLength;  
	BD_U16 u16VerWndStart;   
	BD_U16 u16VerWndLength;  
    
} ISP_INPUT_TIMING_S;

typedef struct bdISP_INPUT_POLARITY_S
{
	BD_U32 u32PixelClk;
	BD_U32 u32HSyncClk;
	BD_U32 u32VSyncClk;
} ISP_INPUT_POLARITY_S;

typedef struct bdISP_IMAGE_ATTR_S	
{
	BD_U16 u16Width;   
	BD_U16 u16Height;  
	BD_U16 u16FrameRate;	
	ISP_BAYER_FORMAT_E  enBayer;
    
} ISP_IMAGE_ATTR_S;


#define ISP_EVENT_DETECT_MASK 		unsigned int
#define	ISP_EVENT_DETECT_NONE 		0x00000000
#define	ISP_EVENT_DETECT_MOTION 	0x00000001
#define	ISP_EVENT_DETECT_BLIND 		0x00000010
#define	ISP_EVENT_DETECT_NIGHT 		0x00000100
#define	ISP_EVENT_DETECT_DAY 		0x00001000
#define	ISP_EVENT_DETECT_DEFOCUS 	0x00010000
#define	ISP_EVENT_DETECT_DEHAZE 	0x00100000

/* MANR definition */

typedef struct bdISP_MANR_ATTR_S {
	BD_BOOL bEnable;
	BD_U32 u32SFilter;
	BD_U32 u32SGain0;
	BD_U32 u32SGain1;
	BD_U32 u32TFilter;
	BD_U32 u32TGain;
	BD_U32 u32KFactor;

	BD_U16 u16NVAR_B;
	BD_U16 u16NVAR_A;
	BD_U32 u32Threshold;
	BD_U32 u32Width;
	BD_U32 u32Height;

	BD_BOOL bFrame25;
	BD_U32	u32TotalWidth;
	BD_U32 	u32TotalHeight;
	BD_U32	u32XKick;
	BD_U32 	u32YKick;
} ISP_MANR_ATTR_S;

typedef struct bdISP_MANR_FILTER_S {
	BD_BOOL bTFilterEnable;
	BD_BOOL bSFilterEnable;
} ISP_MANR_FILTER_S;

/* Defocus definition */

typedef struct bdISP_DEFOCUS_ATTR_S {
	BD_BOOL bEnable;
	
	BD_U32 u32Level;
	BD_U32 u32Spartial;
	BD_U32 u32Temporal;

	RECT_S	stRect;
} ISP_DEFOCUS_ATTR_S;

typedef struct bdISP_DEFOCUS_STATE_S {
	BD_BOOL	bFocused;
} ISP_DEFOCUS_STATE_S;



/* Dehaze definition */

typedef enum bdISP_DEHAZE_RESOLUTION_E
{
	ISP_DEHAZE_RESOLUTION_720P = 0x0,           
	//ISP_DEHAZE_RESOLUTION_1080I = 0x2,   /* sensor bayer does not support interlaced */ 	
	ISP_DEHAZE_RESOLUTION_1080P = 0x3,    
	ISP_DEHAZE_RESOLUTION_BUTT,           
} ISP_DEHAZE_RESOLUTION_E;

typedef enum bdISP_DEHAZE_FILTER_E
{
	ISP_DEHAZE_FILTER_PLUS = 0x0,
	ISP_DEHAZE_FILTER_X,
	ISP_DEHAZE_FILTER_3X3,
	ISP_DEHAZE_FILTER_3X3WEIGHT,
	ISP_DEHAZE_FILTER_BUTT,
} ISP_DEHAZE_FILTER_E;

typedef enum bdISP_DEHAZE_OUTRANGE_E
{
	ISP_DEHAZE_OUTRANGE_1_254 = 0x0,
	ISP_DEHAZE_OUTRANGE_16_240,
	ISP_DEHAZE_OUTRANGE_BUTT,
} ISP_DEHAZE_OUTRANGE_E;

typedef struct bdISP_DEHAZE_ATTR_S {
	BD_BOOL bEnable;
	
	/* Set Input Resolution */
	ISP_DEHAZE_RESOLUTION_E	enInputResolution;		// 0/1 : 720p, 2:1080i, 3:1080p

	ISP_DEHAZE_FILTER_E enFilterType;	// + Type, X Type, 3x3 Type, 3x3 Weighted Type

	/* DeHaze Region Window */	
	BD_U16 u16StartX;
	BD_U16 u16EndX;
	BD_U16 u16StartY;
	BD_U16 u16EndY;

	BD_U8	u8HazeTemporalSensitivity;
	BD_BOOL	bHazeDetectAllWindow;

	BD_BOOL	bGainDetectAllWindow;
	BD_U8 	u8GainThreshold;
	BD_U8 	u8GainMininum;
	BD_U8 	u8DeviationThreshold;
	BD_U8 	u8DeviationMinimum;
	BD_U8	u8GainTemporalSensitivity;

	BD_U8	u8AutoGainWeight;
	BD_BOOL	bAutoGainControl;
	BD_U16	u16ManualGainLevel;

	BD_BOOL	bDehazeAllWindow;

	BD_BOOL bBWEEnable;	
	BD_BOOL	bYPeak;

	ISP_DEHAZE_OUTRANGE_E enOutRange;	
	BD_BOOL	bYCInvert;

	BD_BOOL	bUseBlank;

} ISP_DEHAZE_ATTR_S;

typedef struct bdISP_DEHAZE_DETECT_STATE_S {
	BD_U32 u32GainValue;
	BD_U32 u32DehazeAverage;	/* means brightness */
	BD_U32 u32DeviationAverage; /* Difference */
	BD_U32 u32DeviationCoef;
} ISP_DEHAZE_DETECT_STATE_S;


/* Motion / Blind / Night / Day Detection */

typedef struct bdISP_MOTION_DETECT_ATTR_S{
	BD_BOOL	bEnable;
	BD_U16	u16TemporalSensitivity;
	BD_U16	u16SpatialSensitivity;
	BD_U16	u16LevelSensitivity;
	BD_U8	u8RefUpdatePeriod;		// frame unit.
} ISP_MOTION_DETECT_ATTR_S;

typedef struct bdISP_BLIND_DETECT_ATTR_S{
	BD_BOOL	bEnable;
	BD_U16	u16TemporalSensitivity;
	BD_U16	u16SpatialSensitivity;
	BD_U16	u16LevelSensitivity;
	BD_U8	u8RefUpdatePeriod;		// frame unit.
} ISP_BLIND_DETECT_ATTR_S;

typedef struct bdISP_NIGHT_DETECT_ATTR_S{
	BD_BOOL	bEnable;
	BD_U16	u16TemporalSensitivity;
	BD_U16	u16LevelSensitivity;
	BD_U8	u8RefUpdatePeriod;		// frame unit.
} ISP_NIGHT_DETECT_ATTR_S;

typedef struct bdISP_DAY_DETECT_ATTR_S{
	BD_BOOL	bEnable;
	BD_U16	u16TemporalSensitivity;
	BD_U16	u16LevelSensitivity;
	BD_U8	u8RefUpdatePeriod;		// frame unit.
} ISP_DAY_DETECT_ATTR_S;

typedef struct bdISP_BLIND_DETECT_STATE_S {
	BD_BOOL bBlinded;
} ISP_BLIND_DETECT_STATE_S;

typedef struct bdISP_NIGHT_DETECT_STATE_S {
	BD_BOOL bNightScene;
} ISP_NIGHT_DETECT_STATE_S;

typedef struct bdISP_DAY_DETECT_STATE_S {
	BD_BOOL bDayScene;
} ISP_DAY_DETECT_STATE_S;

typedef struct bdISP_MOTION_DETECT_MASK_S {
	BD_BOOL bClear;				// 0: set, 1: clear
	BD_U32 u32MaskBit[24];
} ISP_MOTION_DETECT_MASK_S;

typedef struct bdISP_BLIND_DETECT_MASK_S {
	BD_BOOL bClear;				// 0: set, 1: clear
	BD_U32 u32MaskBit[24];
} ISP_BLIND_DETECT_MASK_S;

typedef struct bdISP_MOTION_DETECT_DATA_S {
	BD_U32 u32DetectBit[2][48];	// [col][row]:  col[0]:msb, col[1]:lsb (total 64bit), row:vertical (total 48line)
} ISP_MOTION_DETECT_DATA_S;

#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* End of #ifdef __cplusplus */

#endif /* __BD_COMM_ISP_H__ */
