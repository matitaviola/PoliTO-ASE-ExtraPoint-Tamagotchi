/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           Music.c
** Last modified Date:  2023-01-12
** Last Version:        V1.00
** Descriptions:        functions to manage music for tamagotchi project
** Correlated files:    adc, rit
**--------------------------------------------------------------------------------------------------------       
*********************************************************************************************************/
#include "lpc17xx.h"
#include "../timer/timer.h"
#define SPEEDUP 1

#define TIMERSCALER 1

#define SECOND 0x17D7840 * TIMERSCALER

#define SONG_SEL_LEN 3
#define SONG_RUN_LEN 34
#define SONG_EAT_LEN 15
#define SONG_CUDDLE_LEN 45
#define SONG_BG_LEN 28

#define UPTICKS 1

typedef enum note_durations /*queste le ho prese da "Music for LandTiger*/
{
	time_semibiscroma = (unsigned int)(SECOND * SPEEDUP / 64.0f + 0.5), // 1/128
	time_biscroma = (unsigned int)(SECOND * SPEEDUP / 32.0f + 0.5), // 1/64
	time_semicroma = (unsigned int)(SECOND * SPEEDUP / 16.0f + 0.5), // 1/32
	time_croma = (unsigned int)(SECOND * SPEEDUP / 8.0f + 0.5), // 1/16
	time_semiminima = (unsigned int)(SECOND * SPEEDUP / 4.0f + 0.5), // 1/4
	time_minima = (unsigned int)(SECOND * SPEEDUP / 2.0f + 0.5), // 1/2
	time_semibreve = (unsigned int)(SECOND * SPEEDUP + 0.5), // 1
} note_duration;

typedef enum frequencies
{
	a2b = 5351,	// 103Hz	k=5351 a2b
	b2 = 4500,	// 123Hz	k=4500 b2
	c3b = 4370,	// 127Hz	k)4370 c3b
	c3 = 4240,	// 131Hz	k=4240 c3
	d3 = 3779,	// 147Hz	k=3779 d3
	e3 = 3367,	// 165Hz	k=3367 e3
	f3 = 3175,	// 175Hz	k=3175 f3
	g3 = 2834,	// 196Hz	k=2834 g3
	a3b = 2670, // 208Hz  k=2670 a4b
	a3 = 2525,	// 220Hz	k=2525 a3
	b3 = 2249,	// 247Hz	k=2249 b3
	c4 = 2120,	// 262Hz	k=2120 c4
	d4 = 1890,	// 294Hz	k=1890 d4
	e4 = 1684,	// 330Hz	k=1684 e4
	f4 = 1592,	// 349Hz	k=1592 f4
	g4 = 1417,	// 392Hz	k=1417 g4
	g4b = 1321, // 415Hz  k=1321 g4b
	a4 = 1263,	// 440Hz	k=1263 a4
	b4 = 1125,	// 494Hz	k=1125 b4
	c5 = 1062, 	// 523Hz	k=1062 c5
	pause = 0		// DO NOT SOUND
} FREQUENCY;


typedef struct 
{
	FREQUENCY freq;
	note_duration duration;
} note;

 /*canzoni*/
/* https://onlinesequencer.net/ */
static note songSEL[]={
{c4, time_croma},
{f4, time_croma}
};
static note songCUDDLE[]={
	{a2b, time_croma},
	{a2b, time_croma},
	{pause, time_croma},
	{c3, time_croma},
	{c3, time_croma},
	{pause, time_croma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{pause, time_croma},
	{c3, time_croma},
	{c3, time_croma},
	{pause, time_croma},
	{a2b, time_croma},
	{a2b, time_croma},
	{pause, time_croma},
	{c3, time_croma},
	{c3, time_croma},
	{pause, time_croma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{g4b, time_croma},
	{f4, time_semicroma},
	{c4, time_semicroma},
	{pause, time_croma},
	{c3, time_croma},
	{c3, time_croma},
	{pause, time_croma},
	{a2b, time_croma},
	{a2b, time_croma}
};
static note songEAT[]={
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma},
{f4, time_semicroma},
{c4, time_semicroma},
{c4, time_semicroma},
{g4b, time_croma}
};
static note songBG[]={
{g4, time_semibreve},
{c4, time_semibreve},
{e4, time_semibreve},
{c4, time_semibreve},
{e4, time_semibreve},
{d4, time_semibreve},
{c4, time_semibreve},
{a4, time_semibreve},
{g4, time_semibreve},
{g4, time_semibreve},
{c4, time_semibreve},
{e4, time_semibreve},
{c4, time_semibreve},
{e4, time_semibreve},
{d4, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{c4, time_semibreve},
{g4, time_semibreve},
{a4, time_semibreve},
{c4, time_semibreve},
{c4, time_semibreve},
{a4, time_semibreve},
{g4, time_semibreve},
{g4, time_semibreve},
{c4, time_semibreve},
{e4, time_semibreve},
{c4, time_semibreve},
{e4, time_semibreve},
{d4, time_semibreve},
{c4, time_semibreve},
};
static note songRUN[] = 
{
{c4, time_semibreve},
{c5, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{c5, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{c4, time_semibreve},
{c5, time_semibreve},
{g4b, time_semibreve},
{f4, time_semibreve},
{c5, time_semibreve},
{g4b, time_semibreve},
{f4, time_semibreve},
{c4, time_semibreve},
{c5, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{c5, time_semibreve},
{g4, time_semibreve},
{e4, time_semibreve},
{e4, time_semibreve}, 
{e4, time_biscroma},
{f4, time_semibreve},
{g4b, time_biscroma},
{g4, time_semibreve},
{g4b, time_biscroma},
{a4, time_semibreve},
{c5, time_semibreve}
};
/*funzioni*/
void PlayNote(note nota);
void PlaySong(note* song, int caso);
