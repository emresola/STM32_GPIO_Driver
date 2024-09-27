/*
 * led_driver.c
 *
 *  Created on: Sep 27, 2024
 *      Author: lenovo
 */
#include "stm32f0xx_hal.h"


void led_driver_init(void)
{
	// LED ==> GPIOA PIN8

	// Clock Enable
	RCC->AHBENR |= (1<<17);			//Clock source of A port enabled

	// Mode Select
	GPIOA->MODER |= (1<<16);		//bit 16 = 1
	GPIOA->MODER &= ~(1<<17);		//bit 17 = 0

	// Output Type Select
	GPIOA->OTYPER &= ~(1<<8);		//bit 8 = 0 output type:push-pull

	// Speed Select
	GPIOA->OSPEEDR &= ~(1<<17);		//bit 17 = 0
	GPIOA->OSPEEDR |= (1<<16);		//bit 16 = 1

	// Pull-up pull-down select
	GPIOA->PUPDR &= ~(1<<17);		//bit 17 = 0 No pull-up, no pull-down
	GPIOA->PUPDR &= ~(1<<16);		//bit 16 = 0 No pull-up, no pull-down
}

void led_driver_toggle()
{
	GPIOA->ODR ^= (1<<8);		// XOR operation with ODR bit 8
}

void led_driver_on(void)
{
	GPIOA->BSRR = (1<<8);		//bit 8 = 1
}
void led_driver_off(void)
{
	GPIOA->BRR = (1<<8);		//bit 8 = 1
}

