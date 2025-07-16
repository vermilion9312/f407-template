/*
 * output_interface.h
 *
 *  Created on: Jul 16, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_OUTPUT_INTERFACE_H_
#define INC_OUTPUT_INTERFACE_H_

#include <common_include.h>

typedef enum {
	ACTIVE_LOW,
	ACTIVE_HIGH
} OutputType;

typedef struct _IOutput IOutput;

struct _IOutput {
	void (* turn_on)(IOutput*);
	void (* turn_off)(IOutput*);
	void (* toggle)(IOutput*);
};

#endif /* INC_OUTPUT_INTERFACE_H_ */
