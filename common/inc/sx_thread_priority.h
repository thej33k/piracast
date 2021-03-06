#if !defined(_SX_THREAD_PRIORITY_H_)
#define _SX_THREAD_PRIORITY_H_

// The priority also depicts the data flow: 
// 
//                        -> VIDEO_DECODER -> VIDEO_SCHEDULE
// PKT_RX -> M2TS_DEMUX -|
//                        -> AUDIO_DECODER -> AUDIO_SCHEDULE
//
// Application profiling reveals audio decoding requires much more processing 
// because of the endianness swap on the received data, thus audio processing 
// threads need to run at lower priority than video to prevent video jittering. 
// Audio is also buffered by hardware; thus minor jitter will not affect 
// playback. 

#define MGMT_DATA_RX_THREAD_PRIORITY            90
#define MGMT_M2TS_PKT_PROCESS_THREAD_PRIORITY   80
#define VIDEO_DECODER_THREAD_PRIORITY           70
#define VIDEO_SCHEDULER_THREAD_PRIORITY         70
#define MGMT_AUDIO_DECODER_THREAD_PRIORITY      60
#define MGMT_AUDIO_SCHEDULER_THREAD_PRIORITY    60
#define MGMT_SYS_THREAD_PRIORITY 				50

#endif // #if !defined(_SX_THREAD_PRIORITY_H_)
