/**********************************************************************************************************************
 *  FILE DESCRIPTION
 *  -----------------------------------------------------------------------------------------------------------------*/
/**        \file  DIO.c
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
#include "tm4c123gh6pm.h"

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
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level)
{
	uint8 portnumber, bitnumber;
	portnumber = ChannelId / 8;/*as per Dio_ChannelType A->0 B->1-----F->5 from deviding the number by 8 */
	bitnumber = ChannelId % 8; /*as per Dio_ChannelType the rest of devision by 8 will result in Bit number required (ISA)*/
	uint32 Bit_address=PORT_APB_BASE_ADDRESS[portnumber]+GPIODATA_OFFSET+(constant_shift_value);
	if(Level==1)
	{
		/*if the level required is one then we will set the bit in an atomic instructuion using bit_banding method 
		  in order to protect the shared prefiral from being shared in this time*/
		set_bit_BAND_PREF_D(Bit_address,bitnumber);
	}
	else if(Level==0)
	{
				/*if the level required is one then we will clear the bit in an atomic instructuion using bit_banding method 
		  in order to protect the shared prefiral from being shared in this time*/
		clear_bit_BAND_PREF_D(Bit_address,bitnumber);
	}
	else
	{
		/*User error
	   we could use assert.h here as a softdebugging method*/
	}
	 
}

Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId)
{

	Dio_LevelType level;
	uint8 portnumber, bitnumber;
	portnumber = ChannelId / 8;
	bitnumber = ChannelId % 8;
	uint32 Bit_address = PORT_APB_BASE_ADDRESS[portnumber] + GPIODATA_OFFSET +(constant_shift_value);
	level = READ_BIT(Bit_address,bitnumber);
	return level;
}

/******************************************************************************
* \Syntax          : void DIO_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/


/**********************************************************************************************************************
 *  END OF FILE: DIO.c
 *********************************************************************************************************************/
