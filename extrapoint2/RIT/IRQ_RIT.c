/*********************************************************************************************************
**--------------File Info---------------------------------------------------------------------------------
** File name:           IRQ_RIT.c
** Last modified Date:  2014-09-25
** Last Version:        V1.00
** Descriptions:        functions to manage T0 and T1 interrupts
** Correlated files:    RIT.h
**--------------------------------------------------------------------------------------------------------
*********************************************************************************************************/
#include "lpc17xx.h"
#include "RIT.h"
#include "../GLCD/GLCD.h" 
#include "../TouchPanel/TouchPanel.h"
#include "../Graphics/Graphic_variables.h"
#include "../timer/timer.h"
#include <string.h>
#include "../adc/adc.h"
#include "../Music/Music.h"

/******************************************************************************
** Function name:		RIT_IRQHandler
**
** Descriptions:		REPETITIVE INTERRUPT TIMER handler
**
** parameters:			None
** Returned value:		None
**
******************************************************************************/
extern note songBG[];
volatile int down=0;
volatile int position=0; //inizializzo a -1 perchè al primo movimento somma già +1
volatile int timer_char_refr=0;
volatile int reset=0;
volatile int snack_level=5;
volatile int meal_level=5;
volatile int battery_counter=0;
volatile int8_t secpassed=0;
volatile int8_t minpassed=0;
volatile int8_t hpassed=0;
volatile int i;
volatile char timestr[9]; 
volatile int is_busy=0;
volatile int busy_counter=0;
volatile int timer_counter=0;
volatile int getaway_counter=0;
volatile int is_going=0;
volatile int is_sad=0;
volatile int other_timer=0;
/*suono*/
volatile int songbg_counter=0;
volatile int songsel_counter=0;
volatile int songeat_counter=0;
volatile int songrun_counter=0;
volatile int songcuddle_counter=0;
volatile int is_playing=0;
extern note songBG[];
extern note songSEL[];
extern note songEAT[];
extern note songRUN[];
extern note songCUDDLE[];

/*ti dà una nuova chance*/
void Resetter(void){
	disable_RIT();
	disable_timer(0);
	LCD_Clear(White);
	GUI_Text(75,10, "Age:", Black, White);
	GUI_Text(110,10, "00:00:00", Black, White);
	
	GUI_Text(battery_snack_x, battery_meal_y-15, "Happiness", Black, White);
	GUI_Text(battery_meal_x-10, battery_meal_y-15, "Satiety", Black, White);
	LCD_DrawBattery(5, battery_row, battery_col, battery_snack_x, battery_snack_y, 2);
	LCD_DrawBattery(5, battery_row, battery_col, battery_meal_x, battery_meal_y, 2);
	
	LCD_DrawButton(meal_x, meal_y, meal_len, meal_height, mealb, Black, White); /*Pulsante Meal*/
	LCD_DrawButton(snack_x, snack_y, snack_len, snack_height, snack, Black, White); /*Pulsante Snack*/
	LCD_DrawFigure(0, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale); /*character*/
	
	is_sad=0;
	secpassed=0;
	minpassed=0;
	hpassed=0;
	position=0;
	snack_level=5;
	meal_level=5;
	battery_counter=0;
	timer_char_refr=0;
	is_busy=0;
	busy_counter=0;
	timer_counter=0;
	getaway_counter=0;
	reset=0;
	is_going=0;
	is_playing=0;
	songbg_counter=0;
	songsel_counter=0;
	songeat_counter=0;
	songrun_counter=0;
	songcuddle_counter=0;
	enable_RIT();
	enable_timer(0);
	return;
}

/*gestisce il timer e lo aggiorna*/
void Timer_funct(void){
	secpassed++;
	i=0;
	if(secpassed==60){
		secpassed=0;
		minpassed++;
		if(minpassed==60){
			minpassed=0;
			hpassed++;
			if(hpassed==100){
				hpassed=99;
				minpassed=99;
				secpassed=99;
			}
		}
	}
	sprintf(timestr, "%02d:%02d:%02d", hpassed, minpassed, secpassed);
	LCD_DrawRect(75, 10, 110, 10, White);//pulisco prima di scrivere
	GUI_Text(75,10, "Age:", Black, White);
	GUI_Text(110,10, timestr, Black, White);
};

