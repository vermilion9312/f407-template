/*
 * class_general_input.h
 *
 *  Created on: Jul 4, 2025
 *      Author: vermilion9312
 */

#ifndef INPUT_INC_CLASS_GENERAL_INPUT_H_
#define INPUT_INC_CLASS_GENERAL_INPUT_H_

#include "interface_input.h"
#include "class_general_output.h"

typedef enum { NOMAL_OPEN, NOMAL_CLOSE } InputType;

typedef struct _CGeneralInput CGeneralInput;

struct _CGeneralInput {
	IInput base;
	IOutput* output;
	GPIO_Config gpio_config;
	InputType input_type;
	bool last_state;
	bool state;
};

IInput* new_GeneralInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, InputType input_type, IOutput* output);

#endif /* INPUT_INC_CLASS_GENERAL_INPUT_H_ */
