/*
 * input_listener_class.h
 *
 *  Created on: Jul 16, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_INPUT_LISTENER_CLASS_H_
#define INC_INPUT_LISTENER_CLASS_H_

#include <event_listener_interface.h>
#include <input_interface.h>

#define MAX_EVENT_BINDINGS 5

typedef struct _EventBinding EventBinding;

struct _EventBinding {
	EventType     event_type;
	EventCallback event_callback;
	void*         context;
};

typedef struct _CInputListener CInputListener;

struct _CInputListener {
	IEventListener base;
	EventBinding   event_bindings[MAX_EVENT_BINDINGS];
	uint8_t        binding_count;

	IInput*        input;
};

IEventListener* new_InputListener(IInput* input);

#endif /* INC_INPUT_LISTENER_CLASS_H_ */
