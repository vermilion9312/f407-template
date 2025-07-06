/*
 * uart_idle_interrupt.c
 *
 *  Created on: Jul 5, 2025
 *      Author: vermi
 */


#include <uart_idle_interrupt_class.h>

static void receive(IUart* uart, uint8_t* buffer, size_t size)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->rx_buffer = buffer;
	this->rx_buffer_size = size;
	this->rx_ready = false;

	HAL_UARTEx_ReceiveToIdle_IT(this->huart, this->rx_buffer, this->rx_buffer_size);
}

static void transmit(IUart* uart, const uint8_t* data, size_t len)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->tx_buffer = data;
	this->tx_length = len;
	this->tx_done = false;

	HAL_UART_Transmit_IT(this->huart, this->tx_buffer, this->tx_length);
}

IUart* new_UartIdleInterrupt(UART_HandleTypeDef* huart)
{
//	CUartIdleInterrupt* this = malloc(sizeof(CUartIdleInterrupt));
//
//	this->base.receive = receive;
//	this->base.transmit = transmit;
//
//	this->huart = huart;
//	this->
//
//	return this;
}
