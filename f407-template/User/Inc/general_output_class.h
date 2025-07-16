/*
 * general_output_class.h
 *
 *  Created on: Jul 16, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_GENERAL_OUTPUT_CLASS_H_
#define INC_GENERAL_OUTPUT_CLASS_H_

#include <output_interface.h>
#include <event_listener_interface.h>

typedef struct _CGeneralOutput CGeneralOutput;

struct _CGeneralOutput {
	IOutput       base;
	GPIO_TypeDef* GPIOx;
	uint16_t      GPIO_Pin;
	OutputType    output_type;
	bool          state;
};

IOutput* new_GeneralOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin, OutputType output_type);

#endif /* INC_GENERAL_OUTPUT_CLASS_H_ */
