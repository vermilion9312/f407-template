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
	void (* transmit)(IUart*, const uint8_t*, size_t);
	bool (* is_received)(IUart*);
	void (* set_rx_ready)(IUart*, bool);
	void (* set_tx_done)(IUart*, bool);
	void (* set_rx_received_length)(IUart*, size_t);

	void (* on_receive_callback)(uint8_t* data, size_t len);
};

#endif /* UART_INC_UART_INTERFACE_H_ */
