/*
 * general_input_class.h
 *
 *  Created on: Jul 13, 2025
 *      Author: vermi
 */

#ifndef INC_GENERAL_INPUT_CLASS_H_
#define INC_GENERAL_INPUT_CLASS_H_

#include <input_interface.h>
#include <event_listener_interface.h>

typedef enum {
	NOMAL_OPEN,
	NOMAL_CLOSE
} InputType;

typedef struct _CGeneralInput CGeneralInput;

struct _CGeneralInput {
	IInput         input_base;
	GPIO_TypeDef*  GPIOx;
	uint16_t       GPIO_Pin;
	InputType      input_type;
	bool           last_state;
	bool           state;
};

IInput* new_GeneralInput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, InputType input_type);

#endif /* INC_GENERAL_INPUT_CLASS_H_ */
