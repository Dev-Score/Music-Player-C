#include<stdio.h>
#include<stdlib.h>
#include<miniaudio.h>
int main()
{
    //creating an object to handle everything
    ma_device music; 
    //configuring audio for playback 
    ma_device_config config=ma_device_config_init(ma_device_type_playback);
    //initializing the object and configuration
    ma_device_init(&music,&config,NULL);
    ma_device_start(&music);
    
    //storing audio data using waveform
    ma_waveform waveform;
    //initializing waveform with song 
    char *song_path="Starboy.mp3"; 
    //the song must be on the same directory as the program
    ma_waveform_init_file(&waveform,song_path);

    //writing audio data to play
    ma_device_write_pcm_frames(&music,&waveform);

    //removing audio file from memory
    ma_waveform_uninit(&waveform);

    //stop the playback
    ma_device_stop(&music);
    ma_device_uninit(&music);

    
    return 0;
}