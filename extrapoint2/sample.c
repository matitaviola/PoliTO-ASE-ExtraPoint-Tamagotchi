/****************************************Copyright (c)****************************************************
**                                      
**                                 http://www.powermcu.com
**
**--------------File Info---------------------------------------------------------------------------------
** File name:               main.c
** Descriptions:            The GLCD application function
**
**--------------------------------------------------------------------------------------------------------
** Created by:              AVRman
** Created date:            2010-11-7
** Version:                 v1.0
** Descriptions:            The original version
**
**--------------------------------------------------------------------------------------------------------
** Modified by:             Paolo Bernardi
** Modified date:           03/01/2020
** Version:                 v2.0
** Descriptions:            basic program for LCD and Touch Panel teaching
**
*********************************************************************************************************/

/* Includes ------------------------------------------------------------------*/
#include "LPC17xx.h"
#include "GLCD/GLCD.h" 
#include "TouchPanel/TouchPanel.h"
#include "timer/timer.h"
#include "joystick/joystick.h"
#include "RIT/RIT.h"
#include "adc/adc.h"

#define SIMULATOR 1

#ifdef SIMULATOR
extern uint8_t ScaleFlag; // <- ScaleFlag needs to visible in order for the emulator to find the symbol (can be placed also inside system_LPC17xx.h but since it is RO, it needs more work)
#endif


int main(void)
{
  SystemInit();  												/* System Initialization (i.e., PLL)  */
	
  LCD_Initialization();
	
  
	TP_Init();
	TouchPanel_Calibrate();
	
	joystick_init();	
	//init_RIT(0x000F4240); //	1/5 del tempo effettivo, usato per i test e video a causa di problemi con la velocità dell'emulatore
	init_RIT(0x004C4B40);									/* RIT Initialization 50 msec, K=50msec*100MHz, usato per testare sulla scheda la velocità di disegno*/
	//init timer_0 per il TP
	init_timer(0, 0, 0, 3, 0xC8); /*8 microsec *25MHz = 200 =0xc8*/
	init_timer(1, 0, 0, 3, 0x1312D0); /*il timer_1 è usato per le coccole e triggera ogni 50ms dopo che hai usato il touch*/
	/*setto i timer del touch a livello di priorità più basso della musica*/
	NVIC_SetPriority(TIMER0_IRQn, 1);
	NVIC_SetPriority(TIMER1_IRQn, 1);
	Resetter();
	ADC_init();
	
	LPC_SC->PCON |= 0x1;									/* power-down	mode*/
	LPC_SC->PCON &= ~(0x2);						
	
	LPC_PINCON->PINSEL1 |= (1<<21);				/*output dac*/
	LPC_PINCON->PINSEL1 &= ~(1<<20);
	LPC_GPIO0->FIODIR |= (1<<26);
	
  while (1)	
  {
		__ASM("wfi");
  }
}

/*********************************************************************************************************
      END FILE
*********************************************************************************************************/
