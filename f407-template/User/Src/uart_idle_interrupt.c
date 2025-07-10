/*
 * uart_idle_interrupt.c
 *
 *  Created on: Jul 5, 2025
 *      Author: vermi
 */


#include <uart_idle_interrupt_class.h>

static void receive(IUart* uart)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->rx_ready = false;

	HAL_UARTEx_ReceiveToIdle_IT(this->huart, this->rx_buffer, RX_BUFFER_SIZE);
}

static void transmit(IUart* uart, const uint8_t* data, size_t len)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->tx_done = false;

	HAL_UART_Transmit_IT(this->huart, data, len);
}

static bool is_received(IUart* uart)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	return  this->rx_ready;
}

static void set_rx_ready(IUart* uart, bool rx_ready)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->rx_ready = rx_ready;
}

static void set_tx_done(IUart* uart, bool tx_done)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->tx_done = tx_done;
}

static void set_rx_received_length(IUart* uart, size_t length)
{
	CUartIdleInterrupt* this = (CUartIdleInterrupt*) uart;

	this->rx_received_length = length;
}

IUart* new_UartIdleInterrupt(UART_HandleTypeDef* huart, void (* on_receive_callback)(uint8_t* data, size_t len))
{
	CUartIdleInterrupt* this = malloc(sizeof(CUartIdleInterrupt));

	this->base.receive                = receive;
	this->base.transmit               = transmit;
	this->base.is_received            = is_received;
	this->base.set_rx_ready           = set_rx_ready;
	this->base.set_tx_done            = set_tx_done;
	this->base.set_rx_received_length = set_rx_received_length;

	this->huart    = huart;
	this->rx_ready = false;
	this->tx_done  = false;

	this->rx_received_length  = 0;
	this->base.on_receive_callback = on_receive_callback;

	memset(this->rx_buffer, 0, RX_BUFFER_SIZE);

	return (IUart*) this;
}
