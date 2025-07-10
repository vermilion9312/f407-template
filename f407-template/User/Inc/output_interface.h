/*
 * output_interface.h
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */

#ifndef OUTPUT_INC_OUTPUT_INTERFACE_H_
#define OUTPUT_INC_OUTPUT_INTERFACE_H_

#include "gpio_config.h"

typedef struct _IOutput IOutput;

struct _IOutput {
	void (* turn_on)(IOutput*);
	void (* turn_off)(IOutput*);
	void (* toggle)(IOutput*);
};

#endif /* OUTPUT_INC_OUTPUT_INTERFACE_H_ */
