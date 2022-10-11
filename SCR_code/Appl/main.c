
#include "Std_Types.h"
#include "tm4c123gh6pm.h"
#include "DIO.h"
#include "Port.h"
#include "timer.h"




int main(void)
{
	
	sys_timer_init(16000000);
	 
Port_ConfigType pin_one,*ptr_pin_one;
	
pin_one.Pin=Dio_Channel_F1;
	
pin_one.Dir=PORT_PIN_OUT;
	
pin_one.Attach=PULLUP;
	
pin_one.Mode=Digital;
	
ptr_pin_one=&pin_one;
	
Port_Init(ptr_pin_one);
	
	systickinit();
 	while(1)
	{
		
	}
	
	
	return 0;
}










/*
void init(void)
{
	//this ine will set the bit 5 in SYSCTL_GPIOHBCTL_R inorder to chose the AHB bus for portF 
	SYSCTL_GPIOHBCTL_R =0;
	//this ine will set the bit 5 in SYSCTL_RCGCGPIO_R in order to provide a clock on portF 
	SYSCTL_RCGCGPIO_R  |=0x20;
	//this ine will write the magic value shown below in order to lock the bits for read and write in portf 
	GPIO_PORTF_LOCK_R =0x4C4F434B;
	//this ine will set GPIO_PORTF_CR_R all the first 7 bits to allow the read and write in them 
	GPIO_PORTF_CR_R =0x1F;
	//this ine will set pin 1 & pin 2 & pin3 in GPIO_PORTF_DIR_R in order to make them an output(leds) an pin 0 & 4 will be input (switches)
	GPIO_PORTF_DIR_R |=0x0E;
	//this ine will be cleared in order to use the pins with the normal GPIO not alternative function 
	GPIO_PORTF_AFSEL_R=0;
	//this ine will be cleared in order to use the pins with the normal GPIO not alternative function 
	GPIO_PORTF_PCTL_R=0;
	//this ine will set pins 0 and 4 to be intalnally pulled up 
	GPIO_PORTF_PUR_R |=0x11;
	//this ine will set the first 5 bits in portf to be used as a digital input and outpt
	GPIO_PORTF_DEN_R |=0x1f;
	GPIO_PORTF_AMSEL_R=0;
	
}
*/

