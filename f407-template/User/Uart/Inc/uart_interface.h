/*
 * uart_interface.h
 *
 *  Created on: Jul 5, 2025
 *      Author: vermilion9312
 */

#ifndef UART_INC_UART_INTERFACE_H_
#define UART_INC_UART_INTERFACE_H_

#include <common_include.h>

typedef struct _IUart IUart;

struct _IUart {
	void (* receive)(IUart*);
	void (* transmit)(IUart*);
};

#endif /* UART_INC_UART_INTERFACE_H_ */
