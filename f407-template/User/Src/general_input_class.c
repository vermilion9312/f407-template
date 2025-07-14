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
		return;
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

	return (!this->last_state && this->state) ? true : false;
}

static
