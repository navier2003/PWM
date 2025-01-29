/*
 *        file : pwm.c
 *
 *  Created on : Jan 29, 2025
 *      Author : Navier
 *      Brief  : PWM signal generation using ARM Cortex M4
 */


#include "stm32f401xc.h"
#include "clockConfig.h"

void pwm_Init(void)
{
	// Initialize the system clock
	sysClock();

	// Enable the clock in Timer 2
	RCC -> APB1ENR |= RCC_APB1ENR_TIM2EN;


	// Enable the clock for GPIO port A
	RCC -> AHB1ENR |= RCC_AHB1ENR_GPIOAEN;

	// Set PA0 as alternate function
	GPIOA -> MODER |= (0x2UL << 0);
	GPIOA -> MODER |= (0x2UL << 2);
	GPIOA -> MODER |= (0x2UL << 4);
	GPIOA -> MODER |= (0x2UL << 6);


	// Set the pin PA0 as TIM2 Channel 1
	GPIOA -> AFR[0] |= (0x1 << 0);
	GPIOA -> AFR[0] &= ~(0x1 << 1);
	GPIOA -> AFR[0] &= ~(0x1 << 2);
	GPIOA -> AFR[0] &= ~(0x1 << 3);
}

void pwm_Config(void)
{
	/*
	 * Timer2 Channel1
	 * Duty Cycle : 50%
	 * Frequency :  10 KHz
	 To configure the timer in this mode:
     1. Configure the output pin:
        a) Select the output mode by writing CCS bits in CCMRx register.
        b) Select the polarity by writing the CCxP bit in CCER register.
     2. Select the PWM mode (PWM1 or PWM2) by writing OCxM bits in CCMRx register.
     3. Program the period and the duty cycle respectively in ARR and CCRx registers.
     4. Set the preload bit in CCMRx register and the ARPE bit in the CR1 register.
     5. Select the counting mode:
        a) PWM edge-aligned mode: the counter must be configured up-counting or
           down-counting
        b) PWM center aligned mode: the counter mode must be center aligned counting
           mode (CMS bits different from '00').
     6. Enable the capture compare.
     7. Enable the counter
	 * */

     TIM2 -> CCMR1 &= ~(0x3 << 0);

     TIM2 -> CCER &= ~(0x1 << 1);

     TIM2 -> CCMR1 |= (0x6 << 4);


     TIM2 -> PSC = 84-1;
     TIM2 -> ARR = 100-1;
     TIM2 -> CCR1 = 50;


     TIM2 -> CCMR1 |= (0x1 << 3);


     TIM2 -> CR1 |= (0x1 << 7);


     TIM2 -> CR1 &= ~(0x3 << 5);


     TIM2 -> CR1 &= ~(0x1 << 4);


     TIM2 -> CCER |= (0x1 << 0);


     TIM2 -> CR1 |= (0x1 << 0);
}
