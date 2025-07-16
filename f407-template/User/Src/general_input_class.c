/*
 * general_input_class.c
 *
 *  Created on: Jul 13, 2025
 *      Author: vermi
 */


#include <general_input_class.h>

static void update(IInput* input)
{
	CGeneralInput* this = (CGeneralInput*) input;

	this->last_state = this->state;

	if (this->input_type == NOMAL_OPEN)
	{
		this->state = !HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin);
		return;
	}

	if (this->input_type == NOMAL_CLOSE)
	{
		this->state = HAL_GPIO_ReadPin(this->GPIOx, this->GPIO_Pin);
	}
}

static bool is_detected(IInput* input)
{
	CGeneralInput* this = (CGeneralInput*) input;

	return this->state;
}

static bool is_rising_edge(IInput* input)
{
	CGeneralInput* this = (CGeneralInput*) input;

	return (!this->last_state && this->state);
}

static bool is_falling_edge(IInput* input)
{
	CGeneralInput* this = (CGeneralInput*) input;

	return (this->last_state && !this->state);
}

IInput* new_GeneralInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, InputType input_type)
{
	CGeneralInput* this = malloc(sizeof(CGeneralInput));

	this->input_base.update          = update;
	this->input_base.is_detected     = is_detected;
	this->input_base.is_pressed      = is_detected;
	this->input_base.is_rising_edge  = is_rising_edge;
	this->input_base.is_falling_edge = is_falling_edge;

	this->GPIOx      = GPIOx;
	this->GPIO_Pin   = GPIO_Pin;
	this->input_type = input_type;

	this->last_state = false;
	this->state      = false;

	return (IInput*) this;
}
