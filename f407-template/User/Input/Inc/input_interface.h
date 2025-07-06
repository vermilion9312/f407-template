/*
 * input_interface.h
 *
 *  Created on: Jul 4, 2025
 *      Author: vermilion9312
 */

#ifndef INPUT_INC_INPUT_INTERFACE_H_
#define INPUT_INC_INPUT_INTERFACE_H_

#include "gpio_config.h"

typedef struct _IInput IInput;

struct _IInput {
	void (* update)(IInput*);
	void (* on_detecting)(IInput*);
	void (* on_pressing)(IInput*);
	void (* on_rising_edge)(IInput*);
	void (* on_falling_edge)(IInput*);
};

#endif /* INPUT_INC_INPUT_INTERFACE_H_ */
