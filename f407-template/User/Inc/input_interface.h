/*
 * input_interface.h
 *
 *  Created on: Jul 13, 2025
 *      Author: vermi
 */

#ifndef INC_INPUT_INTERFACE_H_
#define INC_INPUT_INTERFACE_H_

#include <common_include.h>

typedef struct _IInput IInput;

struct _IInput {
	void (* update)(IInput*);
	bool (* is_pressed)(IInput*);
	bool (* is_detected)(IInput*);
	bool (* is_rising_edge)(IInput*);
	bool (* is_falling_edge)(IInput*);
};

#endif /* INC_INPUT_INTERFACE_H_ */
