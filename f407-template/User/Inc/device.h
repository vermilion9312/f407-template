/*
 * device.h
 *
 *  Created on: Jun 30, 2025
 *      Author: vermilion9312
 */

#ifndef INC_DEVICE_H_
#define INC_DEVICE_H_

#include "output.h"

typedef struct _Device Device;

struct _Device {
	Output base;
	GPIO_Config gpio_config;
	bool state;
};

Output* new_Device(GPIO_TypeDef* GPIOx, uint16_t GPIO_Pin);

#endif /* INC_DEVICE_H_ */
