/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  DIO.h
 *       Module:  DIO
 *
 *  Description:  header file for DIO Module    
 *  
 *********************************************************************************************************************/
#ifndef DIO_H
#define DIO_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Mcu_Hw.h"

/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
 #define constant_shift_value 0X3FC


/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
static const uint32 PORT_APB_BASE_ADDRESS[6]=
{
GPIO_PORTA_APB_BASE_ADDRESS,
GPIO_PORTB_APB_BASE_ADDRESS,
GPIO_PORTC_APB_BASE_ADDRESS,
GPIO_PORTD_APB_BASE_ADDRESS,
GPIO_PORTE_APB_BASE_ADDRESS,
GPIO_PORTF_APB_BASE_ADDRESS
};

 /*the below sruct is used to call the channel */
 typedef enum
{

	Dio_Channel_A0,
	Dio_Channel_A1,
	Dio_Channel_A2,
	Dio_Channel_A3,
	Dio_Channel_A4,
	Dio_Channel_A5,
	Dio_Channel_A6,
	Dio_Channel_A7,

	Dio_Channel_B0,
	Dio_Channel_B1,
	Dio_Channel_B2,
	Dio_Channel_B3,
	Dio_Channel_B4,
	Dio_Channel_B5,
	Dio_Channel_B6,
	Dio_Channel_B7,

	Dio_Channel_C0,
	Dio_Channel_C1,
	Dio_Channel_C2,
	Dio_Channel_C3,
	Dio_Channel_C4,
	Dio_Channel_C5,
	Dio_Channel_C6,
	Dio_Channel_C7,

	Dio_Channel_D0,
	Dio_Channel_D1,
	Dio_Channel_D2,
	Dio_Channel_D3,
	Dio_Channel_D4,
	Dio_Channel_D5,
	Dio_Channel_D6,
	Dio_Channel_D7,

	Dio_Channel_E0,
	Dio_Channel_E1,
	Dio_Channel_E2,
	Dio_Channel_E3,
	Dio_Channel_E4,
	Dio_Channel_E5,
	Dio_Channel_E6_unusable,
	Dio_Channel_E7_unusable,

	Dio_Channel_F0,
	Dio_Channel_F1,
	Dio_Channel_F2,
	Dio_Channel_F3,
	Dio_Channel_F4,
	Dio_Channel_F5_unusable,
	Dio_Channel_F6_unusable,
	Dio_Channel_F7_unusable

} Dio_ChannelType;

/*the struct is used refering to the port number*/
typedef enum
{

	PORTA,
	PORTB,
	PORTC,
	PORTD,
	PORTE,/*2 restricted Bits*/
	PORTF /*3 restricted Bits*/
	
} Dio_PortType;

/*from the Std_Types header file : generating a data boolen type for level minapulation */
typedef STD_levelType Dio_LevelType;


/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
void Dio_WriteChannel(Dio_ChannelType ChannelId, Dio_LevelType Level);
Dio_LevelType Dio_ReadChannel(Dio_ChannelType ChannelId);

#endif  /* DIO_H */

/**********************************************************************************************************************
 *  END OF FILE: DIO.h
 *********************************************************************************************************************/
