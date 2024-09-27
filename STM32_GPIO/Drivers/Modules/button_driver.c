/*
 * button_driver.c
 *
 *  Created on: Sep 27, 2024
 *      Author: lenovo
 */

#include "stm32f0xx_hal.h"


void button_driver_init()
{
	RCC->AHBENR |= (1<<18);

	GPIOB->MODER &= ~(1<<9);
	GPIOB->MODER &= ~(1<<8);

	GPIOB->PUPDR &= ~(1<<9);
	GPIOB->PUPDR &= ~(1<<8);
}
int button_driver_get_state()
{
	if(!(GPIOB->IDR & (1<<4)))
	{
		return 1;		//Burada return 1'in ne anlama geldiğini anlamamız gerekiyor. STM32'ye bağlı
	}					//butona pull-up direnci bağlanmıştır.Yani bu butonun boşta lojik 1 basılı
	else				//durumda lojik 0 olduğu anlamına gelir.Bundan dolayı butonun basılı olduğunu
	{					//anlamak için if deyimi içerisinde ilgili register'ın 0 olup olmadığı kontrol
		return 0;		//edilmiştir. Kısaca return 1 butonun basılı olduğu anlamına gelir.
	}
}
