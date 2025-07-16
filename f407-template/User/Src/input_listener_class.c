/*
 * input_listener_class.c
 *
 *  Created on: Jul 16, 2025
 *      Author: LeeJooHo
 */


#include <input_listener_class.h>

static void add_event_listener(IEventListener* event_listener, EventType event_type, EventCallback event_callback, void* context)
{
	CInputListener* this = (CInputListener*) event_listener;

	if (this->binding_count >= MAX_EVENT_BINDINGS) return;

	this->event_bindings[this->binding_count++] = (EventBinding) { event_type, event_callback, context };
}

static void check_event(IEventListener* event_listener)
{
	CInputListener* this = (CInputListener*) event_listener;

	for (size_t i = 0; i < this->binding_count; i++)
	{
		EventBinding* event = &this->event_bindings[i];

		switch (event->event_type)
		{
		case PRESS:
			if (this->input->is_pressed(this->input))
			{
				event->event_callback(event->context);
			}
			break;
		case RISING_EDGE:
			if (this->input->is_rising_edge(this->input))
			{
				event->event_callback(event->context);
			}
			break;
		case FALLING_EDGE:
			if (this->input->is_falling_edge(this->input))
			{
				event->event_callback(event->context);
			}
			break;
		default:
			break;
		}
	}
}

IEventListener* new_InputListener(IInput* input)
{
	CInputListener* this = calloc(1, sizeof(CInputListener));

	this->base.add_event_listener = add_event_listener;
	this->base.check_event        = check_event;

	this->binding_count = 0;
	this->input         = input;

	return (IEventListener*) this;
}