/*RIT Handler*/
void RIT_IRQHandler(void)
{			
	static int J_sel = 0;
	static int J_left = 0;
	static int J_right = 0;
	
	/*suono*/
	ADC_start_conversion();/*regolazione nota/volume*/
	switch(is_playing){
		case(0):{
			//PlaySong(songBG, 0);
		}break;
		case(1):{
			PlaySong(songSEL, 1);
			if(songsel_counter==0){
				is_playing=0;
			}
		}break;
		case(2):{
			PlaySong(songEAT, 2);
			if(songeat_counter==0){
				is_playing=0;
			}
		}break;
		case(3):{
			PlaySong(songCUDDLE, 3);
			if(songcuddle_counter==0){
				is_playing=0;
			}
		}break;
		case(4):{
					PlaySong(songRUN, 4);
		}break;
		default: is_playing=0; break;
	}

	
	timer_counter++;
	if(is_busy==1){
		busy_counter++;
	}
	/*gestione secondi per il timer*/
	if(reset==0 && timer_counter==20){
		Timer_funct();
		timer_counter=0;
	}
	
	if(other_timer==0){
		timer_char_refr++;
		
		if(is_going==0){
		battery_counter++;
		if(battery_counter>=100 && getaway_counter==0){
			snack_level--;
			meal_level--;
			if(snack_level<=1 || meal_level<=1)
				is_sad=1;
			else
				is_sad=0;
			LCD_DrawBattery(snack_level, battery_row, battery_col, battery_snack_x, battery_snack_y, 2);
			LCD_DrawBattery(meal_level, battery_row, battery_col, battery_meal_x, battery_meal_y, 2);
			if(snack_level==0 || meal_level==0){
				//Runaway sequence
				disable_timer(0);
				is_busy=1;
				reset=1;
				is_going=1;
			}
			battery_counter=0;
		}
	}
			/*runaway sequence*/
		if(is_going==1){ /* se è occupato perchè devo resettare, runaway*/
			getaway_counter++;
			if(getaway_counter==1){
				is_playing=4;
				LCD_DrawFigure(9, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
			}
			if(getaway_counter==10){
				LCD_DrawRect(char_x, char_y, 40, character_sheet_size_y*upscale, White);
				LCD_DrawRect(char_x, char_y-10+character_sheet_size_x*upscale, character_sheet_size_x*upscale, 10, White);
				LCD_DrawFigure(5, character_sheet_size_x, character_sheet_size_y, char_x+40, char_y-10, upscale);
			}
			if(getaway_counter==15){
				LCD_DrawRect(char_x+40, char_y-10, 42, character_sheet_size_y*upscale, White);
				LCD_DrawRect(char_x+40, char_y-10+character_sheet_size_x, character_sheet_size_x*upscale, character_sheet_size_y, White);
				LCD_DrawFigure(5, character_sheet_size_x, character_sheet_size_y, char_x+82, char_y-10, 1);
			}
			if(getaway_counter==19){
				LCD_DrawRect(char_x+80, char_y-10, character_sheet_size_x, character_sheet_size_y, White);
				LCD_DrawRect(char_x+130, char_y-10, 4, 6, Black);
			}
			if(getaway_counter==21){
				LCD_DrawRect(char_x+130, char_y-10, 4, 6, White);
				LCD_DrawRect(0, meal_y, 240, MAX_Y-meal_y, White);
				GUI_Text(0, MAX_Y/2, "You didn't care enough", Black, White);
				GUI_Text(0, MAX_Y/2+20, "Albert went away :(", Black, White);
				GUI_Text(0, MAX_Y/2+40, "Press to get another chance", Black, White);
				LCD_DrawButton(reset_x, reset_y, reset_len, reset_height, redo, Black, White);
				is_busy=0;
			}
		}
		
		/*dimuiscono ogni 5 sec i valori delle batterie*/
		
		/*gestione is busy per 1 sec, gestisce l'animazione del nutrirsi*/
		if(is_busy==1 && reset==0){
			switch(busy_counter){
				case(2):{ //va verso il cibo
					is_playing=2;
					if(position==0){
						LCD_DrawRect(char_x, char_y, character_sheet_size_x*upscale, character_sheet_size_y*upscale, White);
						LCD_DrawFigure(0, character_sheet_size_x, character_sheet_size_y, char_x-30, char_y+30, upscale);
					}
					else{
						LCD_DrawRect(char_x, char_y, character_sheet_size_x*upscale, character_sheet_size_y*upscale, White);
						LCD_DrawFigure(4, character_sheet_size_x, character_sheet_size_y, char_x+30, char_y+30, upscale);
					}
				}break;
				case(7):{
					if(position==0){//primo morso
						LCD_DrawRect(char_x-30, char_y+30, character_sheet_size_x*upscale+15, 15, White);
						LCD_DrawRect(char_x-30+character_sheet_size_x*upscale-15, char_y+30, 15, character_sheet_size_x*upscale+20, White);
						LCD_DrawFigure(3, character_sheet_size_x, character_sheet_size_y, char_x-45, char_y+45, upscale);
						LCD_DrawFood(1,food_size, food_size, meal_an_x, meal_an_y, upscale);
					}
					else{
						LCD_DrawRect(char_x+30, char_y+30, character_sheet_size_x*upscale+15, 15, White);
						LCD_DrawRect(char_x+30, char_y+30, 15, character_sheet_size_x*upscale+15, White);
						LCD_DrawFigure(4, character_sheet_size_x, character_sheet_size_y, char_x+45, char_y+45, upscale);
						LCD_DrawFood(4,food_size, food_size, snack_an_x, snack_an_y, 2);
					}
				}break;
				case(12):{//secondo morso
					if(position==0){
						LCD_DrawFood(2,food_size, food_size, meal_an_x, meal_an_y, upscale);
						LCD_DrawBattery(meal_level, battery_row, battery_col, battery_meal_x, battery_meal_y, 2);
					}
					else{
						LCD_DrawFood(5,food_size, food_size, snack_an_x, snack_an_y, 2);
						LCD_DrawBattery(snack_level, battery_row, battery_col, battery_snack_x, battery_snack_y, 2);
					}
				}break;
				case(17):{ //cibo finito, ricarico la pila
					if(position==0){
						LCD_DrawRect(meal_an_x, meal_an_y, food_size*upscale, food_size*upscale, White);
						GUI_Text(0, meal_y, "Its satiety went up       ", Black, White);
					}
					else{
						LCD_DrawRect(snack_an_x, snack_an_y, food_size*2, food_size*2, White);
						GUI_Text(0, meal_y, "Its happiness went up     ", Black, White);
					}
				}break;
				case (22):{//torna a posto
					if(position==0){
						LCD_DrawRect(char_x-45, char_y+45, character_sheet_size_x*upscale, character_sheet_size_x*upscale, White);
						LCD_DrawFigure(0, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
					}
					else{
						LCD_DrawRect(char_x+45, char_y+45, character_sheet_size_x*upscale, character_sheet_size_x*upscale, White);
						LCD_DrawFigure(0, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
					}
					timer_char_refr=0; //ricomincia l'animazione del pg
				}break;
				case (23):{
					LCD_DrawRect(0, meal_y, 240, 50, White);
					LCD_DrawButton(meal_x, meal_y, meal_len, meal_height, mealb, Black, White); /*Pulsante Meal*/
					LCD_DrawButton(snack_x, snack_y, snack_len, snack_height, snack, Black, White); /*Pulsante Snack*/
					is_busy=0;
					busy_counter=0;
					enable_timer(0); //finita l'animazione, non è più busy e torna il touch
				}break;
				default:break;
			}
			
		}
		
		/*gestion secondi per il pg*/
		if(reset==0 && is_busy==0){
			switch(timer_char_refr){
				case 1: //appena parte
				{
					if(is_sad==0)
						LCD_DrawFigure(8, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
					else
						LCD_DrawFigure(6, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
				}break;
				case 5: //passato 1/4 sec, è la fase che dura di meno
				{
					if(is_sad==0)
						LCD_DrawFigure(1, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
				}break;
				case 10: //passato 1/2 sec
				{
					if(is_sad==0)
						LCD_DrawFigure(2, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
					else
						LCD_DrawFigure(7, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
				}break;
				case 15: //passati 3/4 sec, torno alla pic intermedia
				{
					if(is_sad==0)
						LCD_DrawFigure(1, character_sheet_size_x, character_sheet_size_y, char_x, char_y, upscale);
				}break;
				case 20: //dopo altri 0,25 sec, è il momento di rifare da capo
				{
					timer_char_refr=0;
				}
				default:break;
			}
		}
		
		
		/*polling per il joystick*/
		if((LPC_GPIO1->FIOPIN & (1<<25)) == 0){	
			/* Joystick Select pressed p1.25*/
			J_sel++;
			if(is_busy==0){ //mentre è busy, ignoro il joystick
				switch(J_sel){
					case 1:
					{
						disable_timer(0);  // se ho selezionato qualcosa non posso usare il touch
						is_playing=1;
						if(reset==1){
							LCD_DrawButton(reset_x, reset_y, reset_len, reset_height, redo, Red, White);
							Resetter();
						}
						else if (position==0 && reset==0){
							LCD_DrawRect(0, meal_y, 240, 50, White);
							is_busy=1;
							if(meal_level<5){
								LCD_DrawFood(0,food_size, food_size, meal_an_x, meal_an_y, upscale);
								meal_level++;
								if(meal_level==1)
										timer_char_refr=0;
								GUI_Text(meal_x, meal_y, mealmess, Black, White);
								busy_counter=0;
							}
							else{
								GUI_Text(meal_x, meal_y, "It's already full :)", Black, White);
								busy_counter=22; //se non faccio l'animazione lascio il messaggio per poco
							}
						}
						else{
							LCD_DrawRect(0, meal_y, 240, 50, White);
							is_busy=1;
							if(snack_level<5){
								LCD_DrawFood(3,food_size, food_size, snack_an_x, snack_an_y, 2);
								snack_level++;
								if(snack_level==1)
										timer_char_refr=0;
								GUI_Text(meal_x, meal_y, snackmess, Black, White);
								busy_counter=0;
							}
							else{
								GUI_Text(meal_x, meal_y, "It's already so happy :)", Black, White);
								busy_counter=22;//se non faccio l'animazione lascio il messaggio per poco
							}
						}
					}
						break;
					default:
						break;
				}
			}
		}else{
				J_sel=0;
		}

		if((LPC_GPIO1->FIOPIN & (1<<27)) == 0){
			/* Joystick Left pressed p1.27 */
			J_left++;
			if(is_busy==0){ //se non sta mangiando
				switch(J_left){
					case 1:{
						if(reset==0){
							position=0;
							LCD_DrawButton(snack_x, snack_y, snack_len, snack_height, snack, Black, White);
							LCD_DrawButton(meal_x, meal_y, meal_len, meal_height, mealb, Red, White);
						}
					}break;
					default: break;
				}
			}
		}else{
				J_left=0;
		}
		
		if((LPC_GPIO1->FIOPIN & (1<<28)) == 0){
			/* Joystick Right pressed p1.28 */
			J_right++;
			if(is_busy==0){ //se non sta mangiando
				switch(J_right){
					case 1:{
						if(reset==0){
							position=1;
							LCD_DrawButton(meal_x, meal_y, meal_len, meal_height, mealb, Black, White);
							LCD_DrawButton(snack_x, snack_y, snack_len, snack_height, snack, Red, White);
						}
					}break;
					default: break;
				}
			}
		}else{
				J_right=0;
		}
		
		
		
	}
	LPC_RIT->RICTRL |= 0x1;	/* clear interrupt flag */
	
  return;
}


/******************************************************************************
**                            End Of File
******************************************************************************/
