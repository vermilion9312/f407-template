/*
 * input.c
 *
 *  Created on: Jun 30, 2025
 *      Author: LeeJooHo
 */


#include "input.h"

static void update(Input* this, InputType input_type)
{
	this->last_state = this->state;

	if (input_type == NOMAL_OPEN)
	{
		this->state = !HAL_GPIO_ReadPin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
		return;
	}

	if (input_type == NOMAL_CLOSE)
	{
		this->state = HAL_GPIO_ReadPin(this->gpio_config.GPIOx, this->gpio_config.GPIO_Pin);
	}
}

static void is_pressed(Input* this)
{
	this->state ? this->device->turn_on(this->device) : this->device->turn_off(this->device);
}

static void on_rising_edge(Input* this)
{
	Device* device = (Device*) this->device;

	if (!this->last_state && this->state)
	{
		device->state ? this->device->turn_off(this->device) : this->device->turn_on(this->device);
	}
}

static void on_falling_edge(Input* this)
{
	Device* device = (Device*) this->device;

	if (this->last_state && !this->state)
	{
		device->state ? this->device->turn_off(this->device) : this->device->turn_on(this->device);
	}
}

Input* new_Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, Output* device)
{
	Input* this = malloc(sizeof(Input));
	if (!this) return NULL;

	this->device               = device;
	this->gpio_config.GPIOx    = GPIOx;
	this->gpio_config.GPIO_Pin = GPIO_Pin;
	this->last_state           = false;
	this->state                = false;

	this->update          = update;
	this->is_pressed      = is_pressed;
	this->on_rising_edge  = on_rising_edge;
	this->on_falling_edge = on_falling_edge;

	return this;
}






