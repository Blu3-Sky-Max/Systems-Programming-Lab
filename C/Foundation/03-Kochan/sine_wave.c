#include <math.h> 
#include <spa/param/audio/format-utils.h> 
#include <pipewire/pipewire.h>

/* run: gcc -Wall sine_wave.c -o sine_wave.o -lm $(pkg-config --cflags --libs libpipewire-0.3) && ./sine_wave.o


 * Generate a stereo sine wave using SPA audio buffers.
 *
 * Audio samples are represented as signed 16-bit integers (S16)
 * and written to both the left and right channels.
 *
 * The audio sample rate is 44,100 Hz (44.1 kHz), which provides
 * 44,100 samples per second. The sine wave phase is expressed
 * in radians, with 2π representing one complete cycle.
 */


/* [Audio stream] */  

#define M_PI_M2  ( M_PI + M_PI) 
#define DEFAULT_RATE  44100
#define DEFAULT_CHANNELS  2
#define DEFAULT_VOLUME  0.7

typedef struct { 

    struct pw_main_loop *__inside_loop; 
    struct pw_stream    *__inside_stream; 
    double accumulator; 



} data; 


static void on_process (void *user_data){ 

  data   *data=user_data; 
  struct pw_buffer *b; 
  struct spa_buffer *buf; 

 int i,c, n_frames,strides; 
 int16_t *dst, val; 

/* buffered it and checked if it get buffered */ //at this place it generated requested, and buffer 
 if (( b=pw_stream_dequeue_buffer(data -> __inside_stream)) == NULL ) { 
   
   pw_log_warn("out of buffer: %m"); 
  return; 

} 

 buf= b -> buffer; 
 

if ( (dst= buf->datas[0].data) == NULL) 
 return; 
// strides tell the pipewire how many byte per frame. FOR example here: it 4byte per frame. 
strides=sizeof(uint16_t) *  DEFAULT_CHANNELS; 

// now n_frame holds the avalible size to be used, that is;  how many complete frames fit in the buffer PipeWire gave. 

n_frames=buf ->datas[0].maxsize / strides ;

 if( (b-> requested) < 0 )
  n_frames=SPA_MIN(b->requested, n_frames); 

for (i=0; i<n_frames; i++){ 
 
   data -> accumulator += M_PI_M2 * 440 / DEFAULT_RATE; 

  if (data -> accumulator  >= M_PI_M2) 
      data -> accumulator -= M_PI_M2;

 /* sin() gives a value between -1.0 and 1.0, we first apply
 *  the volume and then scale with 32767.0 to get a 16 bits value
 *  between [-32767 32767].
 *  Another common method to convert a double to
 *  16 bits is to multiple by 32768.0 and then clamp to
 *  [-32768 32767] to get the full 16 bits range. */

 
  val=sin(data -> accumulator) * DEFAULT_VOLUME * 32767.0 ; 

     for (c=0; c<DEFAULT_CHANNELS; c++) 
      *dst++=val; 


} 

buf->datas[0].chunk->offset=0; 
buf->datas[0].chunk -> stride=strides; 
buf -> datas[0].chunk -> size=n_frames * strides; 

pw_stream_queue_buffer(data->__inside_stream, b); 

} 
       

struct pw_stream_events  stream_event = { 
 PW_VERSION_STREAM_EVENTS, 
 .process=on_process,
}; 

int main (int __argc, char *__argv[]){ 

    pw_init(&__argc, &__argv);

 data data = { 0, }; 
const  struct spa_pod *param[1]; 
uint8_t buffer[1024]; 


struct spa_pod_builder b = SPA_POD_BUILDER_INIT(buffer, sizeof(buffer)); 

data.__inside_loop=pw_main_loop_new(NULL);   


data.__inside_stream=pw_stream_new_simple(pw_main_loop_get_loop(data.__inside_loop),"audio-src",pw_properties_new(PW_KEY_MEDIA_TYPE,"Audio" ,\
PW_KEY_MEDIA_CATEGORY,"Playback" , PW_KEY_MEDIA_ROLE, "Music", NULL ), &stream_event, &data);    



param[0]=spa_format_audio_raw_build(&b, SPA_PARAM_EnumFormat,
 &SPA_AUDIO_INFO_RAW_INIT( .format=SPA_AUDIO_FORMAT_S16, .channels=DEFAULT_CHANNELS, .rate=DEFAULT_RATE)); 


pw_stream_connect( data.__inside_stream, PW_DIRECTION_OUTPUT, PW_ID_ANY,PW_STREAM_FLAG_AUTOCONNECT |  PW_STREAM_FLAG_MAP_BUFFERS |  PW_STREAM_FLAG_RT_PROCESS, param, 1); 

 




pw_main_loop_run(data.__inside_loop); 

pw_stream_destroy(data.__inside_stream); 

pw_main_loop_destroy(data.__inside_loop); 




} 
