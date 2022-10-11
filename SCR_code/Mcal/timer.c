/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  timer.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "DIO.h"
#include "Mcu_Hw.h"
#include "timer.h"




/**********************************************************************************************************************
*  LOCAL MACROS CONSTANT\FUNCTION
*********************************************************************************************************************/	

/**********************************************************************************************************************
 *  LOCAL DATA 
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL DATA
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  LOCAL FUNCTIONS
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  GLOBAL FUNCTIONS
 *********************************************************************************************************************/
void sys_timer_init(uint32 relaod_value)
{
	
	     /*Disable the systick timer to re configure*/
	clear_bit_BAND_PREF_D((SYSTEM_TIMER_BASE+SCTRL_OFFSET),ENABLE_BIT);      /*Atomic intruction*/
	clear_bit_BAND_PREF_D((SYSTEM_TIMER_BASE+SCTRL_OFFSET),INTEN_BIT);      /*Atomic intruction*/
	clear_bit_BAND_PREF_D((SYSTEM_TIMER_BASE+SCTRL_OFFSET),CLK_SRC_BIT);    /*Atomic intruction*/
	
	
	
	
	    /*this is the relaod value for the counter*/
	(*(volatile uint32*)(SYSTEM_TIMER_BASE+STRELOAD_OFFSET))=relaod_value-1;
	
	
	
	    /*this step is to claer the current value of the timer and also clearig the timer flag*/
	(*(volatile uint32*)(SYSTEM_TIMER_BASE+STCURRENT_OFFSET))=0;
	
	    /*Enable the systick timer after accutate configuration*/
	set_bit_BAND_PREF_D((SYSTEM_TIMER_BASE+SCTRL_OFFSET),ENABLE_BIT);      /*Atomic intruction to enable the system tick*/
	set_bit_BAND_PREF_D((SYSTEM_TIMER_BASE+SCTRL_OFFSET),INTEN_BIT);      /*Atomic intruction to enable the interrupt after finishing count*/
	set_bit_BAND_PREF_D((SYSTEM_TIMER_BASE+SCTRL_OFFSET),CLK_SRC_BIT);    /*Atomic intruction to select the timer source signal to be the system freq*/
	
	
	
	
	
}

void SysTick_Handler(void)
{
	GPIO_PORTF_DATA_R ^=2;
}





/**********************************************************************************************************************
 *  END OF FILE: timer.c
 *********************************************************************************************************************/
