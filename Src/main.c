/**
 ******************************************************************************
 * @file           : main.c
 * @author         : Navier
 * @brief          : Main program body
 * Date : Jan 29,2025
 ******************************************************************************
 * @attention
 *
 * Copyright (c) 2025 STMicroelectronics.
 * All rights reserved.
 *
 * This software is licensed under terms that can be found in the LICENSE file
 * in the root directory of this software component.
 * If no LICENSE file comes with this software, it is provided AS-IS.
 *
 ******************************************************************************
 */

#include <stdint.h>
#include "stm32f401xc.h"
#include "clockConfig.h"
#include "pwm.h"



int main(void)
{
	// Initialize the PWM
	pwm_Init();
	// Configure the pwm_Config
	pwm_Config();

	while(1)
	{

	}
}
