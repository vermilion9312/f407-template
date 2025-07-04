/*
 * class_general_output.h
 *
 *  Created on: Jul 4, 2025
 *      Author: vermilion9312
 */

#ifndef OUTPUT_INC_CLASS_GENERAL_OUTPUT_H_
#define OUTPUT_INC_CLASS_GENERAL_OUTPUT_H_

#include "interface_output.h"

typedef struct _CGeneralOutput CGeneralOutput;

struct _CGeneralOutput {
	IOutput base;
	GPIO_Config gpio_config;
	bool state;
};

IOutput* new_GeneralOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* OUTPUT_INC_CLASS_GENERAL_OUTPUT_H_ */
