/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  port.h
 *       Module:  port
 *
 *  Description:  header file for port Module    
 *  
 *********************************************************************************************************************/
#ifndef port_H
#define port_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"
#include "Platform_Types.h"
#include "Mcu_Hw.h"
#include "Atomic_Opp.h"
#include "DIO.h"
#include "tm4c123gh6pm.h"


/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define Magic_value 0x4C4F434B /*the magic value required to open the lock register page(684) why this value spesicly? ask? session*/
#define Digital (0)            /*used to choose the PINs_Mode*/

/**********************************************************************************************************************
 *  GLOBAL FUNCTION MACROS
 *********************************************************************************************************************/


/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef Dio_ChannelType Port_PinType;
/*Port_PinType is used to get the Port&bit required to loop on*/
typedef enum
{
	PORT_PIN_IN,
	PORT_PIN_OUT,
	Sum_PIN
} Port_PinDirectionType;
/*Port_PinDirectionType is used to decide the pin direction 0 | 1*/
typedef uint8 Port_PinModeType;
/*used to choose between DIO mode and Analog Mode*/

typedef enum
{
	DEFAULT,
	PULLUP,
	PULLDOWN,
	OPENDRAIN,
	Sum_Attach
} Port_PinInternalAttachType;
/*used to identify the internal resistor attachment*/
typedef struct
{
	Port_PinType Pin;
	Port_PinDirectionType Dir;
	Port_PinModeType Mode;
	Port_PinInternalAttachType Attach;
	
} Port_ConfigType;
/*new sructure to fill each item of the the above typedefs */
/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 
/**********************************************************************************************************************
 *  GLOBAL FUNCTION PROTOTYPES
 *********************************************************************************************************************/
 void Port_Init(const Port_ConfigType *ConfigPtr);

/******************************************************************************
* \Syntax          : void port_Init(void)                                      
* \Description     : initialize Nvic\SCB Module by parsing the Configuration 
*                    into Nvic\SCB registers                                    
*                                                                             
* \Sync\Async      : Synchronous                                               
* \Reentrancy      : Non Reentrant                                             
* \Parameters (in) : None                     
* \Parameters (out): None                                                      
* \Return value:   : None
*******************************************************************************/ 



void systickinit(void);

#endif  /* port_H */

/**********************************************************************************************************************
 *  END OF FILE: port.h
 *********************************************************************************************************************/
