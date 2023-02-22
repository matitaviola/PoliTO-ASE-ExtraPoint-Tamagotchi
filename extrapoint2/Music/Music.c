#include "Music.h"
#define song_bg_len 19
/*variables*/
#define single_dura
volatile uint16_t duration=0;
volatile uint16_t song_pos=0;
volatile int time_factor=3;
volatile int may_change_note;
extern int freqs[];
extern int songbg_counter;
extern int songsel_counter;
extern int songeat_counter;
extern int songrun_counter;
extern int songcuddle_counter;

void PlayNote(note note) /*suona singola nota con timer2 e la stoppa dopo la durata corretta con timer3*/
{
	if(note.freq != pause)
	{
		reset_timer(2);
		init_timer(2,0,0,3,note.freq);
		enable_timer(2);
	}
	reset_timer(3);
	init_timer(3,0,0,3, note.duration);
	enable_timer(3);
}

void PlaySong(note* song, int caso){
	switch(caso){
	case(0):{
		PlayNote(song[songbg_counter]);
		songbg_counter++;
		if(songbg_counter>=SONG_BG_LEN) songbg_counter=0;
	}break;
		case(1):{
			PlayNote(song[songsel_counter]);
			songsel_counter++;
			if(songsel_counter>=SONG_SEL_LEN) songsel_counter=0;
		}break;
		case(2):{
			PlayNote(song[songeat_counter]);
			songeat_counter++;
			if(songeat_counter>=SONG_EAT_LEN) songeat_counter=0;
		}break;
		case(3):{
			PlayNote(song[songcuddle_counter]);
			songcuddle_counter++;
			if(songcuddle_counter>=SONG_CUDDLE_LEN) songcuddle_counter=0;
		}break;
		case(4):{
			PlayNote(song[songrun_counter]);
			songrun_counter++;
			if(songrun_counter>=SONG_RUN_LEN) songrun_counter=0;
		}break;
	}
	return;
}

