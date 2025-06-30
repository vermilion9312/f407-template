/*
 * output.h
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */

#ifndef INC_OUTPUT_H_
#define INC_OUTPUT_H_

#include "gpio_config.h"

typedef struct _Output Output;

struct _Output {
	void (* turn_on)(Output*);
	void (* turn_off)(Output*);
};

#endif /* INC_OUTPUT_H_ */
