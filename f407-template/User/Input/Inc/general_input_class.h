/*
 * general_input_class.h
 *
 *  Created on: Jul 4, 2025
 *      Author: vermilion9312
 */

#ifndef INPUT_INC_GENERAL_INPUT_CLASS_H_
#define INPUT_INC_GENERAL_INPUT_CLASS_H_

#include <general_output_class.h>
#include <input_interface.h>

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

#endif /* INPUT_INC_GENERAL_INPUT_CLASS_H_ */
