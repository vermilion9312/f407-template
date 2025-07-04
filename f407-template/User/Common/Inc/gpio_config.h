/*
 * gpio_config.h
 *
 *  Created on: May 19, 2025
 *      Author: vermilion9312
 */

#ifndef INC_GPIO_CONFIG_H_
#define INC_GPIO_CONFIG_H_

#include <stdbool.h>
#include <stdlib.h>
#include <stdint.h>
#include "stm32f4xx_hal.h"

typedef struct _GPIO_Config GPIO_Config;

struct _GPIO_Config {
	GPIO_TypeDef* GPIOx;
	uint16_t      GPIO_Pin;
};

#endif /* INC_GPIO_CONFIG_H_ */
