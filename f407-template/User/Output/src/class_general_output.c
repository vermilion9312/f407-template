/*
 * class_general_output.c
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */


#include "class_general_output.h"

static void turn_general_output_on(IOutput* output)
{
	CGeneralOutput* this = (CGeneralOutput*) output;
	HAL_GPIO_WritePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin, GPIO_PIN_RESET);
	this->state = true;
}

static void turn_general_output_off(IOutput* output)
{
	CGeneralOutput* this = (CGeneralOutput*) output;
	HAL_GPIO_WritePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin, GPIO_PIN_SET);
	this->state = false;
}

static void toggle_general_output(IOutput* output)
{
	CGeneralOutput* this = (CGeneralOutput*) output;
	HAL_GPIO_TogglePin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
	this->state ^= 1;
}

IOutput* new_GeneralOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin)
{
	CGeneralOutput* this = malloc(sizeof(CGeneralOutput));
	if (!this) return NULL;

	this->base.turn_on         = turn_general_output_on;
	this->base.turn_off        = turn_general_output_off;
	this->base.toggle          = toggle_general_output;
	this->gpio_config.GPIOx    = GPIOx;
	this->gpio_config.GPIO_Pin = GPIO_Pin;
	this->state                = false;

	return (IOutput*) this;
}
