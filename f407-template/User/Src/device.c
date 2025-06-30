/*
 * device.c
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */


#include "device.h"

static void turn_dvice_on(Output* output)
{
	Device* this = (Device*) output;
	HAL_GPIO_WritePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin, GPIO_PIN_RESET);
	this->state = true;
}

static void turn_dvice_off(Output* output)
{
	Device* this = (Device*) output;
	HAL_GPIO_WritePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin, GPIO_PIN_SET);
	this->state = false;
}

Output* new_Device(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	Device* this = malloc(sizeof(Device));
	if (!this) return NULL;

	this->base.turn_on         = turn_dvice_on;
	this->base.turn_off        = turn_dvice_off;
	this->gpio_config.GPIOx    = GPIOx;
	this->gpio_config.GPIO_Pin = GPIO_Pin;
	this->state                = false;

	return (Output*) this;
}
