/***********************************************************************
Il file contine le variabili usate per la grafica, come pulsanti, posizioni, immagini della creaturina
************************************************************************/
#include "../GLCD/GLCD.h"
//sizes and offsets
#define upscale 2
#define character_sheet_size_x 44
#define character_sheet_size_y 44
#define tail_size_x 16
#define tail_size_y 12
#define eyes_size_x 9 
#define eyes_size_y 16 
#define mouth_size_x 3 
#define mouth_size_y 8 
#define meal_mouth_size_x 5
#define meal_mouth_size_y 12
#define mouth_offset_x 8
#define mouth_offset_y 26
#define meal_mouth_offset_x 8
#define meal_mouth_offset_y 25 
#define eyes_offset_x 5 
#define eyes_offset_y 14
#define tail_offset_x 31
#define tail_offset_y 20
#define food_size 16
#define battery_snack_x 5
#define battery_meal_x 190
#define battery_snack_y 45
#define battery_meal_y 45
#define battery_row 20
#define battery_col 20
#define meal_x 5
#define meal_y 270
#define meal_len 110
#define meal_height 40
#define snack_x  125
#define snack_y 270
#define snack_len 110
#define snack_height 40
#define reset_x  5
#define reset_y 270
#define reset_len 230
#define reset_height 40
#define meal_an_x 0 
#define meal_an_y 210 
#define snack_an_x 208  //(MAX_X-32)
#define snack_an_y 210 
#define heart_offset_1 0
#define heart_offset_2 150
#define heart_sheet_x 15
#define heart_sheet_y 10
#define audio_size 15
#define audio_x 0
#define audio_y 2
#define primo_piano_x 32
/****character animation****/
static int char_x=MAX_X/2-character_sheet_size_x;
static int char_y=100;
/*posa di base e bocca/coda*/
static uint16_t character_animation_1[44][44] = {
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, Black, Black, Black, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, Black, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, Black, Black, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, Black, Black, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, White, Black, White, White, Black, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, White, White, White, Black, White, White, White, White, Black, White, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, White, White, White, Black, White, White, White, White, Black, White, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, White, White, White, Black, Black, White, White, Black, Black, White, White, White, Black, Black, White, White, Black, Black, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, Black, White, White, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, Black, Black, White, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, White, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White},
{White, Black, Black, Black, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, White},
{White, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, Black, Black, White, White, White, White, Black, White, White, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, Black, White, White, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, Black, Black, Black, White, White, White, Black, White, White, White},
{White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, Black, Black, White, White, Black, White, White, White, White},
{White, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White},
{White, Black, White, White, White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White},
{White, Black, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, White, Black, Black, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, Black, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, Black, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
static uint16_t character_mouth_1[3][8]={
{White, Black, Black, Black, Black, Black, Black, White},
{White, White, Black, Black, Black, Black, White, White},
{White, White, White, Black, Black, White, White, White}
};
static uint16_t character_tail_1 [16][12]={
{Black, White, White, White, White, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, White, White, White, White, White, Black, Black, Black, White, White},
{Black, Black, White, White, White, Black, Black, White, White, White, Black, White},
{Black, Black, White, White, Black, Black, White, White, White, White, Black, White},
{Black, Black, Black, Black, Black, Black, Black, White, White, White, Black, White},
{Black, Black, Black, White, Black, Black, Black, White, White, White, Black, White},
{White, White, White, White, White, Black, Black, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, Black, Black, White, White, White, White},
{Black, White, White, White, Black, Black, White, White, White, White, White, White},
{Black, Black, Black, Black, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White}
};

static uint16_t character_eyes_base [9][16]={
{White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White,White},
{White, Black, White, White, Black, White, White, White, White, White, Black, White, White, Black, White,White},
{Black, White, White, White, White, Black, White, White, White, Black, White, White, White, White, Black,White},
{Black, White, White, White, White, Black, White, White, White, Black, White, White, White, White, Black,White},
{Black, Black, White, White, Black, Black, White, White, White, Black, Black, White, White, Black, Black,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White,White},
{White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White,White}
};
static uint16_t character_mouth_2[3][8]={
{White, Black, White, White, White, White, Black, White},
{White, White, Black, Black, Black, Black, White, White},
{White, White, White, Black, Black, White, White, White}
};
static uint16_t character_tail_2 [16][12]={
{Black, White, White, White, White, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, White, White, White, White, White, White, White, White, White, White},
{Black, Black, White, White, White, White, White, White, White, White, White, White},
{Black, Black, Black, Black, Black, White, White, White, Black, Black, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, White, White, Black, White},
{White, White, Black, Black, Black, White, Black, Black, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, Black, Black, White, White, White, White},
{Black, White, White, Black, Black, Black, White, White, White, White, White, White},
{Black, Black, Black, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White},
};

/*char 3*/
static uint16_t character_mouth_3[3][8]={
{White, Black, White, White, White, White, Black, White},
{White, White, Black, Black, Black, Black, White, White},
{White, White, White, White, White, White, White, White}
};
static uint16_t character_tail_3 [16][12]={
{Black, White, White, White, White, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, White, White, White, White, White, White, White, White, White, White},
{Black, Black, White, White, White, White, White, White, White, White, White, White},
{Black, Black, Black, White, White, White, White, White, White, White, White, White},
{White, Black, Black, Black, White, White, White, White, White, White, White, White},
{White, White, White, Black, Black, White, White, White, White, White, White, White},
{White, White, White, Black, Black, Black, White, White, White, White, White, White},
{White, White, Black, Black, Black, Black, Black, White, White, White, White, White},
{White, White, Black, Black, Black, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, White, Black, Black, Black, Black, White},
{Black, White, White, White, White, White, White, White, Black, White, Black, Black},
{Black, White, White, White, White, White, White, White, White, White, White, Black},
{White, Black, Black, Black, White, White, White, White, White, White, Black, Black},
{White, White, White, White, Black, Black, Black, White, White, White, Black, Black},
{White, White, White, White, White, White, White, Black, Black, Black, Black, White}
};
/*meal*/
static uint16_t character_eyes_meal [9][16]={
{White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White,White},
{White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{Black, Black, White, Black, Black, Black, White, White, White, Black, Black, White, Black, Black, Black,White},
{Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black,White},
{Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black,White},
{Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black,White},
{White, Black, White, Black, Black, White, White, White, White, White, Black, White, Black, Black, White,White},
{White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White,White}
};
static int meal_mouth [5][12]={
{White, White, White, White, White, White, White, Black, White, White, White, Black},
{Black, Black, Black, Black, Black, Black, White, Black, White, White, White, Black},
{White, White, Black, Black, Black, Black, White, White, Black, Black, Black, White},
{White, White, White, Black, Black, Black, White, White, White, White, White, White},
{White, White, White, White, Black, Black, White, White, White, White, White, White}
};


/*snack*/
static uint16_t character_snack [44][44]={
	{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, Black, Black, Black, White, Black, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, Black, White, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, Black, Black, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, Black, Black, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, Black, Black, Black, White, Black, Black, White, White, White, Black, Black, Black, White, Black, Black, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, Black, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, Black, White, Black, Black, Black, Black, Black, White, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, Black, Black, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, Black, White, White, White, White, White, Black, Black, White, Black, White, White, Black, Black, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, Black, White},
{White, White, White, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, White, White, Black, Black, Black, Black, Black, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, White, White, Black, Black, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White},
{White, White, Black, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, White, Black, Black, Black, Black, Black, Black, White, White, White, White, Black, Black, Black, White},
{White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, Black, Black, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, Black, Black, White, White, White, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, White, Black, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, Black, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};

/*la coda di sad è quella di 3, verso il basso*/
static int character_mouth_sad [3][8]={
{White, White, Black, Black, Black, Black, White, White},
{White, Black, White, White, White, White, Black, White},
{Black, White, White, White, White, White, White, Black}
};

static int character_eyes_sad_1[9][16]={
{White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White,White},
{White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black,White},
{Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black,White},
{Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black,White},
{White, Black, White, White, Black, White, White, White, White, White, Black, White, White, Black, White,White},
{Black, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, Black,White}
};
static int character_eyes_sad_2[9][16]={
{White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White,White},
{White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black,White},
{Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black,White},
{Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black,White},
{Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black,White},
{White, Black, White, White, Black, White, White, White, White, White, Black, White, White, Black, White,White},
{Black, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, Black,White}
};
/*runaway*/
static uint16_t character_gone [44][44]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, Black, Black, White, White, Black, White, Black, Black, White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White},
{White, Black, Black, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, Black, Black, Black, White, Black, White, White, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, White, White, Black, Black, Black, White, Black, White, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White, Black, Black, White, White, Black, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, White, Black, White, White, White, White, Black, Black, White, White, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, White, White, White, White, White, White, White},
{Black, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White},
{Black, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White},
{White, Black, Black, Black, White, White, White, White, Black, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White},
{White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, Black, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, White, White, Black, Black, Black, Black, Black, White, White, Black, Black, Black, Black, Black, Black, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, White, White, Black, Black, White, Black, Black, Black, White, White, White, White, Black, Black, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White},
{White, White, Black, White, White, White, White, White, White, Black, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White},
{White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, Black, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, Black, Black, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, Black, White, White, Black, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, Black, White, White, White, Black, Black, Black, Black, White, White, Black, Black, Black, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, Black, Black, White, White, White, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, White, Black, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, Black, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};

static uint16_t character_gone_front[44][44]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, Black, Black, Black, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, Black, White, Black, Black, Black, White, White, White, White, White, White, White, White, Black, White, Black, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, White, White, White, White, White, Black, White, White, White, White, Black, Black, White, White, White, White, White, White},
{White, White, White, White, Black, Black, Black, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, Black, Black, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, White, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, White, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, Black, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, Black, Black, Black, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, White, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White},
{White, Black, Black, Black, White, White, Black, White, White, Black, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, Black, White, White, White, Black, Black, White, White, White, Black, White, White, White},
{White, Black, White, White, White, Black, White, Black, Black, White, White, White, White, White, White, White, Black, Black, White, Black, White, White, White, White, White, Black, White, White, White, White, Black, Black, White, White, Black, Black, White, White, White, White, Black, White, White, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, Black, White, White, White},
{White, Black, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, Black, White, White, White, Black, Black, Black, Black, Black, White, Black, Black, Black, White, White, White, Black, White, White, White},
{White, Black, Black, Black, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, Black, Black, White, White, Black, White, White, White, White},
{White, Black, Black, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White},
{White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White},
{White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, White, White, White, White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, White, Black, Black, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, Black, White, Black, Black, Black, Black, White, White, White, White, White, White, White, White, White, Black, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, Black, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};

/*food animation*/
static uint16_t meal1 [16][16]={{White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White},
{
White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White},
{
White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White},
{
White, White, White, White, White, Black, Black, Black, Black, Black, White, White, White, White, White, White},
{
White, White, White, White, Black, White, White, White, White, White, Black, White, White, White, White, White},
{
White, White, White, White, Black, White, White, White, White, White, Black, White, White, White, White, White},
{
White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White},
{
White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White},
{
White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White},
{
White, White, White, Black, Black, White, White, White, White, White, White, Black, Black, White, White, White},
{
White, White, Black, White, White, Black, White, White, White, White, Black, White, White, Black, White, White},
{
White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White},
{
White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{
White, White, Black, Black, White, White, Black, Black, Black, Black, White, White, Black, Black, White, White},
{
White, White, White, White, Black, Black, White, White, White, White, Black, Black, White, White, White, White},
{
White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White}
};
static uint16_t meal2 [16][16]={{White, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, Black, White, White, White, White, White, White, White, White},
{White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White},
{White, White, White, White, Black, White, White, White, Black, White, White, White, White, White, White, White},
{White, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White, White},
{White, White, White, Black, White, White, White, White, White, Black, Black, White, White, White, White, White},
{White, White, White, Black, White, White, White, White, White, White, White, Black, White, White, White, White},
{White, White, White, Black, Black, White, White, White, White, White, Black, White, White, White, White, White},
{White, White, Black, White, White, Black, White, White, White, White, White, Black, White, White, White, White},
{White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, Black, White, White, Black, Black, Black, Black, White, White, Black, Black, White, White},
{White, White, White, White, Black, Black, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White}
};
static uint16_t meal3 [16][16]={{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, Black, Black, White, Black, White, White, White, White, White, White, White, White, White},
{White, White, Black, White, White, Black, White, Black, White, White, White, White, White, White, White, White},
{White, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, Black, White, White, Black, Black, Black, Black, White, White, Black, Black, White, White},
{White, White, White, White, Black, Black, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White}
};
static uint16_t snack1 [16][16]={
{White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White},
{White, White, White, White, Black, Black, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, Black, White, White, Black, White, White, White, White, White, Black, White, White, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, Black, White, White, White, White, White, White, White, Black, Black, White, White, White, Black, White},
{White, Black, White, White, Black, White, White, White, White, White, White, White, White, White, Black, White},
{Black, White, White, White, Black, White, White, Black, Black, White, White, White, White, White, White, Black},
{Black, White, White, White, White, White, White, White, White, White, White, White, Black, White, White, Black},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black},
{Black, White, White, White, White, White, White, White, Black, White, White, White, White, White, White, Black},
{White, Black, White, White, Black, White, White, Black, White, White, Black, White, White, White, Black, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, Black, White, White, Black, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, Black, Black, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, Black, Black, Black, Black, White, White, 0xFFFF, 0xFFFF, 0xFFFF, White}
};
static uint16_t snack2 [16][16]={
{White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White},
{White, White, White, White, White, Black, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, Black, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, White, White, Black, White, White, White, White, White, Black, White, White},
{White, White, White, White, White, White, Black, White, White, Black, Black, White, White, White, Black, White},
{White, White, White, White, White, Black, White, White, White, White, White, White, White, White, Black, White},
{White, White, White, White, White, Black, White, Black, Black, White, White, White, White, White, White, Black},
{White, Black, White, White, Black, White, White, White, White, White, White, White, Black, White, White, Black},
{Black, White, Black, White, Black, White, White, White, White, White, White, White, White, White, White, Black},
{Black, White, White, Black, White, White, White, White, Black, White, White, White, White, White, White, Black},
{White, Black, White, White, Black, White, White, Black, White, White, Black, White, White, White, Black, White},
{White, Black, White, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{White, White, Black, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{White, White, White, Black, White, White, Black, White, White, White, White, White, Black, White, White, White},
{White, White, White, White, Black, Black, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White}
};

static uint16_t snack_3 [16][16]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, 0xFFFF, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, Black, Black, White, White, White, White},
{White, White, White, White, White, White, White, White, White, Black, White, White, Black, Black, Black, White},
{White, White, White, Black, White, Black, White, White, White, Black, White, White, White, White, Black, White},
{White, White, White, White, White, White, White, White, Black, White, Black, White, White, Black, White, White},
{Black, Black, White, White, White, White, Black, Black, White, White, White, White, Black, White, White, White},
{White, White, White, White, White, Black, White, White, White, White, Black, Black, White, White, Black, White},
{White, White, Black, White, White, White, Black, Black, Black, Black, White, White, White, White, White, White}
};
/*cuddles*/
static uint16_t heart_purple[heart_sheet_x][heart_sheet_y]={
	{White, Black, Black, White, White, White, White, Black, Black, White},
	{White, Black, Black, White, White, White, White, Black,Black, White}, 
	{Black, Purple, Purple, Black, White, White, Black, Purple, Purple, Black},
	{Black, Purple, Purple, Black, White, White, Black, Purple, Purple, Black},
	{Black, Purple, Purple, Purple, Black, Black, Purple, Purple, Purple, Black},
	{Black, Purple, Purple, Purple, Purple, Purple, Purple, Purple, Purple, Black},
	{Black, Purple, Purple, Purple, Purple, Purple, Purple, Purple, Purple, Black},
	{White, Black, Purple, Purple, Purple, Purple, Purple, Purple, Black, White},
	{White, Black, Purple, Purple, Purple, Purple, Purple, Purple, Black, White},
	{White, Black, Purple, Purple, Purple, Purple, Purple, Purple, Black, White},
	{White, White, Black, Purple, Purple, Purple, Purple, Black, White, White},
	{White, White, White, Black, Purple, Purple, Black, White, White, White},
	{White, White, White, Black, Purple, Purple, Black, White, White, White},
	{White, White, White, White, Black, Black, White, White, White, White},
	{White, White, White, White, Black, Black, White, White, White, White}
};
static uint16_t heart_yellow[heart_sheet_x][heart_sheet_y]=	{
	{White, Black, Black, White, White, White, White, Black, Black, White},
	{White, Black, Black, White, White, White, White, Black,Black, White}, 
	{Black, Yellow, Yellow, Black, White, White, Black, Yellow, Yellow, Black},
	{Black, Yellow, Yellow, Black, White, White, Black, Yellow, Yellow, Black},
	{Black, Yellow, Yellow, Yellow, Black, Black, Yellow, Yellow, Yellow, Black},
	{Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black},
	{Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black},
	{White, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, White},
	{White, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, White},
	{White, Black, Yellow, Yellow, Yellow, Yellow, Yellow, Yellow, Black, White},
	{White, White, Black, Yellow, Yellow, Yellow, Yellow, Black, White, White},
	{White, White, White, Black, Yellow, Yellow, Black, White, White, White},
	{White, White, White, Black, Yellow, Yellow, Black, White, White, White},
	{White, White, White, White, Black, Black, White, White, White, White},
	{White, White, White, White, Black, Black, White, White, White, White}
};
/*buttons*/
static uint8_t mealb[] = "MEAL";
static uint8_t snack[] = "SNACK";
static uint8_t redo[] = "  RESET";
static uint8_t mealmess[] = "You gave him a good meal";
static uint8_t snackmess[] = "You gave him a cookie";
/*batteries*/
static uint16_t battery_0[20][20]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, White, White, White},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, White, White, White, Red, White, Red, White, White, White, Red, White, Red, White, White, White, White, White, Red, White},
{Red, White, White, White, White, Red, White, White, White, White, White, Red, White, White, White, White, White, White, Red, Red},
{Red, White, White, White, Red, White, Red, White, White, White, Red, White, Red, White, White, White, White, White, Red, Red},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, White, White, White, White, White, Red, Red, Red, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, White, White, White, White, Red, White, White, White, Red, White, White, White, White, White, White, White, Red, White},
{Red, White, White, White, White, Red, White, White, White, White, White, Red, White, White, White, White, White, Red, White, White},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
static uint16_t battery_1[20][20]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, White, White, White},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, Red},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White},
{Red, White, Red, Red, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Red, White, White},
{Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, Red, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
static uint16_t battery_2[20][20]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
static uint16_t battery_3[20][20]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, White, White, White, White, White, White, Black, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
static uint16_t battery_4[20][20]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, White, White, White, Black, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
static uint16_t battery_5[20][20]={
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, Black, White, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, Black},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, White, Black, White},
{Black, White, Red, Red, White, Orange, Orange, White, Yellow, Yellow, White, LightGreen, LightGreen, White, Green, Green, White, Black, White, White},
{Black, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, Black, White, White},
{Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, Black, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White},
{White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White, White}
};
/*audio*/
static uint16_t volume_4[15][15]={
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,Black,Black,White,Black,Black,White},
{White,White,White,White,White,Black,Black,Black,White,Black,White,Black,White,Black,White},
{White,White,White,White,Black,Black,Black,Black,White,Black,White,White,White,Black,White},
{White,Black,Black,Black,Black,Black,Black,Black,White,White,White,Black,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,Black,Black,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,White,Black,White,Black,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,Black,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,Black,White,Black,White,White},
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
};
static uint16_t volume_3[15][15]={
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,Black,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,Black,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,Black,White,White,Black,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,Black,White},
{White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,Black,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,Black,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,Black,White},
{White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,Black,White},
{White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,Black,White},
{White,White,White,White,White,Black,Black,Black,White,Black,White,White,Black,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,Black,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,Black,White,White,White,White},
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
};
static uint16_t volume_2[15][15]={
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,Black,White,White,White,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,Black,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,Black,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
};
static uint16_t volume_1[15][15]={
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,White,White,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,Black,White,White,White,White,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
};
static uint16_t volume_0[15][15]={
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,White,Black,White,White,White,White},
{Black,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{White,Black,Black,Black,Black,Black,Black,Black,White,Black,White,Black,White,White,White},
{White,White,White,White,Black,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,Black,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,Black,Black,White,White,White,White,White,White,White},
{White,White,White,White,White,White,White,White,White,White,White,White,White,White,White},
};
