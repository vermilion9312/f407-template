/*
 * event_listener_interface.h
 *
 *  Created on: Jul 16, 2025
 *      Author: LeeJooHo
 */

#ifndef INC_EVENT_LISTENER_INTERFACE_H_
#define INC_EVENT_LISTENER_INTERFACE_H_

#include <common_include.h>

typedef enum {
	PRESS,
	RISING_EDGE,
	FALLING_EDGE
} EventType;

typedef void (* EventCallback)(void*);

typedef struct _IEventListener IEventListener;

struct _IEventListener {
	void (* add_event_listener)(IEventListener*, EventType, EventCallback, void*);
	void (* check_event)(IEventListener*);
};

#endif /* INC_EVENT_LISTENER_INTERFACE_H_ */
