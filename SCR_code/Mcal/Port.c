/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  port.c
 *        \brief  Nested Vector Interrupt Controller Driver
 *
 *      \details  The Driver Configure All MCU interrupts Priority into gorups and subgroups
 *                Enable NVIC Interrupt Gate for Peripherals
 *
 *********************************************************************************************************************/

/**********************************************************************************************************************
 *  INCLUDES
 *********************************************************************************************************************/
#include "Port.h"



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
 void Port_Init(const Port_ConfigType *ConfigPtr)
{
  Port_PinType config_Pin;
	Port_PinDirectionType Pin_Dir;
	Port_PinModeType Pin_Mode;
	Port_PinInternalAttachType Internal_Res;
	
	uint8 Port_num, Pin_num, looper;

    for (looper = 0; looper < 6; looper++)
	{

		config_Pin = ConfigPtr[looper].Pin;
		Pin_Dir = ConfigPtr[looper].Dir;
		Pin_Mode = ConfigPtr[looper].Mode;
		Internal_Res = ConfigPtr[looper].Attach;

        for(looper=0;looper<6;looper++)
        {
            config_Pin = ConfigPtr[looper].Pin;
		        Pin_Dir = ConfigPtr[looper].Dir;
		        Pin_Mode = ConfigPtr[looper].Mode;
		        Internal_Res = ConfigPtr[looper].Attach;
            Port_num=config_Pin/8;
            Pin_num=config_Pin%8;
						
					/*Start by unlovking the port is going to be confired to allow read & write opperations*/
					(*((volatile uint32 *)(PORT_APB_BASE_ADDRESS[Port_num] + GPIOLOCK_OFFSET)))=Magic_value;
					
					/*intiate the clock on the pin*/
					set_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIOCR_OFFSET),Pin_num);  
        }
        if (Pin_Dir == PORT_PIN_OUT)
        {
					/*set the pin in Direction register by bit banding (Atomic operation)*/
					set_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num]+ GPIODIR_OFFSET),Pin_num);
        }
		else if (Pin_Dir == PORT_PIN_IN)
        {
					/*clear the Direction bit by bit banding (Aomic operation)*/
					clear_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIODIR_OFFSET),Pin_num);
        }
        else
        {
            /*Retrun error message with assertion */
        }

		if (Internal_Res == PULLUP && Pin_Dir == PORT_PIN_IN)
        {
			    /*Activte the internal pull up resistor by seting the PULLUP bit (Atomic operation)*/
					set_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIOPUR_OFFSET),Pin_num);
        }
		else if (Internal_Res == PULLDOWN && Pin_Dir == PORT_PIN_IN)
        {
				 /*Activte the internal pull down resistor by seting the PULL DOWN bit (Atomic operation)*/
					set_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIOPDR_OFFSET),Pin_num);
        }
		else if (Internal_Res == OPENDRAIN && Pin_Dir == PORT_PIN_OUT)
        {
			    /*Activte the open drain mode by seting the OODR bit (Atomic operation)*/
					set_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIOODR_OFFSET),Pin_num);
        }
        else
        {
            /*Retrun error message with assertion */
        }

		if (Pin_Mode == Digital)
		{

			/*Set the Bit number in the GPIODEN to choose the Digital Mode (DIO) (atomic operation)*/
			set_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIODEN_OFFSET),Pin_num);

			/*clear the Bit number in the AFSEL to choose the Digital Mode (DIO) (atomic operation)*/
			clear_bit_BAND_PREF_D((PORT_APB_BASE_ADDRESS[Port_num] + GPIOAFSEL_OFFSET),Pin_num);
		}

		else
		{
/*
Analog mode (Alternative pin functions)
*/
		}
	}

}

void systickinit(void)
{
	NVIC_ST_CTRL_R=0;								/*Disable the systick timer to re configure*/
	NVIC_ST_RELOAD_R=16000000-1; 		/*this is the relaod value for the counter*/
	NVIC_ST_CURRENT_R=0;     				/*this step is to claer the current value of the timer and also clearig the timer flag*/
	NVIC_ST_CTRL_R=7;               /*this value is to enable the system timer tick also enable the timer interrupt */
}
	



/**********************************************************************************************************************
 *  END OF FILE: port.c
 *********************************************************************************************************************/
