/**********************************************************************************************************************

 *  FILE DESCRIPTION
 *  -------------------------------------------------------------------------------------------------------------------
 *         File:  Mcu_Hw.h
 *       Module:  Mcu_Hw
 *
 *  Description:  header file for Registers definition    
 *  
 *********************************************************************************************************************/
#ifndef MCU_HW_H
#define MCU_HW_H

/**********************************************************************************************************************
 * INCLUDES
 *********************************************************************************************************************/
#include "Std_Types.h"

/**********************************************************************************************************************
 *  GLOBAL DATA TYPES AND STRUCTURES
 *********************************************************************************************************************/
typedef struct 
{
    uint32 VECACT   :8;
    uint32          :3;
    uint32 RETBASE  :1;
    uint32 VECPEND  :3;
    uint32 VECPEND2  :4;
    uint32          :2;
    uint32 ISRPEND  :1;
    uint32 ISRPRE   :1;
    uint32          :1;
    uint32 PENDSTCLR:1;
    uint32 PENDSTSET:1;
    uint32 UNPENDSV :1;
    uint32 PENDSV   :1;
    uint32          :2;
    uint32 NMISET   :1; 
}INTCTRL_BF;
typedef union 
{
    uint32 R;
    INTCTRL_BF B;
}INTCTRL_Tag;



/**********************************************************************************************************************
 *  GLOBAL CONSTANT MACROS
 *********************************************************************************************************************/
#define CORTEXM4_PERI_BASE_ADDRESS             0xE000E000
#define APINT                                  *((volatile uint32*)(CORTEXM4_PERI_BASE_ADDRESS+0xD0C))
#define INTCTRL                                *((volatile INTCTRL_Tag*)(CORTEXM4_PERI_BASE_ADDRESS+0xD04))
#define SET_BIT(ADDRESS,Bit_num)      (ADDRESS|= (1<<Bit_num))
#define CLEAR_BIT(ADDRESS,Bit_num)    (ADDRESS&= ~(1<<Bit_num))
#define TOGGLE_BIT(ADDRESS,Bit_num)   (ADDRESS^= (1<<Bit_num))
#define READ_BIT(ADDRESS,Bit_num)     ((ADDRESS>>Bit_num) & 1)
	
/*the below defines are used to define each Port in the APB bus*/
#define GPIO_PORTA_APB_BASE_ADDRESS 0x40004000
#define GPIO_PORTB_APB_BASE_ADDRESS 0x40005000
#define GPIO_PORTC_APB_BASE_ADDRESS 0x40006000
#define GPIO_PORTD_APB_BASE_ADDRESS 0x40007000
#define GPIO_PORTE_APB_BASE_ADDRESS 0x40024000
#define GPIO_PORTF_APB_BASE_ADDRESS 0x40025000

/*the below defines are used to define each Port in the AHB bus*/

#define GPIO_PORTA_AHB_BASE_ADDRESS 0x40058000
#define GPIO_PORTB_AHB_BASE_ADDRESS 0x40059000
#define GPIO_PORTC_AHB_BASE_ADDRESS 0x4005A000
#define GPIO_PORTD_AHB_BASE_ADDRESS 0x4005B000
#define GPIO_PORTE_AHB_BASE_ADDRESS 0x4005C000
#define GPIO_PORTF_AHB_BASE_ADDRESS 0x4005D000

/*the below defines are used to define each offest on the port addreses to reach the required register addreses*/
#define GPIOLOCK_OFFSET 0x520
#define GPIOCR_OFFSET 0x524
#define GPIODIR_OFFSET 0x400
#define GPIOPUR_OFFSET 0x510
#define GPIOPDR_OFFSET 0x514
#define GPIOODR_OFFSET 0x50C
#define GPIODR2R_OFFSET 0x500
#define GPIODR4R_OFFSET 0x504
#define GPIODR8R_OFFSET 0x508
#define GPIODEN_OFFSET 0x51C
#define GPIOAFSEL_OFFSET 0x420
#define GPIOPCTL_OFFSET 0x52C
#define GPIODATA_OFFSET 0x000

/*the below define will be used to navigate throgh the system timer registers*/

#define SYSTEM_TIMER_BASE 0xE000E000
#define SCTRL_OFFSET 0x010
#define STRELOAD_OFFSET 0x014
#define STCURRENT_OFFSET 0x018

/**********************************************************************************************************************
 *  GLOBAL DATA PROTOTYPES
 *********************************************************************************************************************/

 

 
#endif  /* MCU_HW_H */

/**********************************************************************************************************************
 *  END OF FILE: Mcu_Hw.h
 *********************************************************************************************************************/
