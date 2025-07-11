/*
 * general_input_class.c
 *
 *  Created on: Jul 4, 2025
 *      Author: vermilion9312
 */


#include <general_input_class.h>

static void add_event_listener(IEventListener* listener, EventType type, EventCallback callback, IOutput* output)
{
	CGeneralInput* this = (CGeneralInput*) listener;


}

static void on_event(IEventListener* listener)
{

}

static void update_gerneral_input(IInput* input)
{
	CGeneralInput* this = (CGeneralInput*) input;

	this->last_state = this->state;

	if (this->input_type == NOMAL_OPEN)
	{
		this->state = !HAL_GPIO_ReadPin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
		return;
	}

	if (this->input_type == NOMAL_CLOSE)
	{
		this->state = HAL_GPIO_ReadPin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
	}
}

static void on_gerneral_input_detecting(IInput* input)
{
	CGeneralInput* this = (CGeneralInput*) input;
	this->state ? this->output->turn_on(this->output) : this->output->turn_off(this->output);
}

static void on_general_input_rising_edge(IInput* input)
{
	CGeneralInput*  this   = (CGeneralInput*) input;
	CGeneralOutput* output = (CGeneralOutput*) this->output;

	if (!this->last_state && this->state)
	{
		output->state ? this->output->turn_off(this->output) : this->output->turn_on(this->output);
	}
}

static void on_general_input_falling_edge(IInput* input)
{
	CGeneralInput*  this   = (CGeneralInput*) input;
	CGeneralOutput* output = (CGeneralOutput*) this->output;

	if (this->last_state && !this->state)
	{
		output->state ? this->output->turn_off(this->output) : this->output->turn_on(this->output);
	}
}

IInput* new_GeneralInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, InputType input_type, IOutput* output)
{
	CGeneralInput* this = malloc(sizeof(CGeneralInput));
	if (!this) return NULL;

	this->output               = output;
	this->gpio_config.GPIOx    = GPIOx;
	this->gpio_config.GPIO_Pin = GPIO_Pin;
	this->input_type           = input_type;
	this->last_state           = false;
	this->state                = false;

	this->base.update          = update_gerneral_input;
	this->base.on_detecting    = on_gerneral_input_detecting;
	this->base.on_pressing     = on_gerneral_input_detecting;
	this->base.on_rising_edge  = on_general_input_rising_edge;
	this->base.on_falling_edge = on_general_input_falling_edge;

	return (IInput*) this;
}
