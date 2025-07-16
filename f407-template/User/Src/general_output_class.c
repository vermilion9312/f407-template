/*
 * general_output_class.h
 *
 *  Created on: Jul 16, 2025
 *      Author: LeeJooHo
 */


#include <general_output_class.h>

static void turn_on(IOutput* output)
{
	CGeneralOutput* this = (CGeneralOutput*) output;

	if (this->output_type == ACTIVE_LOW)
	{
		HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_RESET);
		this->state = true;
		return;
	}

	if (this->output_type == ACTIVE_HIGH)
	{
		HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_SET);
		this->state = true;
	}
}

static void turn_off(IOutput* output)
{
	CGeneralOutput* this = (CGeneralOutput*) output;

	if (this->output_type == ACTIVE_LOW)
	{
		HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_SET);
		this->state = false;
		return;
	}

	if (this->output_type == ACTIVE_HIGH)
	{
		HAL_GPIO_WritePin(this->GPIOx, this->GPIO_Pin, GPIO_PIN_RESET);
		this->state = false;
	}
}

static void toggle(IOutput* output)
{
	CGeneralOutput* this = (CGeneralOutput*) output;

	HAL_GPIO_TogglePin(this->GPIOx, this->GPIO_Pin);
	this->state = !this->state;
}

IOutput* new_GeneralOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, OutputType output_type)
{
	CGeneralOutput* this = malloc(sizeof(CGeneralOutput));

	this->base.turn_on  = turn_on;
	this->base.turn_off = turn_off;
	this->base.toggle   = toggle;

	this->GPIOx       = GPIOx;
	this->GPIO_Pin    = GPIO_Pin;
	this->output_type = output_type;

	this->state = false;

	return (IOutput*) this;
}
