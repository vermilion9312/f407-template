/*
 * interface_output.h
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */

#ifndef OUTPUT_INC_INTERFACE_OUTPUT_H_
#define OUTPUT_INC_INTERFACE_OUTPUT_H_

#include "gpio_config.h"

typedef struct _IOutput IOutput;

struct _IOutput {
	void (* turn_on)(IOutput*);
	void (* turn_off)(IOutput*);
	void (* toggle)(IOutput*);
};

#endif /* OUTPUT_INC_INTERFACE_OUTPUT_H_ */
