#ifndef __BD_API_AO_H__
#define __BD_API_AO_H__

#ifdef __cplusplus
#if __cplusplus
extern "C"{
#endif
#endif /* __cplusplus */
BD_S32 BD_MPI_AO_INIT(BD_VOID);
BD_VOID BD_MPI_AO_EXIT(BD_VOID);
BD_S32 BD_MPI_AO_SetPubAttr(AUDIO_DEV AudioDevId, const AIO_ATTR_S *pstAttr);
BD_S32 BD_MPI_AO_GetPubAttr(AUDIO_DEV AudioDevId, AIO_ATTR_S *pstAttr);

BD_S32 BD_MPI_AO_Enable(AUDIO_DEV AudioDevId);
BD_S32 BD_MPI_AO_Disable(AUDIO_DEV AudioDevId);

BD_S32 BD_MPI_AO_EnableChn(AUDIO_DEV AudioDevId, AO_CHN AoChn);
BD_S32 BD_MPI_AO_DisableChn(AUDIO_DEV AudioDevId, AO_CHN AoChn);

BD_S32 BD_MPI_AO_SendFrame(AUDIO_DEV AudioDevId, AO_CHN AoChn, const AUDIO_FRAME_S *pstData, BD_S32 s32MilliSec);

//BD_S32 BD_MPI_AO_EnableReSmp(AUDIO_DEV AudioDevId, AO_CHN AoChn, AUDIO_SAMPLE_RATE_E enInSampleRate);
//BD_S32 BD_MPI_AO_DisableReSmp(AUDIO_DEV AudioDevId, AO_CHN AoChn);

BD_S32 BD_MPI_AO_ClearChnBuf(AUDIO_DEV AudioDevId ,AO_CHN AoChn);
BD_S32 BD_MPI_AO_QueryChnStat(AUDIO_DEV AudioDevId ,AO_CHN AoChn, AO_CHN_STATE_S *pstStatus);

BD_S32 BD_MPI_AO_PauseChn(AUDIO_DEV AudioDevId, AO_CHN AoChn);
BD_S32 BD_MPI_AO_ResumeChn(AUDIO_DEV AudioDevId, AO_CHN AoChn);

BD_S32 BD_MPI_AO_SetVolume(AUDIO_DEV AudioDevId, BD_S32 s32VolumeDb);
BD_S32 BD_MPI_AO_GetVolume(AUDIO_DEV AudioDevId, BD_S32 *ps32VolumeDb);

BD_S32 BD_MPI_AO_SetMute(AUDIO_DEV AudioDevId, BD_BOOL bEnable);
BD_S32 BD_MPI_AO_GetMute(AUDIO_DEV AudioDevId, BD_BOOL *pbEnable);

//BD_S32 BD_MPI_AO_SetTrackMode(AUDIO_DEV AudioDevId, AUDIO_TRACK_MODE_E enTrackMode);
//BD_S32 BD_MPI_AO_GetTrackMode(AUDIO_DEV AudioDevId, AUDIO_TRACK_MODE_E *penTrackMode);

BD_S32 BD_MPI_AO_GetFd(AUDIO_DEV AudioDevId, AO_CHN AoChn);

BD_S32 BD_MPI_AO_ClrPubAttr(AUDIO_DEV AudioDevId);

BD_VOID BD_MPI_AO_DBGI2SStat(BD_S32 *rp, BD_S32 *wp);


#ifdef __cplusplus
#if __cplusplus
}
#endif
#endif /* __cplusplus */


#endif
