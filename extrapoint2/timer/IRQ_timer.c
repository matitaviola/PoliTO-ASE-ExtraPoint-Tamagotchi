/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_timer.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    timer.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "timer.h"
#include "../led/led.h"
#include "../RIT/RIT.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "../Graphics/Graphic_variables.h"
#include "../adc/adc.h"
#include "../Music/Music.h"
#define song_bg_len 19
/******************************************************************************
** Function name:		Timer0_IRQHandler
**
** Descriptions:		Timer/Counter 0 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern unsigned char led_value;					/*manages touch in character pos*/
extern int other_timer;
extern int snack_level;
extern int battery_counter;
extern int is_playing;
volatile int cuddle_counter=0;
#define maxvalue 819 /*valore massimo nella sinusoide di sintable*/
volatile int volume_scaler=maxvalue;
volatile int ticks=0;
volatile int already_cuddling=0;


uint16_t SinTable[45] =                                       /* sinusoide del suono */
{
    410, 467, 523, 576, 627, 673, 714, 749, 778,
    799, 813, 819, 817, 807, 789, 764, 732, 694, 
    650, 602, 550, 495, 438, 381, 324, 270, 217,
    169, 125, 87 , 55 , 30 , 12 , 2  , 0  , 6  ,   
    20 , 41 , 70 , 105, 146, 193, 243, 297, 353
};


void TIMER0_IRQHandler (void)
{
	if(getDisplayPoint(&display, Read_Ads7846(), &matrix)){
		if(display.x>char_x && display.x<(char_x+upscale*character_sheet_size_x) &&
				display.y>char_y && display.y<(char_y+upscale*character_sheet_size_y)){
					cuddle_counter=0;
					other_timer=1;
					enable_timer(1);
					LPC_TIM0->IR = 1;	
					disable_timer(0);
				}
	}
	LPC_TIM0->IR = 1;	
  return;
}


/******************************************************************************
** Function name:		Timer1_IRQHandler
**
** Descriptions:		Timer/Counter 1 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER1_IRQHandler (void)
{
	cuddle_counter++;
	if(snack_level!=5){
		switch(cuddle_counter){//animazione in 4 parti delle coccole
			case(1):{
				is_playing=3;
				PlaySong(songCUDDLE, 3);
				LCD_DrawCuddles(0);
			}break;
			case(9):{
				//delay_ms(15);
				LCD_DrawCuddles(1);
			}break;
			case(17):{
				LCD_DrawCuddles(2);
			}break;
			case(25):{
				LCD_DrawCuddles(3);
			}break;
			case(33):{
				LCD_DrawCuddles(4);
				LCD_DrawRect(0, meal_y, 240, 50, White);
				GUI_Text(0, meal_y, "Albert is happier     ", Black, White);
			}break;
			case(41):{
				snack_level++;
				if(snack_level>5) snack_level=5;
				LCD_DrawBattery(snack_level,battery_row, battery_col, battery_snack_x, battery_snack_y, 2);
				LCD_DrawRect(primo_piano_x, char_y, character_sheet_size_x*(upscale+3), 32*(upscale+3), White);
				LCD_DrawFigure(0, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale); /*character*/
				LCD_DrawRect(0, meal_y, 240, 50, White);
				LCD_DrawButton(meal_x, meal_y, meal_len, meal_height, mealb, Black, White); /*Pulsante Meal*/
				LCD_DrawButton(snack_x, snack_y, snack_len, snack_height, snack, Black, White); /*Pulsante Snack*/
				other_timer=0;
				LPC_TIM1->IR = 1;	
				disable_timer(1);
				enable_timer(0);
			}break;
			default:break;
		}
	}
	else{
		switch(cuddle_counter){//animazione in 4 parti delle coccole
			case(1):{
				LCD_DrawRect(0, meal_y, 240, 50, White);
				GUI_Text(0, meal_y, "Albert is already happy", Black, White);
			}break;
			case(9):{
				LCD_DrawRect(0, meal_y, 240, 50, White);
				LCD_DrawButton(meal_x, meal_y, meal_len, meal_height, mealb, Black, White); /*Pulsante Meal*/
				LCD_DrawButton(snack_x, snack_y, snack_len, snack_height, snack, Black, White); /*Pulsante Snack*/
				other_timer=0;
				LPC_TIM1->IR = 1;	
				disable_timer(1);
				enable_timer(0);
			}break;
			default:break;
		}
	}
  LPC_TIM1->IR = 1;			/* clear interrupt flag */
  return;
}

/******************************************************************************
** Function name:		Timer2_IRQHandler
**
** Descriptions:		Timer/Counter 2 interrupt handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
void TIMER2_IRQHandler (void)
{
	/* DAC management */	
	LPC_DAC->DACR = ((SinTable[ticks])*volume_scaler/maxvalue)<<6;
	ticks++;
	
	if(ticks==45){ 
		ticks=0;
	}

	
  LPC_TIM2->IR = 1;			/* clear interrupt flag */
  return;
}

void TIMER3_IRQHandler (void)
{
	disable_timer(2);
  LPC_TIM3->IR = 1;			/* clear interrupt flag */
  return;
}



/******************************************************************************
**                            End Of File
******************************************************************************/
