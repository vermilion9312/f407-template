/*
 * uart_idle_interrupt_class.h
 *
 *  Created on: Jul 5, 2025
 *      Author: vermilion9312
 */

#ifndef UART_INC_UART_IDLE_INTERRUPT_CLASS_H_
#define UART_INC_UART_IDLE_INTERRUPT_CLASS_H_

#include <uart_interface.h>

#define RX_BUFFER_SIZE 256

typedef struct _CUartIdleInterrupt CUartIdleInterrupt;

struct _CUartIdleInterrupt {
	IUart base;
	UART_HandleTypeDef* huart;

	uint8_t rx_buffer[RX_BUFFER_SIZE];
	volatile bool rx_ready;
	size_t rx_received_length;

	volatile bool tx_done;


};

IUart* new_UartIdleInterrupt(UART_HandleTypeDef* huart, void (* on_receive_callback)(uint8_t* data, size_t len));

#endif /* UART_INC_UART_IDLE_INTERRUPT_CLASS_H_ */
