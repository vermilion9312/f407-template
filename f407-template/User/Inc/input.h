/*
 * input.h
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */

#ifndef INC_INPUT_H_
#define INC_INPUT_H_

#include "device.h"

typedef enum { NOMAL_OPEN, NOMAL_CLOSE } InputType;

typedef struct _Input Input;

struct _Input {
	Output* device;
	GPIO_Config gpio_config;
	bool last_state;
	bool state;

	void (* update)(Input*, InputType);
	void (* is_pressed)(Input*);
	void (* on_rising_edge)(Input*);
	void (* on_falling_edge)(Input*);
};

Input* new_Input(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, Output* device);

#endif /* INC_INPUT_H_ */
