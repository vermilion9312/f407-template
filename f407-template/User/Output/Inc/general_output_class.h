/*
 * general_output_class.h
 *
 *  Created on: Jul 4, 2025
 *      Author: vermilion9312
 */

#ifndef OUTPUT_INC_GENERAL_OUTPUT_CLASS_H_
#define OUTPUT_INC_GENERAL_OUTPUT_CLASS_H_

#include <output_interface.h>

typedef struct _CGeneralOutput CGeneralOutput;

struct _CGeneralOutput {
	IOutput base;
	GPIO_Config gpio_config;
	bool state;
};

IOutput* new_GeneralOutput(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* OUTPUT_INC_GENERAL_OUTPUT_CLASS_H_ */
